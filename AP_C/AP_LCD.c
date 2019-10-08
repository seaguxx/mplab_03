#include "../AP_H/ap_lcd.h"
#include "../USER_H/lcd.h"
#include "math.h"
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

void LCD_Draw_Two_Dot(unsigned char StartX,unsigned char StartY,unsigned char EndX,unsigned char EndY,unsigned char Color)
{
    int t,distance; /*������Ļ��С�ı��������(���Ϊint��)*/
    int x=0,y=0,delta_x,delta_y;
    char incx,incy;

    delta_x=EndX-StartX;
    delta_y=EndY-StartY;

    if(delta_x>0) 
	{   
		incx=1;  
	}
	 
    else
	{ 
	   if( delta_x==0 )
       {
           v_Lcd12864DrawLineY_f(StartX,StartY,EndY,Color);
          return;
        }
        else {  incx=-1; }
	}
    
    if(delta_y>0)  
	{  
		incy=1; 
	}

    else
	{ 
	    if(delta_y==0)
        {
            v_Lcd12864DrawLineX_f( StartX,EndX,StartY,Color);    
            return;
        }
       else	 {  incy=-1; }
	}

    delta_x=abs(delta_x);    
    delta_y=abs(delta_y);

    if(delta_x>delta_y)	 
	{ 
		distance=delta_x; 
	}
    else  
	{ 
		distance=delta_y; 
	}
    
    Draw_point(StartX,StartY,Color);    
    /* Draw Line*/
    for(t=0;t<=distance+1;t++)
    {
        Draw_point(StartX,StartY,Color);
        x+=delta_x;
        y+=delta_y;
        if(x>distance)
        {
            x-=distance;
            StartX+=incx;
        }
        if(y>distance)
        {
            y-=distance;
            StartY+=incy;
        }
    }
}
void LCD_DrawSineWave(void)
{
	unsigned char xn=0;
	unsigned char yn=32; 
	unsigned char i;
	unsigned char xi,yi;
	
	for(i=0;i<127;i++)
	{
		xi=i;  
		yi=(sin(i*0.5)*20)+32;  //��yn=0�� yi=i*0.5�̻�ֱ��	  yi=j*2
		LCD_Draw_Two_Dot(xn,yn,xi,yi,1); //��һϵ����ɢ�ĵ��ϣ���������֮�����ߣ��Ӷ��õ�һ������
		xn=i;  
		yn=yi;
	}
}
void LCD_DrawCoseWave(void)	  //��������
{
	unsigned char xn=0;
	unsigned char yn=32; 
	unsigned char i;
	unsigned char xi,yi;
	
	for(i=0;i<127;i++)
	{
		xi=i;  
		yi=32-20*cos(i*5/20);  //�޸�������ʽ����ֵ����������ı䲨�εĴ�С
		LCD_Draw_Two_Dot(xn,yn,xi,yi,1); //��һϵ����ɢ�ĵ��ϣ���������֮�����ߣ��Ӷ��õ�һ������
		xn=i;  
		yn=yi;
	}
}
