/*
 * sherwins_lib_io.h
 *
 *  Created on: Apr 28, 2018
 *      Author: Sherwin
 */

#ifndef INCLUDES_SHERWINS_LIB_IO_H_
#define INCLUDES_SHERWINS_LIB_IO_H_

void setPortDirections(unsigned char port, unsigned char bits) {
#if MSP == F5529
    if (port == 1) {
        P1DIR = bits;
    } else if (port == 2) {
        P2DIR = bits;
    } else if (port == 3) {
        P3DIR = bits;
    } else if (port == 4) {
        P4DIR = bits;
    } else if (port == 5) {
        P5DIR = bits;
    } else if (port == 6) {
        P6DIR = bits;
    } else if (port == 7) {
        P7DIR = bits;
    } else if (port == 8) {
        P8DIR = bits;
    }

#elif MSP == G2231
    if (port == 1) {
        P1DIR = bits;
    } else if (port == 2) {
        P2DIR = bits;
    }

#endif
}

void setPinOutput(unsigned char port, unsigned char pin);
void setPinInput(unsigned char port, unsigned char pin);
void setPullDownResistor(unsigned char port, unsigned char pin);

void setPullUpResistor(unsigned char, port, unsigned char pin);

void writePortOutput(unsigned char port, unsigned char bits);
void writePinHigh(unsigned char port, unsigned char pin);
void writePinLow(unsigned char port, unsigned char pin);
void togglePin(unsigned char port, unsigned char pin);

unsigned char readPinInput(unsigned char port, unsigned char pin);

void enableHighToLowInterrupt(unsigned char port, unsigned char pin);
void enableLowToHighInterrupt(unsigned char port, unsigned char pin);
void setISR(unsigned char port, void (*isr)(void));
void resetFlag(unsigned char port, unsigned char pin)

#endif /* INCLUDES_SHERWINS_LIB_IO_H_ */
