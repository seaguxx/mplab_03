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
#define NO1_OK display_char(2,1,4,"һ������");
#define NO2_OK display_char(2,5,4,"��������");
#define NO3_OK display_char(1,9,4,"��������");
#define NO4_OK display_char(1,13,4,"�ĺ�����");

#define NO1_Fault display_char(2,1,4,"һ�Ź���");
#define NO2_Fault display_char(2,5,4,"���Ź���");
#define NO3_Fault display_char(1,9,4,"���Ź���");
#define NO4_Fault display_char(1,13,4,"�ĺŹ���");

#define NO1_TNT display_char(2,1,4,"һ���ͷ�");
#define NO2_TNT display_char(2,5,4,"�����ͷ�");
#define NO3_TNT display_char(1,9,4,"�����ͷ�");
#define NO4_TNT display_char(1,13,4,"�ĺ��ͷ�");

#define Un_White display_char(1,13,4,"        ");

#define Mute    display_char(2,15,2,"����");
#define Umute   display_char(2,15,2,"    ");
extern void Welcome(void);
extern void RunGui(void);
