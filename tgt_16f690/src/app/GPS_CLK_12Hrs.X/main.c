/* 
 * File:   main.c
 * Author: Raja-L
 *
 * Created on 3 April, 2018, 5:16 PM
 */


// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select bit (MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = ON         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#include <stdio.h>
#include <stdlib.h>
#define _XTAL_FREQ 8000000
#define BAUDRATE 9600
#define UART_MAX_RX_SIZE 80
#define UART_RX_MAX_TIMEOUT 200//300 as 3 sec
/*
 * 
 */
unsigned char U16Rx_Write_Index;
unsigned char U16ResponseSize;
char U8Valid_Char,j;
char Receive_buffer[UART_MAX_RX_SIZE];
unsigned int U8_tmr_cnt=0;
unsigned int U8sent_intervel_cnt;
unsigned char Time_Temp1;
unsigned char Time_Temp2;
unsigned char Time_Hr = 0,Time_Min = 0,Time_Sec = 0;
unsigned int Time_local_Hr = 0,Time_local_Min = 0,Time_local_Sec = 0;
unsigned char offset=0;
char IST_TIME[9];char IST_TIME1[9];
unsigned int Temp_Cnt=0,error_cnt=0,sec=0;;
unsigned int i;

void INIT();
void IST_Time_Formate();
char Time_Formate_to_STR();
char Time_Formate_to_STR_local();
void UARTReceiveInterrupt();
unsigned char UARTReceiveddatasize();
void UARTResetRxBuffer();
void send_char(char val);

void Tick();

void interrupt ISR(void)
{      
    if(RCIE && RCIF)
    {   
        UARTReceiveInterrupt(); 
        //send_char('R');
        RCIF = 0;
        
    }        
}

void main() 
{
    INIT();
    PORTA=0xFF; //PORTBbits.RB4=1;PORTBbits.RB6=1;
    int j=0;
    while(1)
    {
    Tick();
       
        if(UARTReceiveddatasize() > 8)
        {
            PORTA=0xFF; 
            UARTResetRxBuffer(); IST_Time_Formate(); Time_Formate_to_STR();
            PORTC=IST_TIME1[0]; PORTA=0xFE;      __delay_ms(5); PORTA=0xFF; 
            PORTC=IST_TIME1[1]; PORTA=0xFD;      __delay_ms(5); PORTA=0xFF; 
            PORTC=IST_TIME1[2]; PORTA=0xFB;      __delay_ms(5); PORTA=0xFF; 
            PORTC=IST_TIME1[3]; PORTA=0xDF;      __delay_ms(5); PORTA=0xFF; 
            Temp_Cnt=0; error_cnt=0;sec=0;

        }
        else
        {
            PORTA=0xFF;
            Time_Formate_to_STR_local();
            PORTC=IST_TIME1[0]; PORTA=0xFE;      __delay_ms(5); PORTA=0xFF;
            PORTC=IST_TIME1[1]; PORTA=0xFD;      __delay_ms(5); PORTA=0xFF;
            PORTC=IST_TIME1[2]; PORTA=0xFB;      __delay_ms(5); PORTA=0xFF;
            PORTC=IST_TIME1[3]; PORTA=0xDF;      __delay_ms(5); PORTA=0xFF;
        
        }
   
      
    }
}

void Tick()
{
    Temp_Cnt++;
        if(Temp_Cnt > 45)
         {
            sec++;
            Time_local_Sec++;
            Temp_Cnt=0; error_cnt++;
            PORTBbits.RB4=~PORTBbits.RB4;
            if(Time_local_Sec > 59)
            {   
                Time_local_Sec=0;
                Time_local_Min++;
                if(Time_local_Min > 59)
                {
                    Time_local_Hr++;
                    Time_local_Min =0;
                    Time_local_Sec=0;
                    if(Time_local_Hr > 12)
                    {
                        Time_local_Hr=0;
                        Time_local_Min=0;
                        Time_local_Sec=0;
                    }
                }
            }
         }
        if(sec > 1000)
          sec=0;
        if(error_cnt >9)
          error_cnt=0;
}

unsigned char UARTReceiveddatasize()
{
	return U16ResponseSize;
} 

void UARTResetRxBuffer()
{
     U16Rx_Write_Index=0;	  
	 U16ResponseSize=0;	 
}
void UARTReceiveInterrupt()
{				
        unsigned char temp;
        temp = RCREG;
        if(temp == '$')
            U8Valid_Char=1;
        else if(U8Valid_Char == 1){
           if(temp == 'G')
               U8Valid_Char=2;
        }
        else if(U8Valid_Char == 2){
           if(temp == 'P')
               U8Valid_Char=3;
        }
        else if(U8Valid_Char == 3){
           if(temp == 'G')
               U8Valid_Char=4;
        }
        else if(U8Valid_Char == 4){
           if(temp == 'G')
               U8Valid_Char=5;
        }
        else if(U8Valid_Char == 5){
           if(temp == 'A')
               U8Valid_Char=6;
        }
        else if(U8Valid_Char == 6){
           if(temp == ',')
               U8Valid_Char=8; 
        }
        else if(U8Valid_Char == 8){
            
            //send_char('K');//UARTsendByte(temp);
            Receive_buffer[U16Rx_Write_Index] = temp;
            U16Rx_Write_Index++;  				
		    U16ResponseSize = U16Rx_Write_Index;
            if(U16ResponseSize > 8){
                U8Valid_Char=0;//UARTResetRxBuffer();//UARTInterruptDisable();
            }
        } 
           
}

void INIT()
{
    OSCCON=0X75;
    //OSCTUNE=0X0F;
    TRISA=0;
    TRISC=0;
    TRISB=0;
    ANSEL =0;
    ANSELH =0;
    GIE=1;
  	PEIE=1;
    TRISB5=1;   
	TXSTA=0x28;
    RCSTA=0x80;    
    SPBRG=12;
    SPBRGH=0;
    BRGH = 0;
    BRG16 = 0;
    RCIE=1;
    RCIF=0;  
    CREN = 1;
    SPEN = 1;
    
    //TXSTA=0x28;
    //RCST=0x0
}
char Time_Formate_to_STR()
{
  IST_TIME1[0]=(Time_Hr/10);
  IST_TIME1[1]=(Time_Hr%10);
  IST_TIME1[2]=(Time_Min/10);
  IST_TIME1[3]=(Time_Min%10);
  IST_TIME1[4]=(Time_Sec/10);
  IST_TIME1[5]=(Time_Sec%10); 
}

char Time_Formate_to_STR_local()
{
  IST_TIME1[0]=(Time_local_Hr/10);
  IST_TIME1[1]=(Time_local_Hr%10);
  IST_TIME1[2]=(Time_local_Min/10);
  IST_TIME1[3]=(Time_local_Min%10);
  IST_TIME1[4]=(Time_local_Sec/10);
  IST_TIME1[5]=(Time_local_Sec%10); 
}
void IST_Time_Formate()
{
    Time_Temp1=Receive_buffer[0]-48;
    Time_Temp2=Receive_buffer[1]-48;
    Time_Hr=(Time_Temp1*10) + Time_Temp2;
    Time_Hr = Time_Hr + 5;
    Time_Temp1=Receive_buffer[2]-48;
    Time_Temp2=Receive_buffer[3]-48;
    Time_Min=(Time_Temp1*10)+Time_Temp2;
    Time_Min=Time_Min + 30;
    Time_Temp1=Receive_buffer[4]-48;
    Time_Temp2=Receive_buffer[5]-48;
    Time_Sec=(Time_Temp1*10)+Time_Temp2;
    
    if(Time_Min > 59)
    {
     Time_Min = Time_Min - 60;//(60 - Time_Min);
     Time_Hr=Time_Hr + 1;
    }
    if(Time_Hr > 24)
    {
     Time_Hr = (Time_Hr - 24);
    } 
    if((Time_Hr >=12) && Time_Hr <=23)
    {
        PORTBbits.RB6=1;
    }
    else
    {
        PORTBbits.RB6=0;
    }
    if(Time_Hr > 12)
    {
        Time_Hr = (Time_Hr - 12);
    }

    
    Time_local_Hr = Time_Hr;
    Time_local_Min = Time_Min;
    Time_local_Sec = Time_Sec;
////////////////////    
}

void send_char(char val)
{
    
    TXREG=val;
    while(!TRMT);
}