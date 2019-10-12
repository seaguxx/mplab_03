#include "../mcc_generated_files/mcc.h"
#include "../USER_H/key.h"
#include "../USER_H/lcd.h"
#include "../AP_H/ap_lcd.h"
#include "../AP_H/GUI.h"
#include "../USER_H/CanBus.h"
char Key_Shoot_Fla_01=0;
char Key1_Fla = 0;
char Key2_Fla = 0;
char Buzz_Disable = 0; //0 disable 1 enable
char Mute_Fla = 0; //0 Umute 1Mute
unsigned int Key1_Cnt = 0;
unsigned int Key2_Cnt = 0;

void Key_Init(void) {
    EXT_INT0_InterruptEnable();
    EXT_INT1_InterruptEnable();
}

void Key1_Fuction(void)//Mute--Umute
{
    //Fuction_Mute();
}

void Key2_Function(void)//shoot
{
    //CAN-Message
}

void Fuction_Mute(void) {


    if (Mute_Fla == 0) {
        Mute
        Buzz_Disable = 1;
        Mute_Fla = 1;
    } else {
        Umute
        Buzz_Disable = 0;
        Mute_Fla = 0;
    }
}

void Fuction_Buzz(char Disable_fla) {
    if (Disable_fla == 1) {
        Buzz_SetLow();
    } else {

    }
}

void Function_Shoot(void) {
    //message
    
    MessageTform(&Message_Send_Test, 2, 0x18FF708F, 8, 0xE6, 0x74, 0x33, 0x73, 0x73, 0xAA, 0xAA, 0XAA);
    
    CAN_transmit_TXB2(&Message_Send_Test);
    Key_Shoot_Fla_01=1;
    

}