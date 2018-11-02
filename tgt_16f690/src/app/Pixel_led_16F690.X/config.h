/* 
 * File:   config.h
 * Author: Raja
 *
 * Created on October 17, 2018, 9:21 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

#define _XTAL_FREQ 20000000
#define TOTAL_LED 10
#define MAX_LEN TOTAL_LED*3

typedef struct rgbLedColur{
   unsigned char rLed;
   unsigned char gLed;
   unsigned char bLed;
}rgbLedColour_t;

rgbLedColour_t RedColour   = {255,0,0};
rgbLedColour_t GreenColour = {0,255,0};
rgbLedColour_t BlueColour  = {0,0,255};

rgbLedColour_t RGBLed[TOTAL_LED] @0x20;

unsigned int bit_cnt,ledCount=MAX_LEN;

/*Function Declaration*/
extern void patternDesign();
//void fade();


#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

