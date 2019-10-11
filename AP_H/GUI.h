/* 
 * File:   GUI.h
 * Author: H
 *
 * Created on October 9, 2019, 12:59 PM
 */

#ifndef GUI_H
#define	GUI_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* GUI_H */
#define NO1_OK display_char(2,1,4,"一号正常");
#define NO2_OK display_char(2,5,4,"二号正常");
#define NO3_OK display_char(1,9,4,"三号正常");
#define NO4_OK display_char(1,13,4,"四号正常");

#define NO1_Fault display_char(2,1,4,"一号故障");
#define NO2_Fault display_char(2,5,4,"二号故障");
#define NO3_Fault display_char(1,9,4,"三号故障");
#define NO4_Fault display_char(1,13,4,"四号故障");

#define NO1_TNT display_char(2,1,4,"一号释放");
#define NO2_TNT display_char(2,5,4,"二号释放");
#define NO3_TNT display_char(1,9,4,"三号释放");
#define NO4_TNT display_char(1,13,4,"四号释放");

#define Un_White display_char(1,13,4,"        ");

#define Mute    display_char(2,15,2,"消音");
#define Umute   display_char(2,15,2,"    ");
extern void Welcome(void);
extern void RunGui(void);
