#include "../AP_H/GUI.h"
#include "../AP_H/ap_lcd.h"
#include "../USER_H/lcd.h"
#include "../mcc_generated_files/mcc.h"
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
void Welcome(void)
{
    display_char(1,2,6,"�ɷۿ���ϵͳ");
    display_char(1,11,4,"������  ");
    display_char(2,9,4,"�汾V0.1");
    Mute
    __delay_ms(300);
    Umute
    __delay_ms(300);
    
}
void RunGui(void)
{
    NO1_OK
    NO2_OK
    NO3_OK
    NO4_OK
    
    __delay_ms(300);
    position(2, 1);
    sendCom(0x34);
    sendCom(0x07);
    sendCom(0x30);
    //Un_White
    __delay_ms(300);

}
void staus(char number,char staus)
{
    switch(staus)
    {
        case 0:
        {
            
        }break;
        case 1:
        {
        
        }break;
        case 2:
        {
        
        }break;
        case 3:
        {
        
        }break;
        default:break;
    }
}