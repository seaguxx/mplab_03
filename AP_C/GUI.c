#include "../AP_H/GUI.h"
#include "../AP_H/ap_lcd.h"
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
void Welcome(void)
{
    display_char(2,9,4,"�������");
    display_char(1,1,4,"�汾v0.1");
    
    NO1_OK
    NO2_OK
    NO3_OK
    NO4_OK
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