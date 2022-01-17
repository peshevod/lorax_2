#include "mcc_generated_files/mcc.h"
#include "interrupt_manager_lora_addons.h"
#include <stdint.h>
#include "shell.h"
#include "sensors.h"
#include "measurements.h"
#include <xc.h>

uint8_t sensor1_inv, sensor2_inv, sensor1_en, sensor2_en, sensor1_trg, sensor2_trg;
volatile uint8_t sensor_event;
extern volatile uint8_t dioStatus;
//extern bool readAndSendFlag;
extern Data_t data;

void Sensor1_ISR(void)
{
    dioStatus|=SENSOR1;
    sensor_event=1;
    
}

void Sensor2_ISR(void)
{
    dioStatus|=SENSOR2;
    sensor_event=1;
}

void SensorsInit(void)
{
    uint8_t s1,s2;
    set_s("SENSOR1",&s1);
    set_s("SENSOR2",&s2);
    if(s1&0x01) sensor1_en=0x01;else sensor1_en=0;
    if(s2&0x01) sensor2_en=0x01;else sensor2_en=0;
    if(s1&0x02) sensor1_trg=0x01;else sensor1_trg=0;
    if(s2&0x02) sensor2_trg=0x01;else sensor2_trg=0;
    if(s1&0x04) sensor1_inv=0x01;else sensor1_inv=0;
    if(s2&0x04) sensor2_inv=0x01;else sensor1_inv=0;
    data.sensors.sensor1_mode=s1&0x07;
    data.sensors.sensor2_mode=s2&0x07;
    if(sensor1_en) IOCAF3_SetInterruptHandler(Sensor1_ISR); //Sensor1
    else
    {
        IOCANbits.IOCAN3 = 0;
        IOCAPbits.IOCAP3 = 0;
        IOCAFbits.IOCAF3 = 0;
    }//Sensor1
    if(sensor2_en) IOCAF2_SetInterruptHandler(Sensor2_ISR); //Sensor2
    else
    {
        IOCANbits.IOCAN2 = 0;
        IOCAPbits.IOCAP2 = 0;
        IOCAFbits.IOCAF2 = 0;
    }
    data.sensors.sensor1_evt=0;
    data.sensors.sensor2_evt=0;
}

void Sensor1(void)
{
    data.sensors.sensor1_cur=getSensor1Alarm();
    if(data.sensors.sensor1_evt<15) data.sensors.sensor1_evt++;
//    if(sensor1_trg) readAndSendFlag = true;
    send_chars("Sensor1 Alarm\n");
}

void Sensor2(void)
{
    data.sensors.sensor2_cur=getSensor2Alarm();
    if(data.sensors.sensor2_evt<15) data.sensors.sensor2_evt++;
//    if(sensor2_trg) readAndSendFlag = true;
    send_chars("Sensor2 Alarm\n");
}


