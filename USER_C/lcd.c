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
unsigned char Readspi(void)
{
    char i = 0;
    unsigned char dat=0xff;//
    
    for (i = 0; i < 8; i++) {
              
        Sid_SetHigh();       
        Clk_SetHigh();
        __delay_ms(2);
        Clk_SetLow();
        __delay_ms(2);
        if(Sid_GetValue()==1)
        {
            dat=dat|0x01;
        }
        else
        {
            dat=dat;
        }
        dat = dat << 1;
    }
    return (dat);
}
unsigned char LCD_read_arm(void)
{
    unsigned char a1=0x00;
    unsigned char a2=0x00;
    unsigned char a3=0x00;
    Spi8b(0xfe);
    a1=Readspi();
    a2=Readspi();
    a3=(a1&0xf0)|(a2>>4);
    return (a3);
}
void Draw_point(unsigned char X,unsigned char Y,unsigned char Color)  //�ĵ�
{
    unsigned char Row, Tier, Tier_bit;	 //��row  ��tier
    unsigned char  ReadOldH, ReadOldL;	  //������������������Ŷ�����������
    sendCom(0x34);	   //ʹ������ָ��
    sendCom(0x36);	   //�ػ�ͼ��ʾ
    Tier=X>>4;    			  //ȡ�еĸ���λ���ж�����һ���У�ֵ��0-7
    Tier_bit=X&0x0f;		  //ȡ�еĵ���λ���ж��ڸ�8λ�����ڵ�8λ

    if(Y<32) {  Row=Y; }
    else  {	 Row= Y-32; Tier+=8; }	  
      
    sendCom(Row+0x80);
    sendCom(Tier+0x80);

    LCD_read_arm();	//��RAM
    ReadOldH=LCD_read_arm();//ǰ8��	һ�������������ֽڣ���ֹ�ظ���� 
    ReadOldL=LCD_read_arm();//��8�� 

    sendCom(Row+0x80);	  //��д�е�ַ
    sendCom(Tier+0x80);	  //д�е�ַ
    if(Tier_bit<8 )		  //��λ
    {
        switch(Color)
        {
            case 0 : ReadOldH&=(~(0x01<<( 7 - Tier_bit ))); break ;	 //��ף���λ
            case 1 : ReadOldH|=( 0x01 <<( 7 - Tier_bit )) ; break ;	 //��ڣ���λ
            case 2 : ReadOldH^=( 0x01 <<( 7 - Tier_bit )) ; break ;	 //ȡ��
            default : break ;    
        }
        sendDat(ReadOldH);	  //д��8λ��0-7�ں�
        sendDat(ReadOldL);	   //д��8λ��8-15��ǰ
    }
    else	  //��λ
    {
        switch(Color)
        {
            case 0 : ReadOldL&=(~(0x01<<( 15 - Tier_bit ))); break ;
            case 1 : ReadOldL|=( 0x01 <<( 15 - Tier_bit )) ; break ;
            case 2 : ReadOldL^=( 0x01 <<( 15 - Tier_bit )) ; break ;
            default : break ;
        }
        sendDat(ReadOldH);		 //д���ݣ���8λ0-7
        sendDat(ReadOldL);		 //д���ݣ���8λ8-15
    }
    sendCom(0x30); 		//�ص�����ָ��
}

void v_Lcd12864DrawLineX_f(unsigned char X0,unsigned char X1,unsigned char Y,unsigned char Color)
{    
    unsigned char Temp;
    if(X0>X1)
    {
        Temp=X1;
        X1=X0;
        X0=Temp;
    }
    for( ;X0<=X1;X0++)
    Draw_point(X0,Y,Color);    
}
void v_Lcd12864DrawLineY_f(unsigned char X,unsigned char Y0,unsigned char Y1,unsigned char Color)
{
    unsigned char Temp;
    if(Y0>Y1)
    {
        Temp=Y1;
        Y1=Y0;
        Y0=Temp;
    }
    for( ;Y0<=Y1;Y0++)
    Draw_point(X,Y0,Color);
}