#include "../AP_H/GUI.h"
#include "../AP_H/ap_lcd.h"
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
void Welcome(void)
{
    display_char(2,9,4,"你好您好");
    display_char(1,1,4,"版本v0.1");
    
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