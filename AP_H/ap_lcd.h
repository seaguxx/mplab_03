/* 
 * File:   ap_lcd.h
 * Author: H
 *
 * Created on September 23, 2019, 9:15 AM
 */

#ifndef AP_LCD_H
#define	AP_LCD_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* AP_LCD_H */
extern void display_12864(int y, int x, char  *p);
extern void display_1632(int y, int x, char  *p);
extern void display_3232(int y, int x, char  *p);
extern void display_char(int y, int x, int char_length, unsigned char *p);
extern void LCD_Draw_Two_Dot(unsigned char StartX,unsigned char StartY,unsigned char EndX,unsigned char EndY,unsigned char Color);
extern void LCD_DrawSineWave(void);
extern void LCD_DrawCoseWave(void);
extern void GRam_Clear(void);
