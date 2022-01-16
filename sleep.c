#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "sw_timer.h"
#include "lorawan_init.h"
#include "sensors.h"
#include "interrupt_manager_lora_addons.h"
#include "tmr_lora_addons.h"
#include "shell.h"
#include "lorawan_types.h"
#include "lorawan.h"
#include "lorawan_ru.h"
#include "sensors.h"
#include "measurements.h"
#include "radio_driver_SX1276.h"


static volatile uint32_t rest, counter, counter0;
static uint8_t ncol, ncoh, ncou, nco;
extern volatile uint8_t sensor_event;
//extern volatile SwTimer_t swTimers[MAX_TIMERS];
//extern volatile uint8_t allocatedTimers;
//uint32_t runningTimers;
//extern ChannelParams_t Channels[MAX_RU_SINGLE_BAND_CHANNELS];
//static uint16_t timerVal;
extern uint8_t radioBuffer[];
uint8_t t_nreset;
extern char b[128];

static void compute_nco(uint32_t dt)
{
    counter0=(dt*1000)/4329559; // кол-во полных циклов nco1
    uint64_t div=(dt*1000)-(counter0*4329559); // кол-во ms в неполном цикле nco1
    if(div==0) counter0--; // коррекция полных циклов nco1 если div==0
    rest=1048576-(div*24219)/100000; // максимальное кол-во циклов в nco1(2^20=1024x1024) минус кол-во циклов CLKR(LFINTOSC/128) в оставшихся милисекундах
    ncou = (rest&0x00FF0000)>>16;
    ncoh = (rest&0x0000FF00)>>8;
    ncol = (rest&0x000000FF);
    nco=0;
    /*send_chars("nco dt=");
    send_chars(ui32toa(dt,b));
    send_chars(", counter=");
    send_chars(ui32toa(counter,b));
    send_chars(", rest=");
    send_chars(ui32toa(rest,b));
    send_chars(", ncou=");
    send_chars(ui8tox(ncou,b));
    send_chars(", ncoh=");
    send_chars(ui8tox(ncoh,b));
    send_chars(", ncol=");
    send_chars(ui8tox(ncol,b));
    send_chars("\r\n");*/
}

void handleNCOInterrupt() {
    if( counter == 0 )
    {
        nco=1;
    } 
    else 
    {
        counter--;
    } 
}

static void startNCO(uint32_t interval)
{
    compute_nco(interval);
    counter=counter0;
    NCO1MD=1;
    NCO1MD=0;
    NCO1CON = 0x00;
    NCO1CLK = 0x06;
    NCO1ACCU = ncou;
    NCO1ACCH = ncoh;
    NCO1ACCL = ncol;
    NCO1INCU = 0x00;
    NCO1INCH = 0x00;
    NCO1INCL = 0x01;
    nco=0;
    PIR4bits.NCO1IF = 0;
    PIE4bits.NCO1IE = 1;
    NCO1CONbits.EN = 1;
}

static void stopNCO(void)
{
    NCO1CONbits.EN = 1;
    NCO1MD=1;
}

static void SX1276_Reset(void)
{
    IOCCPbits.IOCCP5 = 0;
    SwTimerSetTimeout(t_nreset,MS_TO_TICKS(5));
    NRESET_SetLow();
//    SystemBlockingWaitMs(10);
    SwTimerStart(t_nreset);
    while(SwTimerIsRunning(t_nreset)) SwTimersExecute();
    NRESET_SetHigh();
    SwTimerSetTimeout(t_nreset,MS_TO_TICKS(5));
    SwTimerStart(t_nreset);
    while(SwTimerIsRunning(t_nreset)) SwTimersExecute();
    
    RADIO_Init(&radioBuffer[16], RU864_CALIBRATION_FREQ);

//    SystemBlockingWaitMs(10);
 }

void periph_permanent_off(void)
{
    CRCMD=1; // CRC Engine
    SCANMD=1; // NVM Memory Scanner

    TMR6MD=1; // Timer TMR6
    TMR5MD=1; // Timer TMR5
    TMR4MD=1; // Timer TMR4
    TMR2MD=1; // Timer TMR2
    TMR0MD=1; // Timer TMR0
    
    DACMD=1; // DAC
    CMP2MD=1; // Comparator CMP2
    CMP1MD=1; // Comparator CMP1
    ZCDMD=1; // Zero-Cross Detect module
    
    PWM8MD=1; // Pulse-Width Modulator PWM8
    PWM7MD=1; // Pulse-Width Modulator PWM7
    PWM6MD=1; // Pulse-Width Modulator PWM6
    PWM5MD=1; // Pulse-Width Modulator PWM5
    CCP4MD=1; // Capture/Compare/PWM CCP4
    CCP3MD=1; // Capture/Compare/PWM CCP3
    CCP2MD=1; // Capture/Compare/PWM CCP2
    CCP1MD=1; // Capture/Compare/PWM CCP1
    
    CWG3MD=1; // CWG3 Module
    CWG2MD=1; // CWG2 Module
    CWG1MD=1; // CWG1 Module
    
    U2MD=1; // UART2
    I2C2MD=1; // I2C2 Module
    I2C1MD=1; // I2C1 Module
    
    SMT1MD=1; // SMT1 Module
    CLC4MD=1; // CLC4 Module
    CLC3MD=1; // CLC3 Module
    CLC2MD=1; // CLC2 Module
    CLC1MD=1; // CLC1 Module
    DSMMD=1; // Data Signal Modulator
    
    DMA2MD=1; // DMA2 Module
    DMA1MD=1; // DMA1 Module
    
}

void periph_permanent_on(void)
{
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    NRESET_SetHigh();
    CLKRMD=0; // Clock Reference
    CLKREF_Initialize();
    IOCMD=0; // Interrupt-on-Change
    INTERRUPT_Initialize();
    EXT_INT_Initialize();
    SensorsInit();
    TMR1MD=0; // Timer TMR1
    TMR1_Initialize();
    SystemTimerInit();
    TMR_ISR_Lora_Init();
    t_nreset=SwTimerCreate();
    stopNCO();
}


static void periph_off(void)
{
/*    runningTimers=0;
    uint32_t ptr=1;
    for(uint8_t k=0;k<allocatedTimers;k++)
    {
        if(swTimers[k].running!=0) runningTimers|=ptr;
        ptr<<=1;
    }
    printVar("allocatedTimers=",PAR_UI8,&allocatedTimers,false,true);
    printVar("runningTimers=",PAR_UI32,&runningTimers,true,true);*/

    NRESET_SetLow();
    sensor_event=0;
    SYSCMD=1; //Peripheral System Clock
    FVRMD=1; //Fixed VoltageReference
    HLVDMD=1; // High/Low-Voltage Detect
    NVMMD=1; // NVM Module

    TMR3MD=1; // Timer TMR3
    TMR1_StopTimer();
//    TMR1MD=1; // Timer TMR1
    
    ADCMD=1; // ADCC
    U1MD=1; // UART1
    SPI1MD=1; // SPI1 Module

    //Device enters Sleep mode on SLEEP instruction
    IDLEN = 0;
    // Configure as output all unused port pins and set them to low
    //PORT A,B
    TRISAbits.TRISA0 = OUTPUT;
    TRISAbits.TRISA1 = OUTPUT;
    TRISAbits.TRISA4 = OUTPUT;
    TRISAbits.TRISA5 = OUTPUT;
    TRISBbits.TRISB6 = OUTPUT;
    TRISBbits.TRISB7 = OUTPUT;
    LATAbits.LATA0 = LOW;
    LATAbits.LATA1 = LOW;
    LATAbits.LATA4 = LOW;
    LATAbits.LATA5 = LOW;
    LATBbits.LATB6 = LOW;
    LATBbits.LATB7 = LOW;
    
    
    
}

static void periph_on(uint32_t interval)
{
    SYSCMD=0; //Peripheral System Clock
    U1MD=0; // UART1
    UART1_Initialize();
    FVRMD=0; //Fixed VoltageReference
    FVR_Initialize();
    HLVDMD=0; // High/Low-Voltage Detect
    HLVD_Initialize();
    NVMMD=0; // NVM Module
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();

    TMR3MD=0; // Timer TMR3
    TMR3_Initialize();
    ticksNCO=interval*32768;
    ticksToScheduledInterrupt = SwTimersInterrupt();
    TMR1_StartTimer();
//    send_chars("TMR1 Start\r\n");
    /*    for(uint8_t k=0;k<allocatedTimers;k++)
    {
        if(swTimers[k].running!=0)
        {
            if(swTimers[k].ticksRemaining<interval*32768) swTimers[k].ticksRemaining=0;
            else swTimers[k].ticksRemaining-=interval*32768;
        }
    }*/
    /*for(uint8_t k=0;k<MAX_RU_SINGLE_BAND_CHANNELS;k++)
    {
        if(Channels[k].channelTimer<interval*1000) Channels[k].channelTimer=0;
        else Channels[k].channelTimer-=interval*1000;
    }*/
    loRa.lastTimerValue+=interval*1000;
//    send_chars("Timers corrected\r\n");
    
    ADCMD=0; // ADCC
    ADCC_Initialize();
    getTableValues();
    SPI1MD=0; // SPI1 Module
    SPI1_Initialize();
    SPI1_Open(SPI1_DEFAULT);
    LORAWAN_PlatformInit();
    SX1276_Reset();
}

void my_sleep(uint32_t interval)
{
    uint8_t a;
    if(LORAWAN_GetState() != IDLE) return;
    send_chars("Entering sleep ");
    send_chars(ui32toa(interval,b));
    send_chars("s.\r\n");
    periph_off();
    startNCO(interval);
    while(1)
    {
        SLEEP();
        NOP();
        NOP();
        if(sensor_event || nco)
        {
            periph_on(interval);
            send_chars("Returning from sleep\r\n");
            return;
        }
    }
}

void init_system(void)
{
    periph_permanent_off();
    periph_permanent_on();
    periph_on(0);
}

