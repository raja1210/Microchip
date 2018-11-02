/*
 * File:   main.c
 * Author: Raja
 *
 * Created on June 10, 2018, 3:36 PM
 */
#pragma config FOSC = HS   // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select bit (MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = ON         // Code Protection bit (Program memory code protection is Enabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)

#include <xc.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
#include "config.h"


void main(void) 
{
    OSCCON=0x00;
    TRISC=0;
    ANSEL =0;
    ANSELH =0;
    while(1) 
    {
        patternDesign();
    }
return;
}



/*void fade()
{
    static char j;
    for(j=0;j<255;j=j+5)
    {
       unsigned char k=0;
       for(i=0;i<TOTAL_LED;i++)
       {
           array_data[k+0]=30;
           array_data[k+1]=0;
           array_data[k+2]=j;
           k=k+3;
       }
       __delay_ms(100);
        data_load();
    }
    for(j=0;j<255;j=j+5)
    {
       unsigned char k=0;
       for(i=0;i<TOTAL_LED;i++)
       {
           array_data[k+0]=j;
           array_data[k+1]=30;
           array_data[k+2]=0;
           k=k+3;
       }
       __delay_ms(100);
        data_load();
    }
    for(j=0;j<255;j=j+5)
    {
       unsigned char k=0;
       for(i=0;i<TOTAL_LED;i++)
       {
           array_data[k+0]=0;
           array_data[k+1]=j;
           array_data[k+2]=30;
           k=k+3;
       }
       __delay_ms(100);
        data_load();
    }
}*/