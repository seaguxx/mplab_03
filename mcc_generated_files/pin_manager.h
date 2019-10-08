/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F25K83
        Driver Version    :  2.11
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set Gled aliases
#define Gled_TRIS                 TRISAbits.TRISA0
#define Gled_LAT                  LATAbits.LATA0
#define Gled_PORT                 PORTAbits.RA0
#define Gled_WPU                  WPUAbits.WPUA0
#define Gled_OD                   ODCONAbits.ODCA0
#define Gled_ANS                  ANSELAbits.ANSELA0
#define Gled_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define Gled_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define Gled_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define Gled_GetValue()           PORTAbits.RA0
#define Gled_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define Gled_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define Gled_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define Gled_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define Gled_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define Gled_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define Gled_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define Gled_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set Bled aliases
#define Bled_TRIS                 TRISAbits.TRISA1
#define Bled_LAT                  LATAbits.LATA1
#define Bled_PORT                 PORTAbits.RA1
#define Bled_WPU                  WPUAbits.WPUA1
#define Bled_OD                   ODCONAbits.ODCA1
#define Bled_ANS                  ANSELAbits.ANSELA1
#define Bled_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define Bled_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define Bled_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define Bled_GetValue()           PORTAbits.RA1
#define Bled_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define Bled_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define Bled_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define Bled_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define Bled_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define Bled_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define Bled_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define Bled_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set Buzz aliases
#define Buzz_TRIS                 TRISAbits.TRISA2
#define Buzz_LAT                  LATAbits.LATA2
#define Buzz_PORT                 PORTAbits.RA2
#define Buzz_WPU                  WPUAbits.WPUA2
#define Buzz_OD                   ODCONAbits.ODCA2
#define Buzz_ANS                  ANSELAbits.ANSELA2
#define Buzz_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define Buzz_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define Buzz_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define Buzz_GetValue()           PORTAbits.RA2
#define Buzz_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define Buzz_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define Buzz_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define Buzz_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define Buzz_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define Buzz_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define Buzz_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define Buzz_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set AD1 aliases
#define AD1_TRIS                 TRISAbits.TRISA3
#define AD1_LAT                  LATAbits.LATA3
#define AD1_PORT                 PORTAbits.RA3
#define AD1_WPU                  WPUAbits.WPUA3
#define AD1_OD                   ODCONAbits.ODCA3
#define AD1_ANS                  ANSELAbits.ANSELA3
#define AD1_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define AD1_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define AD1_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define AD1_GetValue()           PORTAbits.RA3
#define AD1_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define AD1_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define AD1_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define AD1_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define AD1_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define AD1_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define AD1_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define AD1_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set MhdDet aliases
#define MhdDet_TRIS                 TRISAbits.TRISA4
#define MhdDet_LAT                  LATAbits.LATA4
#define MhdDet_PORT                 PORTAbits.RA4
#define MhdDet_WPU                  WPUAbits.WPUA4
#define MhdDet_OD                   ODCONAbits.ODCA4
#define MhdDet_ANS                  ANSELAbits.ANSELA4
#define MhdDet_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define MhdDet_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define MhdDet_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define MhdDet_GetValue()           PORTAbits.RA4
#define MhdDet_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define MhdDet_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define MhdDet_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define MhdDet_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define MhdDet_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define MhdDet_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define MhdDet_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define MhdDet_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set Cs aliases
#define Cs_TRIS                 TRISAbits.TRISA5
#define Cs_LAT                  LATAbits.LATA5
#define Cs_PORT                 PORTAbits.RA5
#define Cs_WPU                  WPUAbits.WPUA5
#define Cs_OD                   ODCONAbits.ODCA5
#define Cs_ANS                  ANSELAbits.ANSELA5
#define Cs_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define Cs_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define Cs_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define Cs_GetValue()           PORTAbits.RA5
#define Cs_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define Cs_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define Cs_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define Cs_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define Cs_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define Cs_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define Cs_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define Cs_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set AD2 aliases
#define AD2_TRIS                 TRISAbits.TRISA6
#define AD2_LAT                  LATAbits.LATA6
#define AD2_PORT                 PORTAbits.RA6
#define AD2_WPU                  WPUAbits.WPUA6
#define AD2_OD                   ODCONAbits.ODCA6
#define AD2_ANS                  ANSELAbits.ANSELA6
#define AD2_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define AD2_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define AD2_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define AD2_GetValue()           PORTAbits.RA6
#define AD2_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define AD2_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define AD2_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define AD2_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define AD2_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define AD2_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define AD2_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define AD2_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set AD3 aliases
#define AD3_TRIS                 TRISAbits.TRISA7
#define AD3_LAT                  LATAbits.LATA7
#define AD3_PORT                 PORTAbits.RA7
#define AD3_WPU                  WPUAbits.WPUA7
#define AD3_OD                   ODCONAbits.ODCA7
#define AD3_ANS                  ANSELAbits.ANSELA7
#define AD3_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define AD3_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define AD3_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define AD3_GetValue()           PORTAbits.RA7
#define AD3_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define AD3_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define AD3_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define AD3_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define AD3_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define AD3_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define AD3_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define AD3_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSELB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSELB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSELB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set Rst aliases
#define Rst_TRIS                 TRISBbits.TRISB5
#define Rst_LAT                  LATBbits.LATB5
#define Rst_PORT                 PORTBbits.RB5
#define Rst_WPU                  WPUBbits.WPUB5
#define Rst_OD                   ODCONBbits.ODCB5
#define Rst_ANS                  ANSELBbits.ANSELB5
#define Rst_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define Rst_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define Rst_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define Rst_GetValue()           PORTBbits.RB5
#define Rst_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define Rst_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define Rst_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define Rst_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define Rst_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define Rst_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define Rst_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define Rst_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set Stb aliases
#define Stb_TRIS                 TRISBbits.TRISB6
#define Stb_LAT                  LATBbits.LATB6
#define Stb_PORT                 PORTBbits.RB6
#define Stb_WPU                  WPUBbits.WPUB6
#define Stb_OD                   ODCONBbits.ODCB6
#define Stb_ANS                  ANSELBbits.ANSELB6
#define Stb_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define Stb_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define Stb_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define Stb_GetValue()           PORTBbits.RB6
#define Stb_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define Stb_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define Stb_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define Stb_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define Stb_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define Stb_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define Stb_SetAnalogMode()      do { ANSELBbits.ANSELB6 = 1; } while(0)
#define Stb_SetDigitalMode()     do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set Yled aliases
#define Yled_TRIS                 TRISBbits.TRISB7
#define Yled_LAT                  LATBbits.LATB7
#define Yled_PORT                 PORTBbits.RB7
#define Yled_WPU                  WPUBbits.WPUB7
#define Yled_OD                   ODCONBbits.ODCB7
#define Yled_ANS                  ANSELBbits.ANSELB7
#define Yled_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define Yled_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define Yled_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define Yled_GetValue()           PORTBbits.RB7
#define Yled_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define Yled_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define Yled_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define Yled_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define Yled_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define Yled_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define Yled_SetAnalogMode()      do { ANSELBbits.ANSELB7 = 1; } while(0)
#define Yled_SetDigitalMode()     do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSELC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSELC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set Clk aliases
#define Clk_TRIS                 TRISCbits.TRISC3
#define Clk_LAT                  LATCbits.LATC3
#define Clk_PORT                 PORTCbits.RC3
#define Clk_WPU                  WPUCbits.WPUC3
#define Clk_OD                   ODCONCbits.ODCC3
#define Clk_ANS                  ANSELCbits.ANSELC3
#define Clk_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define Clk_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define Clk_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define Clk_GetValue()           PORTCbits.RC3
#define Clk_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define Clk_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define Clk_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define Clk_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define Clk_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define Clk_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define Clk_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define Clk_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set Sid aliases
#define Sid_TRIS                 TRISCbits.TRISC4
#define Sid_LAT                  LATCbits.LATC4
#define Sid_PORT                 PORTCbits.RC4
#define Sid_WPU                  WPUCbits.WPUC4
#define Sid_OD                   ODCONCbits.ODCC4
#define Sid_ANS                  ANSELCbits.ANSELC4
#define Sid_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define Sid_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define Sid_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define Sid_GetValue()           PORTCbits.RC4
#define Sid_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define Sid_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define Sid_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define Sid_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define Sid_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define Sid_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define Sid_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define Sid_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set AD4 aliases
#define AD4_TRIS                 TRISCbits.TRISC5
#define AD4_LAT                  LATCbits.LATC5
#define AD4_PORT                 PORTCbits.RC5
#define AD4_WPU                  WPUCbits.WPUC5
#define AD4_OD                   ODCONCbits.ODCC5
#define AD4_ANS                  ANSELCbits.ANSELC5
#define AD4_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define AD4_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define AD4_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define AD4_GetValue()           PORTCbits.RC5
#define AD4_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define AD4_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define AD4_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define AD4_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define AD4_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define AD4_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define AD4_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define AD4_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set Mhd1 aliases
#define Mhd1_TRIS                 TRISCbits.TRISC6
#define Mhd1_LAT                  LATCbits.LATC6
#define Mhd1_PORT                 PORTCbits.RC6
#define Mhd1_WPU                  WPUCbits.WPUC6
#define Mhd1_OD                   ODCONCbits.ODCC6
#define Mhd1_ANS                  ANSELCbits.ANSELC6
#define Mhd1_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define Mhd1_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define Mhd1_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define Mhd1_GetValue()           PORTCbits.RC6
#define Mhd1_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define Mhd1_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define Mhd1_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define Mhd1_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define Mhd1_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define Mhd1_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define Mhd1_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define Mhd1_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set Mhd2 aliases
#define Mhd2_TRIS                 TRISCbits.TRISC7
#define Mhd2_LAT                  LATCbits.LATC7
#define Mhd2_PORT                 PORTCbits.RC7
#define Mhd2_WPU                  WPUCbits.WPUC7
#define Mhd2_OD                   ODCONCbits.ODCC7
#define Mhd2_ANS                  ANSELCbits.ANSELC7
#define Mhd2_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define Mhd2_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define Mhd2_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define Mhd2_GetValue()           PORTCbits.RC7
#define Mhd2_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define Mhd2_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define Mhd2_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define Mhd2_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define Mhd2_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define Mhd2_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define Mhd2_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define Mhd2_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/