/*
 * main.c
 *
 *  Created on: Apr 28, 2018
 *      Author: Sherwin
 */
//#include <sherwins_lib_io.h>
#include <sherwins_lib_io.h>

void isr() {
    switch (getPinAndResetFlag(1)) {
    case 1:
        togglePin(4, 7);
        break;

    default:
        break;
    }

}

int main() {
    WDTCTL = WDTPW | WDTHOLD;
    setPinOutput(4, 7);
    setPinInput(1, 1);
    setPullUpResistor(1, 1);

    enableHighToLowInterrupt(1, 1);
    setISR(1, isr);

    for (;;) {

    }
    return 0;
}



