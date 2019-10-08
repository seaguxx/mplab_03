/* 
 * File:   led.h
 * Author: H
 *
 * Created on September 19, 2019, 4:58 PM
 */
#include "../mcc_generated_files/mcc.h"
#ifndef LED_H
#define	LED_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LED_H */
#define YH Yled_SetHigh();
#define BH Bled_SetHigh();
#define GH Gled_SetHigh();
#define BuzzH Buzz_SetHigh();

#define YL Yled_SetLow();
#define BL Bled_SetLow();
#define GL Gled_SetLow();
#define BuzzL Buzz_SetLow();

extern void ledtest() ;
extern void ledoff();