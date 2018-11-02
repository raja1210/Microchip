#include <xc.h>
#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "config.h"


void data_load();
void setRGBColour(rgbLedColour_t RGB,unsigned char LedPos);
void patternDesign();
void flushledarray();

void data_load() 
{
   __delay_us(50);
    #asm
    _asm
    
    BCF STATUS,5
    BCF STATUS,6
    MOVLW 0x20
    MOVWF FSR
    MOVLW MAX_LEN
    MOVWF _ledCount
    MOVLW 0x00
    MOVWF _bit_cnt
    
    main_loop:
            BSF _bit_cnt,3
        loop:
            btfsc INDF,7
            goto writeone
            goto writezero
        writeone:
            bsf PORTC,3
            nop
            RLF INDF
            bcf PORTC,3
            DECFSZ _bit_cnt
            goto loop
            goto endbyte
        writezero:
            bsf PORTC,3
            bcf PORTC,3
            RLF INDF
            DECFSZ _bit_cnt
            goto loop
            goto endbyte
        endbyte:
            INCF FSR
            DECFSZ _ledCount
            goto main_loop
   _endasm
   #endasm
}

void setRGBColour(rgbLedColour_t RGB,unsigned char LedPos)
{
   memcpy(&RGBLed[LedPos],&RGB,sizeof(RGB));
   //printf("%i-%i-%i\n",RGBLed[LedPos].rLed,RGBLed[LedPos].gLed,RGBLed[LedPos].bLed,);
}

void flushledarray()
{
   memset(&RGBLed[0],0x00,TOTAL_LED*3); 
}


void patternDesign()
{
    setRGBColour(RedColour,0);setRGBColour(RedColour,1);setRGBColour(RedColour,2);setRGBColour(RedColour,3);setRGBColour(RedColour,4);setRGBColour(RedColour,5);setRGBColour(RedColour,6);setRGBColour(RedColour,7);setRGBColour(RedColour,8);setRGBColour(RedColour,9);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(RedColour,0);setRGBColour(RedColour,1);setRGBColour(RedColour,2);setRGBColour(RedColour,3);setRGBColour(RedColour,4);setRGBColour(RedColour,5);setRGBColour(RedColour,6);setRGBColour(RedColour,7);setRGBColour(RedColour,8);setRGBColour(RedColour,9);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(RedColour,0);setRGBColour(RedColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(RedColour,0);setRGBColour(RedColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(RedColour,0);setRGBColour(RedColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(RedColour,0);setRGBColour(RedColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(RedColour,0);setRGBColour(RedColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(RedColour,0);setRGBColour(RedColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(RedColour,0);setRGBColour(RedColour,1);setRGBColour(RedColour,2);setRGBColour(RedColour,3);setRGBColour(RedColour,4);setRGBColour(RedColour,5);setRGBColour(RedColour,6);setRGBColour(RedColour,7);setRGBColour(RedColour,8);setRGBColour(RedColour,9);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(RedColour,0);setRGBColour(RedColour,1);setRGBColour(RedColour,2);setRGBColour(RedColour,3);setRGBColour(RedColour,4);setRGBColour(RedColour,5);setRGBColour(RedColour,6);setRGBColour(RedColour,7);setRGBColour(RedColour,8);setRGBColour(RedColour,9);
    data_load(); __delay_ms(2);
    flushledarray();
    
    __delay_ms(8);
    
    setRGBColour(GreenColour,0);setRGBColour(GreenColour,1);setRGBColour(GreenColour,2);setRGBColour(GreenColour,3);setRGBColour(GreenColour,4);setRGBColour(GreenColour,5);setRGBColour(GreenColour,6);setRGBColour(GreenColour,7);setRGBColour(GreenColour,8);setRGBColour(GreenColour,9);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(GreenColour,0);setRGBColour(GreenColour,1);setRGBColour(GreenColour,2);setRGBColour(GreenColour,3);setRGBColour(GreenColour,4);setRGBColour(GreenColour,5);setRGBColour(GreenColour,6);setRGBColour(GreenColour,7);setRGBColour(GreenColour,8);setRGBColour(GreenColour,9);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(GreenColour,0);setRGBColour(GreenColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(GreenColour,0);setRGBColour(GreenColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(GreenColour,0);setRGBColour(GreenColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(GreenColour,0);setRGBColour(GreenColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(GreenColour,0);setRGBColour(GreenColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(GreenColour,0);setRGBColour(GreenColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(GreenColour,0);setRGBColour(GreenColour,1);setRGBColour(GreenColour,2);setRGBColour(GreenColour,3);setRGBColour(GreenColour,4);setRGBColour(GreenColour,5);setRGBColour(GreenColour,6);setRGBColour(GreenColour,7);setRGBColour(GreenColour,8);setRGBColour(GreenColour,9);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(GreenColour,0);setRGBColour(GreenColour,1);setRGBColour(GreenColour,2);setRGBColour(GreenColour,3);setRGBColour(GreenColour,4);setRGBColour(GreenColour,5);setRGBColour(GreenColour,6);setRGBColour(GreenColour,7);setRGBColour(GreenColour,8);setRGBColour(GreenColour,9);
    data_load(); __delay_ms(2);
    flushledarray();
    
    __delay_ms(8);
    
    setRGBColour(BlueColour,0);setRGBColour(BlueColour,1);setRGBColour(BlueColour,2);setRGBColour(BlueColour,3);setRGBColour(BlueColour,4);setRGBColour(BlueColour,5);setRGBColour(BlueColour,6);setRGBColour(BlueColour,7);setRGBColour(BlueColour,8);setRGBColour(BlueColour,9);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(BlueColour,0);setRGBColour(BlueColour,1);setRGBColour(BlueColour,2);setRGBColour(BlueColour,3);setRGBColour(BlueColour,4);setRGBColour(BlueColour,5);setRGBColour(BlueColour,6);setRGBColour(BlueColour,7);setRGBColour(BlueColour,8);setRGBColour(BlueColour,9);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(BlueColour,0);setRGBColour(BlueColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(BlueColour,0);setRGBColour(BlueColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(BlueColour,0);setRGBColour(BlueColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(BlueColour,0);setRGBColour(BlueColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(BlueColour,0);setRGBColour(BlueColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(BlueColour,0);setRGBColour(BlueColour,1);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(BlueColour,0);setRGBColour(BlueColour,1);setRGBColour(BlueColour,2);setRGBColour(BlueColour,3);setRGBColour(BlueColour,4);setRGBColour(BlueColour,5);setRGBColour(BlueColour,6);setRGBColour(BlueColour,7);setRGBColour(BlueColour,8);setRGBColour(BlueColour,9);
    data_load(); __delay_ms(2);
    flushledarray();
    setRGBColour(BlueColour,0);setRGBColour(BlueColour,1);setRGBColour(BlueColour,2);setRGBColour(BlueColour,3);setRGBColour(BlueColour,4);setRGBColour(BlueColour,5);setRGBColour(BlueColour,6);setRGBColour(BlueColour,7);setRGBColour(BlueColour,8);setRGBColour(BlueColour,9);
    data_load(); __delay_ms(2);
    flushledarray();
    
    __delay_ms(8);
    
}
/*
void patternDesign()
{
   flushledarray();
   setRGBColour(RedColour,4);
   data_load(); __delay_ms(4);
   flushledarray();
   setRGBColour(RedColour,3);setRGBColour(RedColour,4);setRGBColour(RedColour,5);
   data_load(); __delay_ms(4);
   flushledarray();
   setRGBColour(RedColour,2);setRGBColour(RedColour,3);setRGBColour(RedColour,4);setRGBColour(RedColour,5);setRGBColour(RedColour,6);
   data_load(); __delay_ms(4);
   flushledarray();
   setRGBColour(RedColour,1);setRGBColour(RedColour,2);setRGBColour(RedColour,3);setRGBColour(RedColour,4);setRGBColour(RedColour,5);setRGBColour(RedColour,6);setRGBColour(RedColour,7);
   data_load(); __delay_ms(4);
   flushledarray();
   setRGBColour(RedColour,0);setRGBColour(RedColour,1);setRGBColour(RedColour,2);setRGBColour(RedColour,3);setRGBColour(RedColour,4);setRGBColour(RedColour,5);setRGBColour(RedColour,6);setRGBColour(RedColour,7);setRGBColour(RedColour,8);
   data_load(); __delay_ms(4);
   flushledarray();
   setRGBColour(RedColour,1);setRGBColour(RedColour,2);setRGBColour(RedColour,3);setRGBColour(RedColour,4);setRGBColour(RedColour,5);setRGBColour(RedColour,6);setRGBColour(RedColour,7);
   data_load(); __delay_ms(4);
   flushledarray();
   setRGBColour(RedColour,2);setRGBColour(RedColour,3);setRGBColour(RedColour,4);setRGBColour(RedColour,5);setRGBColour(RedColour,6);
   data_load(); __delay_ms(4);
   flushledarray();
   setRGBColour(RedColour,3);setRGBColour(RedColour,4);setRGBColour(RedColour,5);
   data_load(); __delay_ms(4);
   flushledarray();
   setRGBColour(RedColour,4);
   data_load();__delay_ms(4); 
   flushledarray();data_load();__delay_ms(40);
   
   flushledarray();
   setRGBColour(GreenColour,4);
   data_load(); __delay_ms(4);
   flushledarray();
   setRGBColour(GreenColour,3);setRGBColour(GreenColour,4);setRGBColour(GreenColour,5);
   data_load(); __delay_ms(4);
   flushledarray();
   setRGBColour(GreenColour,2);setRGBColour(GreenColour,3);setRGBColour(GreenColour,4);setRGBColour(GreenColour,5);setRGBColour(GreenColour,6);
   data_load(); __delay_ms(4);
   flushledarray();
   setRGBColour(GreenColour,1);setRGBColour(GreenColour,2);setRGBColour(GreenColour,3);setRGBColour(GreenColour,4);setRGBColour(GreenColour,5);setRGBColour(GreenColour,6);setRGBColour(GreenColour,7);
   data_load(); __delay_ms(4);
   flushledarray();
   setRGBColour(GreenColour,0);setRGBColour(GreenColour,1);setRGBColour(GreenColour,2);setRGBColour(GreenColour,3);setRGBColour(GreenColour,4);setRGBColour(GreenColour,5);setRGBColour(GreenColour,6);setRGBColour(GreenColour,7);setRGBColour(GreenColour,8);
   data_load(); __delay_ms(4);
   flushledarray();
   setRGBColour(GreenColour,1);setRGBColour(GreenColour,2);setRGBColour(GreenColour,3);setRGBColour(GreenColour,4);setRGBColour(GreenColour,5);setRGBColour(GreenColour,6);setRGBColour(GreenColour,7);
   data_load(); __delay_ms(4);
   flushledarray();
   setRGBColour(GreenColour,2);setRGBColour(GreenColour,3);setRGBColour(GreenColour,4);setRGBColour(GreenColour,5);setRGBColour(GreenColour,6);
   data_load(); __delay_ms(4);
   flushledarray();
   setRGBColour(GreenColour,3);setRGBColour(GreenColour,4);setRGBColour(GreenColour,5);
   data_load(); __delay_ms(4);
   flushledarray();
   setRGBColour(GreenColour,4);
   data_load(); __delay_ms(4);
   flushledarray();data_load();__delay_ms(40);
   
   
}
*/