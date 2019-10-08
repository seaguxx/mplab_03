/* 
 * File:   lcd.h
 * Author: H
 *
 * Created on September 19, 2019, 5:16 PM
 */
#include "../mcc_generated_files/mcc.h"

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

extern void lcdport(void);
extern void LCDInit(void);
extern void Spi8b(unsigned char dat);
extern void position(char x, char y);
extern void LcdString(unsigned char *p);
extern void sendDat(unsigned char dat);
extern void sendCom(unsigned char com);