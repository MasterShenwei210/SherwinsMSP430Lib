/*
 * sherwins_lib_clk.c
 *
 *  Created on: May 14, 2018
 *      Author: Sherwin
 */

#include <sherwins_lib_clk.h>

void setDCOFrequencyRange(unsigned char bits) {
#if MSP == F5529
   UCSCTL1 |= bits << 4;

#elif MSP == G2231
   BCSCTL1 |= bits;

#endif
}

void setDCOTap(unsigned char bits) {
#if MSP == F5529
    UCSCTL0 |= bits << 8;

#elif MSP == G2231
    DCOCTL |= bits << 5;

#endif
}

#if MSP == F5529
void setDCOPrescaler(unsigned char bits) {
    UCSCTL2 |= bits << 12;
}

void setUpFLL(unsigned char mult, unsigned char reference, unsigned char referenceDivider) {
    UCSCTL3 |= (reference << 4) + referenceDivider;
    UCSCTL2 |= mult;
}

void outputACLK(unsigned char div){
    UCSCTL5 |= div << 12;
    P1SEL |= 0X01;
    P1DIR &= ~0X01;
}

#endif

void setACLK(unsigned char source, unsigned char div) {
#if MSP == F5529
    UCSCTL4 |= source << 8;
    UCSCTL5 |= div << 8;

#elif MSP == G2231
    BCSCTL3 |= source << 4;
    BCSCTL1 |= div << 4;

#endif
}

void setSMCLK(unsigned char source, unsigned char div) {
#if MSP == F5529
    UCSCTL4 |= source << 4;
    UCSCTL5 |= div << 4;

#elif MSP == G2231
    BCSCTL2 |= source << 3
    BCSCTL3 |= div << 1;

#endif
}

void setMCLK(unsigned char source, unsigned char div) {
#if MSP == F5529
    UCSCTL4 |= source;
    UCSCTL5 |= div;

#elif MSP == G2231
    BCSCTL2 |= source << 6;
    BCSCTL2 |= div << 4;

#endif
}



