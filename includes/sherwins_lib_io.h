/*
 * sherwins_lib_io.h
 *
 *  Created on: Apr 27, 2018
 *      Author: Sherwin
 */

#ifndef INCLUDES_SHERWINS_LIB_IO_H_
#define INCLUDES_SHERWINS_LIB_IO_H_

void setPortDirections(unsigned char port, unsigned char bits);
void setPinOutput(unsigned char port, unsigned char pin);
void setPinInput(unsigned char port, unsigned char pin);

void setPullDownResistor(unsigned char port, unsigned char pin);
void setPullUpResistor(unsigned char, port, unsigned char pin);

void writePortOutput(unsigned char port, unsigned char bits);
void writePinOutput(unsigned char port, unsigned char pin, bool state);

unsigned char readPortInput(unsigned char port);
bool readPinInput(unsigned char port, unsigned char pin);

void enableHighToLowInterrupt(unsigned char port, unsigned char pin);
void enableLowToHighInterrupt(unsigned char port, unsigned char pin);
void setISR(unsigned char port);

#endif /* INCLUDES_SHERWINS_LIB_IO_H_ */
