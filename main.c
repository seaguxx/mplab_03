/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F25K83
        Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include "mcc_generated_files/mcc.h"
#include "USER_H/led.h"
#include"USER_H/lcd.h"
#include"AP_H/ap_lcd.h"
#include "AP_H/GUI.h"
#include "USER_H/key.h"
#include "USER_H/CanBus.h"
#include "mcc_generated_files/ecan.h"
#define Equ_ID_01 0x18ff7080
#define Equ_ID_02 0x18ff7081
#define Equ_ID_03 0x18ff7082
#define Equ_ID_04 0x18ff7083
#define Equ_Num 4
#define Equ_Status_OffLine 0x99
#define Equ_Status_Fault 0x77
#define Equ_Status_Ok 0x00
#define Equ_Status_TNT 0X88
unsigned char Equ_DATA_Current_HeartBeat_08[Equ_Num]={0X00,0X00,0X00,0X00};
unsigned char Equ_DATA_Update_HeartBeat_08[Equ_Num]={0X00,0X00,0X00,0X00};
unsigned char Equ_DATA_Status_07[Equ_Num]={0X00,0X00,0X00,0X00};
char Equ_OnLine_Fla=0x00;
char LoopCnt=0;
/*
                         Main application
 */
void main(void) {
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    Key_Init();
    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    LCDInit();

    CanHardWareInit();

    Welcome();

    while (1) {
                if(Can_Receive_Fla_01==1)
                {
                    Can_Receive_Fla_01=0;
                    switch(Message_Receive_02.frame.id)
                    {
                        case Equ_ID_01:
                        {
                            Equ_DATA_Current_HeartBeat_08[0]=Message_Receive_02.frame.data7;
                            Equ_DATA_Status_07[0]=Message_Receive_02.frame.data6;
                        }break;
                        case Equ_ID_02:
                        {
                            Equ_DATA_Current_HeartBeat_08[1]=Message_Receive_02.frame.data7;
                            Equ_DATA_Status_07[1]=Message_Receive_02.frame.data6;
                        }break;
                        case Equ_ID_03:
                        {
                            Equ_DATA_Current_HeartBeat_08[2]=Message_Receive_02.frame.data7;
                            Equ_DATA_Status_07[2]=Message_Receive_02.frame.data6;
                        }break;
                        case Equ_ID_04:
                        {
                            Equ_DATA_Current_HeartBeat_08[3]=Message_Receive_02.frame.data0;
                            Equ_DATA_Status_07[3]=Message_Receive_02.frame.data6;
                        }break;
                        default:
                        {
                            break;
                        }
                    }
                }
                for(LoopCnt=0;LoopCnt<Equ_Num;LoopCnt++)
                {
                    
                    if(Equ_DATA_Status_07[LoopCnt]==Equ_Status_Ok)
                    {
                        switch(LoopCnt)
                        {
                            case 0:
                            {
                                NO1_OK
                            }break;
                            case 1:
                            {
                                NO2_OK
                            }break;
                            case 2:
                            {
                                NO3_OK
                            }break;
                            case 3:
                            {
                                NO4_OK
                            }break;                           
                            default:
                            {
                                break;
                            }
                        }
                    }
                    else if(Equ_DATA_Status_07[LoopCnt]==Equ_Status_Fault)
                    {
                        switch(LoopCnt)
                        {
                            case 0:
                            {
                                NO1_Fault
                            }break;
                            case 1:
                            {
                                NO2_Fault
                            }break;
                            case 2:
                            {
                                NO3_Fault
                            }break;
                            case 3:
                            {
                                NO4_Fault
                            }break;                           
                            default:
                            {
                                break;
                            }
                        }                    
                    }
                    else if(Equ_DATA_Status_07[LoopCnt]==Equ_Status_OffLine)
                    {
                        switch(LoopCnt)
                        {
                            case 0:
                            {
                                NO1_OffLine
                            }break;
                            case 1:
                            {
                                NO2_OffLine
                            }break;
                            case 2:
                            {
                                NO3_OffLine
                            }break;
                            case 3:
                            {
                                NO4_OffLine
                            }break;                           
                            default:
                            {
                                break;
                            }
                        }                        
                    }
                    else if(Equ_DATA_Status_07[LoopCnt]==Equ_Status_TNT)
                    {
                        switch(LoopCnt)
                        {
                            case 0:
                            {
                                NO1_TNT
                            }break;
                            case 1:
                            {
                                NO2_TNT
                            }break;
                            case 2:
                            {
                                NO3_TNT
                            }break;
                            case 3:
                            {
                                NO4_TNT
                            }break;                           
                            default:
                            {
                                
                                break;
                            }
                        }
                    }
                    else
                    {
                        switch(LoopCnt)
                        {
                            case 0:
                            {
                                NO1_Code_Er
                            }break;
                            case 1:
                            {
                                NO2_Code_Er
                            }break;
                            case 2:
                            {
                                NO3_Code_Er
                            }break;
                            case 3:
                            {
                                NO4_Code_Er
                            }break;                           
                            default:
                            {
                                
                                break;
                            }
                        }
                    }
                    
                }
                

        //        MessageTform(&Message_Send, 2, 0x011123, 8, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, Message_Receive.frame.data0);
        //        CAN_transmit(&Message_Send);
        //        MessageTform(&Message_Send, 2, 0x00411123, 8, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0xff);
        //        CAN_transmit(&Message_Send);
        //Function_Shoot();
        if (Message_Receive_02.frame.data0 == 0x5a) {
            NO4_TNT
            Message_Receive_02.frame.data0 = 0x00;
        }
        if (Message_Receive_02.frame.data0 == 0x4a) {
            NO3_TNT
            Message_Receive_02.frame.data0 = 0x00;
            
        }


        if (Can_1s_Send_Fla == 1) {


            Can_1s_Send_Fla = 0;
            MessageTform(&Message_Send_Test, 2, 0x00411121, 8, 0xee, 0x01, 0x02, 0x03, 0x04, 0x05, 0x07, 0XEE);
            CAN_transmit_TXB0(&Message_Send_Test);
        }
        __delay_ms(1000);

        ledtest();
    }
}
/**
 End of File
 */