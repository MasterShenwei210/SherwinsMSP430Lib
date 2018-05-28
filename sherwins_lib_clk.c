/*
 * sherwins_lib_clk.c
 *
 *  Created on: May 14, 2018
 *      Author: Sherwin
 */

#include <sherwins_lib_clk.h>

/*
 * @params
 *      bits: 3 bit selection, see device specific data sheet
 *            for frequency ranges
 */
void setDCOFrequencyRange(unsigned char bits) {
#if MSP == F5529
   UCSCTL1 &= ~0b1110000;
   UCSCTL1 |= bits << 4;

#elif MSP == G2231
   BCSCTL1 &= ~0b111;
   BCSCTL1 |= bits;

#endif
}

/*
 * @params: bits: bits for DCO frequency select within range,
 *          3 bit for g2231 and 5 bit for f5529
 */
void setDCOTap(unsigned char bits) {
#if MSP == F5529
    UCSCTL0 &= ~0b1111100000000;
    UCSCTL0 |= bits << 8;

#elif MSP == G2231
    DCOCTL &= ~0b11100000
    DCOCTL |= bits << 5;

#endif
}

/*
 * @params: bits: bits for prescaler which acts like
 *          additional multiplication for FLL and
 *          DCO division for DCOCLKDIV output
 */
#if MSP == F5529
void setDCOPrescaler(unsigned char bits) {
    UCSCTL2 = (bits << 12) + UCSCTL2 & 0x3FF;
}

/*
 * @params: mult: 9 bit loop multiplier, output is this times
 *                 input reference clock after division
 *
 *          reference: reference clock select, recommended to choose
 *          REFCLOCK at 32.768 kHz.
 *
 *          reference divider: divides reference clock before input to FLL
 */
void setUpFLL(unsigned char mult, unsigned char reference, unsigned char referenceDivider) {
    UCSCTL3 = (reference << 4) + referenceDivider;
    UCSCTL2 &= ~0b1111111111;
    UCSCTL2 |= mult;
}

/*
 * @params: div: division before output on pin 1_0
 */
void outputACLK(unsigned char div){
    UCSCTL5 &= ~0b111000000000000;
    UCSCTL5 |= div << 12;
    P1SEL |= 0X01;
    P1DIR |= 0X01;
}

#endif

/*
 * @params: source: source of ACLK
 *
 *          div: division before output to ACLK
 */
void setACLK(unsigned char source, unsigned char div) {
#if MSP == F5529
    UCSCTL4 &= ~0b11100000000;
    UCSCTL4 |= source << 8;
    UCSCTL5 &= ~0b11100000000;
    UCSCTL5 |= div << 8;

#elif MSP == G2231

    BCSCTL3 &= ~0b110000;
    BCSCTL3 |= source << 4;
    BCSCTL1 &= 0b11
    BCSCTL1 |= div << 4;

#endif
}

/*
 * @params: source: source of SMCLK
 *          (for g2 devices, 1 is for DCOCLK
 *          and 0 is for LFXTICLK/VLOCLK)
 *
 *          div: division before output to SMCLK
 */
void setSMCLK(unsigned char source, unsigned char div) {
#if MSP == F5529
    UCSCTL4 &= ~0b1110000;
    UCSCTL4 |= source << 4;
    UCSCTL5 &= ~0b1110000;
    UCSCTL5 |= div << 4;

#elif MSP == G2231
    BCSCTL2 &= ~0b1000;
    BCSCTL2 |= source << 3
    BCSCTL2 &= ~0b110;
    BCSCTL2 |= div << 1;

#endif
}

/*
 * @params: source: source of MCLK
 *
 *          div: division before output to MCLK
 */
void setMCLK(unsigned char source, unsigned char div) {
#if MSP == F5529
    UCSCTL4 &= ~0b111;
    UCSCTL4 |= source;
    UCSCTL5 &= ~0b111;
    UCSCTL5 |= div;

#elif MSP == G2231
    BCSCTL2 &= ~0b11000000;
    BCSCTL2 |= source << 6;
    BCSCTL2 &= ~0b110000;
    BCSCTL2 |= div << 4;

#endif
}



