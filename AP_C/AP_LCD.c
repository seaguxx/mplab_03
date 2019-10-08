#include "../AP_H/ap_lcd.h"
#include "../USER_H/lcd.h"
void display_char(int y, int x, int char_length, unsigned char *p) {
    char i = 0;
    sendCom(0x30); /*???????*/
    __delay_us(10);
    // transfer_command(0x01); /*??*/
    __delay_us(10);
    sendCom(0x80 + (y - 1)*(0x10)+(x - 1));
    for (i = 0; i < char_length; i++) {
        sendDat(*p);
        p++;
        sendDat(*p); /* ???????????????*/
        p++;
    }
}

void display_3232(int y, int x, char  *p) {
    int i, j;
    sendCom(0x36); /*???????*/
    __delay_us(10);
    for (j = 0; j < 32; j++) {
        sendCom(0x80 + (y - 1) + j); /*????*/
        sendCom(0x80 + (x - 1)); /*????*/
        for (i = 0; i < 4; i++) {
            sendDat(*p);
            p++;
        }
    }
}

void display_1632(int y, int x, char  *p) {
    int i, j;
    sendCom(0x36);
    for (j = 0; j < 32; j++) {
        sendCom(0x80 + (y - 1) + j);
        sendCom(0x80 + (x - 1));
        for (i = 0; i < 2; i++) {
            sendDat(*p);
            p++;
        }
    }
}

void display_12864(int y, int x, char  *p) {
    int i, j;
    sendCom(0x36); /*???????*/
    __delay_us(10);
    /*??????32 ???*/
    for (j = 0; j < 32; j++) {
        sendCom(0x80 + (y - 1) + j); /*????*/
        sendCom(0x80 + (x - 1)); /*????*/
        for (i = 0; i < 8; i++) //
        {
            sendDat(*p);
            p++;
            sendDat(*p);
            p++;
        }
    }
    sendCom(0x36); /*???????*/
    __delay_us(10);
    /*??????32 ???*/
    for (j = 0; j < 32; j++) {
        sendCom(0x80 + (y - 1) + j); /*????*/
        sendCom(0x80 + (x - 1) + 8); /*????*/
        for (i = 0; i < 8; i++) {
            sendDat(*p);
            p++;
            sendDat(*p);
            p++;
        }
    }
}

