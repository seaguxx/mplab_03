/**
  TMR0 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr0.c

  @Summary
    This is the generated driver implementation file for the TMR0 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for TMR0.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F25K83
        Driver Version    :  3.10
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20
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

/**
  Section: Included Files
 */

#include <xc.h>
#include "tmr0.h"
#include "pin_manager.h"
#include "../USER_H/key.h"
#include "../AP_H/GUI.h"
#include "../USER_H/CanBus.h"
#define MuteKeyDownTime 200 //200*10
#define ShootKeyDownTime 300
#define Tmr0_3s 300
#define Tmr0_half_1s 50
#define Tmr0_1s 100
char Tmr0_Run_Fla = 0;
char Tmr0_1s_Fla = 0;
char Tmr0_3s_Fla = 0;
char Can_1s_Send_Fla = 0;
unsigned int Tmr0_1s_Cnt = 0;
unsigned int Tmr0_3s_Cnt = 0;
/**
  Section: TMR0 APIs
 */

void (*TMR0_InterruptHandler)(void);

void TMR0_Initialize(void) {
    // Set TMR0 to the options selected in the User Interface

    // T0CS HFINTOSC; T0CKPS 1:64; T0ASYNC synchronised; 
    T0CON1 = 0x66;

    // TMR0H 77; 
    TMR0H = 0x4D;

    // TMR0L 0; 
    TMR0L = 0x00;

    // Clear Interrupt flag before enabling the interrupt
    PIR3bits.TMR0IF = 0;

    // Enabling TMR0 interrupt.
    PIE3bits.TMR0IE = 1;

    // Set Default Interrupt Handler
    TMR0_SetInterruptHandler(TMR0_DefaultInterruptHandler);

    // T0OUTPS 1:4; T0EN enabled; T016BIT 8-bit; 
    T0CON0 = 0x83;
}

void TMR0_StartTimer(void) {
    // Start the Timer by writing to TMR0ON bit
    if (Tmr0_Run_Fla == 0) {
        Tmr0_Run_Fla = 1;
        T0CON0bits.T0EN = 1;
        PIE3bits.TMR0IE = 1;
    } else {

    }

}

void TMR0_StopTimer(void) {
    // Stop the Timer by writing to TMR0ON bit
    if (Tmr0_Run_Fla == 1) {
        Tmr0_Run_Fla = 0;
        T0CON0bits.T0EN = 0;
    } else {

    }

}

uint8_t TMR0_ReadTimer(void) {
    uint8_t readVal;

    // read Timer0, low register only
    readVal = TMR0L;

    return readVal;
}

void TMR0_WriteTimer(uint8_t timerVal) {
    // Write to Timer0 registers, low register only
    TMR0L = timerVal;
}

void TMR0_Reload(uint8_t periodVal) {
    // Write to Timer0 registers, high register only
    TMR0H = periodVal;
}

void TMR0_ISR(void)//10ms
{
    // clear the TMR0 interrupt flag
    PIR3bits.TMR0IF = 0;
    Tmr0_1s_Cnt++;
    Tmr0_3s_Cnt++;
    if (Tmr0_3s_Cnt >= Tmr0_3s) {
        Tmr0_3s_Cnt = 0;
        Tmr0_3s_Fla = 1;
    }
    if (Tmr0_1s_Cnt == Tmr0_half_1s) {
        //Yled_Toggle();

    } 
    else if ((Tmr0_1s_Cnt > Tmr0_half_1s)&&(Tmr0_1s_Cnt < Tmr0_1s)) {
        //Yled_SetLow();

    } 
    else if (Tmr0_1s_Cnt == Tmr0_1s) {
        Yled_Toggle();
        Tmr0_1s_Fla = 1;
        Tmr0_1s_Cnt = 0;
    } 
    else 
    {
    }
    if (Tmr0_1s_Fla == 1) {
        Tmr0_1s_Fla = 0;

        MessageTform(&Message_Send_Test, 2, 0x00411122, 8, 0xee, 0x01, 0x02, 0x03, 0x04, 0x05, 0x07, 0XEE);
        CAN_transmit_TXB1(&Message_Send_Test);

        Can_1s_Send_Fla = 1;
    }


    if (Key1_Fla == 1) {
        Fuction_Mute();

       

        Key1_Fla = 0;
    }
    if (Key2_Fla == 1) {
        //TMR0_StopTimer();
        Function_Shoot();
        //TMR0_StartTimer();
        Key2_Fla = 0;
    }
    if (RB0_GetValue() == 0) {
        Key1_Cnt++;
        if (Key1_Cnt >= MuteKeyDownTime) {
            
            Key1_Fla = 1;
            Key1_Cnt = 0;
        } else {

        }
    } else {
        Key1_Cnt = 0;
        Key1_Fla = 0;
        //TMR0_StopTimer();
    }
    if (RB1_GetValue() == 0) {
        Key2_Cnt++;
        if (Key2_Cnt >= ShootKeyDownTime) {
            Key2_Fla = 1;
            Key2_Cnt = 0;
        } else {

        }
    } else {
        Key2_Fla = 0;
        Key2_Cnt = 0;
        //TMR0_StopTimer();
    }
    if (TMR0_InterruptHandler) {
        TMR0_InterruptHandler();
    }

    // add your TMR0 interrupt custom code
}

void TMR0_SetInterruptHandler(void (* InterruptHandler)(void)) {
    TMR0_InterruptHandler = InterruptHandler;
}

void TMR0_DefaultInterruptHandler(void) {
    // add your TMR0 interrupt custom code
    // or set custom function using TMR0_SetInterruptHandler()
}

/**
  End of File
 */