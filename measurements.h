/* 
 * File:   measurements.h
 * Author: ilya_000
 *
 * Created on September 20, 2021, 1:12 PM
 */

#ifndef MEASUREMENTS_H
#define	MEASUREMENTS_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef union
{
    uint16_t value;
    uint8_t bytes[2];
    struct {
        unsigned sensor1_mode:3;
        unsigned sensor2_mode:3;
        unsigned sensor1_cur :1;
        unsigned sensor2_cur :1;
        unsigned sensor1_evt :4;
        unsigned sensor2_evt :4;
    };
} Sensors_t;

typedef struct
{
//    uint32_t uid;
//    uint32_t num;
    uint16_t temperature;
    uint8_t batLevel;
    uint8_t rssi;
    int8_t snr;
    int8_t power;
    Sensors_t sensors;
} Data_t;
    
uint8_t getBatteryLevel(void);
void getTableValues(void);
int16_t getTemperature(void);


#ifdef	__cplusplus
}
#endif

#endif	/* MEASUREMENTS_H */

