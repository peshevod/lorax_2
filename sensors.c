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
    data.sensors.sensor1_cur=SENSOR1_PORT^sensor1_inv;
    sensor_event=1;
    
}

void Sensor2_ISR(void)
{
    dioStatus|=SENSOR2;
    data.sensors.sensor2_cur=SENSOR2_PORT^sensor2_inv;
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
//    printVar("s1=",PAR_UI8,&s1,true,true);
    data.sensors.sensor2_mode=s2&0x07;
//    printVar("s2=",PAR_UI8,&s2,true,true);
    IOCAFbits.IOCAF3 = 0;
    if(sensor1_en)
    {
        IOCAF3_SetInterruptHandler(Sensor1_ISR);
        IOCANbits.IOCAN3 = 1;
        IOCAPbits.IOCAP3 = 1;
    }
    else
    {
        IOCANbits.IOCAN3 = 0;
        IOCAPbits.IOCAP3 = 0;
    }//Sensor1
    IOCAFbits.IOCAF2 = 0;
    if(sensor2_en)
    {
        IOCAF2_SetInterruptHandler(Sensor2_ISR);
        IOCANbits.IOCAN2 = 1;
        IOCAPbits.IOCAP2 = 1;
    }
    else
    {
        IOCANbits.IOCAN2 = 0;
        IOCAPbits.IOCAP2 = 0;
    }
    data.sensors.sensor1_evt=0;
    data.sensors.sensor2_evt=0;
    data.sensors.sensor1_cur=SENSOR1_PORT^sensor1_inv;
    data.sensors.sensor2_cur=SENSOR2_PORT^sensor2_inv;
}

void Sensor1(void)
{
    if(data.sensors.sensor1_evt<15) data.sensors.sensor1_evt++;
    printVar("Alarm Sensor1=",PAR_UI8,&data.sensors.bytes[0],true,true);
}

void Sensor2(void)
{
    if(data.sensors.sensor2_evt<15) data.sensors.sensor2_evt++;
    printVar("Alarm Sensor2=",PAR_UI8,&data.sensors.bytes[0],true,true);
}


