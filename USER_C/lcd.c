#include "../USER_H/lcd.h"

void lcdport(void) {
    Rst_Toggle();
    Cs_Toggle();
    Sid_Toggle();
    Clk_Toggle();
    __delay_ms(1000);

}

void LCDInit(void) {
    Rst_SetLow();
    __delay_ms(10);
    Rst_SetHigh();
    __delay_ms(100);
    Cs_SetHigh();
    Sid_SetLow();
    Clk_SetLow();
    sendCom(0x30);
    sendCom(0x0c);


    sendCom(0x01);
    
    sendCom(0x02);
    sendCom(0x06);
    sendCom(0x0c);
    sendCom(0x14);
}

void Spi8b(unsigned char dat) {
    char i = 0;

    for (i = 0; i < 8; i++) {

        if ((dat & 0x80) == 0x80) {
            Sid_SetHigh();
        } else {
            Sid_SetLow();
        }
        Clk_SetHigh();
        __delay_ms(2);
        Clk_SetLow();
        __delay_ms(2);
        dat = dat << 1;
    }


}

void sendCom(unsigned char com) {

    unsigned char comh, coml;
    comh = com & 0xf0;
    coml = ((com & 0x0f) << 4);
    //Cs_SetHigh();

    Spi8b(0xf8);

    Spi8b(comh);

    Spi8b(coml);

    //Cs_SetLow();

}

void sendDat(unsigned char dat) {

    unsigned char dath, datl;
    dath = dat & 0xf0;
    datl = ((dat & 0x0f) << 4);
    // Cs_SetHigh();
    __delay_ms(20);
    Spi8b(0xfa);

    Spi8b(dath);

    Spi8b(datl);
    __delay_ms(20);
    //Cs_SetLow();


}

void position(char x, char y) {
    char pos;
    if (x == 1)
        pos = 0x80 + y;
    if (x == 2)
        pos = 0x90 + y;
    if (x == 3)
        pos = 0x88 + y;
    if (x == 4)
        pos = 0x98 + y;
    sendCom(pos);


}

void LcdString(unsigned char *p) {
    while (*p != '\0') {
        sendDat(*p);
        p++;
    }


}

