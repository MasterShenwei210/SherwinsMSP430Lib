/*
 * sherwins_lib_io.h
 *
 *  Created on: Apr 28, 2018
 *      Author: Sherwin
 */

#ifndef INCLUDES_SHERWINS_LIB_IO_H_
#define INCLUDES_SHERWINS_LIB_IO_H_

#include <msp430.h>

void setPortDirections(unsigned char port, unsigned char bits);

void setPinOutput(unsigned char port, unsigned char pin);
void setPinInput(unsigned char port, unsigned char pin);
void setPullDownResistor(unsigned char port, unsigned char pin);
void setPullUpResistor(unsigned char port, unsigned char pin);

void writePortOutput(unsigned char port, unsigned char bits);
void writePinHigh(unsigned char port, unsigned char pin);
void writePinLow(unsigned char port, unsigned char pin);
void togglePin(unsigned char port, unsigned char pin);

unsigned char readPinInput(unsigned char port, unsigned char pin);

void enableHighToLowInterrupt(unsigned char port, unsigned char pin);
void enableLowToHighInterrupt(unsigned char port, unsigned char pin);
void setISR(unsigned char port, void (*isr)(void));
void resetFlag(unsigned char port, unsigned char pin);
unsigned char getPinAndResetFlag(unsigned char port);

#endif /* INCLUDES_SHERWINS_LIB_IO_H_ */
