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
