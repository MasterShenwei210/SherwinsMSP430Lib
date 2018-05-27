/*
 * sherwins_lib_others.h
 *
 *  Created on: Apr 29, 2018
 *      Author: Sherwin
 */

#ifndef SHERWINS_LIB_CLK_H_
#define SHERWINS_LIB_CLK_H_

#include <msp430.h>

#if defined (__MSP430F5529__)
#define MSP     0

#elif defined (__MSP430G2231__)
#define MSP     1

#endif

#define F5529   0
#define G2231   1

#define XT1CLK          0x00
#define REFCLOCK        0x02
#define XT2CLK          0x05
#define VLOCLK          0X01
#define DCOCLK          0X03
#define DCOCLKDIV       0X04


#define FLLDIV_1        0X00
#define FLLDIV_2        0x01
#define FLLDIV_4        0x02
#define FLLDIV_8        0X03
#define FLLDIV_12       0X04
#define FLLDIV_16       0X05

#define DIV_1           0X00
#define DIV_2           0X01
#define DIV_4           0x02
#define DIV_8           0X03
#define DIV_16          0X04
#define DIV_32          0X05


void setDCOFrequencyRange(unsigned char bits);
void setDCOTap(unsigned char bits);

#if MSP == F5529
void setDCOPrescaler(unsigned char bits);
void setUpFLL(unsigned char mult, unsigned char reference, unsigned char referenceDivider);
void outputACLK(unsigned char div);
#endif

void selectACLKSource(unsigned char source);
void selectSMCLKSource(unsigned char source);
void selectMCLKSource(unsigned char source);
void selectACLKDiv(unsigned char div);
void selectSMCLKDiv(unsigned char div);
void selectMCLKDiv(unsigned char div);


#endif /* SHERWINS_LIB_CLK_H_ */
