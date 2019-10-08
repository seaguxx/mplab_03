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

extern unsigned char Readspi(void);
extern unsigned char LCD_read_arm(void);
extern void Draw_point(unsigned char X,unsigned char Y,unsigned char Color);
extern void v_Lcd12864DrawLineX_f(unsigned char X0,unsigned char X1,unsigned char Y,unsigned char Color);
extern void v_Lcd12864DrawLineY_f(unsigned char X,unsigned char Y0,unsigned char Y1,unsigned char Color);