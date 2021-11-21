/* 
 * File:   sensors.h
 * Author: ilya_000
 *
 * Created on November 15, 2021, 10:05 PM
 */

#ifndef SENSORS_H
#define	SENSORS_H

#include "mcc_generated_files/pin_manager.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define getSensor1Alarm() ((SENSOR1_PORT^sensor1_inv)&sensor1_en)
#define getSensor2Alarm() ((SENSOR2_PORT^sensor2_inv)&sensor2_en)
    
extern uint8_t sensor1_inv, sensor2_inv, sensor1_en, sensor2_en, sensor1_trg, sensor2_trg, sensor1_intr, sensor2_intr;

void SensorsInit(void);
void Sensor1(void);
void Sensor2(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SENSORS_H */

