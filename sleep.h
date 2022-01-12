/* 
 * File:   sleep.h
 * Author: ilya
 *
 * Created on January 11, 2022, 6:47 PM
 */

#ifndef SLEEP_H
#define	SLEEP_H

#ifdef	__cplusplus
extern "C" {
#endif

void handleNCOInterrupt(void);
void periph_permanent_off(void);
void periph_permanent_on(void);
void my_sleep(uint32_t interval);
void init_system(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SLEEP_H */

