#include "../AP_H/GUI.h"
#include "../AP_H/ap_lcd.h"
#include "../USER_H/lcd.h"
#include "../mcc_generated_files/mcc.h"

void Welcome(void)
{
    display_char(1,2,6,"干粉控制系统");
    display_char(1,11,4,"中汽客  ");
    display_char(2,9,4,"版本V0.1");
//    Mute
//    __delay_ms(300);
//    Umute
//    __delay_ms(300);
    
}
void Docker(void)
{
    display_char(2, 9, 4, "    ");
    display_char(2,9,3,"状态：");
    display_char(2,12,1,"0");
    display_char(2,13,1,"丨");
    display_char(2,14,1,"4");

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