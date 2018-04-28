/*
 * sherwins_msp430_lib.h
 *
 *  Created on: Apr 27, 2018
 *      Author: Sherwin
 */

#ifndef INCLUDES_SHERWINS_MSP430_LIB_H_
#define INCLUDES_SHERWINS_MSP430_LIB_H_

#include "msp430.h"
#include "sherwins_lib_io.h"

#if defined (__MSP430F5529__)
#define MSP 0

#elif defined (__MSP430G2231__)
#define MSP 1

#endif

#define F5529   0
#define G2231   1

void (*port_1_isr)();
void (*port_2_isr)();

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

void setPinOutput(unsigned char port, unsigned char pin) {
    unsigned char bit = 1 << pin;
#if MSP == F5529
    if (port == 1) {
        P1DIR |= bit;
    } else if (port == 2) {
        P2DIR |= bit;
    } else if (port == 3) {
        P3DIR |= bit;
    } else if (port == 4) {
        P4DIR |= bit;
    } else if (port == 5) {
        P5DIR |= bit;
    } else if (port == 6) {
        P6DIR |= bit;
    } else if (port == 7) {
        P7DIR |= bit;
    } else if (port == 8) {
        P8DIR |= bit;
    }

#elif MSP == G2231
    if (port == 1) {
        P1DIR |= bit;
    } else if (port == 2) {
        P2DIR |= bit;
    }

#endif
}

void setPinInput(unsigned char port, unsigned char pin) {
    unsigned char bit = 1 << pin;
#if MSP == F5529
    if (port == 1) {
        P1DIR &= ~bit;
    } else if (port == 2) {
        P2DIR &= ~bit;
    } else if (port == 3) {
        P3DIR &= ~bit;
    } else if (port == 4) {
        P4DIR &= ~bit;
    } else if (port == 5) {
        P5DIR &= ~bit;
    } else if (port == 6) {
        P6DIR &= ~bit;
    } else if (port == 7) {
        P7DIR &= ~bit;
    } else if (port == 8) {
        P8DIR &= ~bit;
    }

#elif MSP == G2231
    if (port == 1) {
        P1DIR &= ~bit;
    } else if (port == 2) {
        P2DIR &= ~bit;
    }

#endif
}

void setPullDownResistor(unsigned char port, unsigned char bit) {
    unsigned char bit = 1 << pin;
#if MSP == F5529
    if (port == 1) {
        P1REN |= bit;
        P1OUT &= ~bit;
    } else if (port == 2) {
        P2REN |= bit;
        P2OUT &= ~bit;
    } else if (port == 3) {
        P3REN |= bit;
        P3OUT &= ~bit;
    } else if (port == 4) {
        P4REN |= bit;
        P4OUT &= ~bit;
    } else if (port == 5) {
        P5REN |= bit;
        P5OUT &= ~bit;
    } else if (port == 6) {
        P6REN |= bit;
        P6OUT &= ~bit;
    } else if (port == 7) {
        P7REN |= bit;
        P7OUT &= ~bit;
    } else if (port == 8) {
        P8REN |= bit;
        P8OUT &= ~bit;
    }

#elif MSP == G2231
    if (port == 1) {
            P1REN |= bit;
            P1OUT &= ~bit;
    } else if (port == 2) {
            P2REN |= bit;
            P2OUT &= ~bit;
    }

#endif
}

void setPullUpResistor(unsigned char, port, unsigned char pin) {
    unsigned char bit = 1 << pin;
#if MSP == F5529
    if (port == 1) {
        P1REN |= bit;
        P1OUT |= bit;
    } else if (port == 2) {
        P2REN |= bit;
        P2OUT |= bit;
    } else if (port == 3) {
        P3REN |= bit;
        P3OUT |= bit;
    } else if (port == 4) {
        P4REN |= bit;
        P4OUT |= bit;
    } else if (port == 5) {
        P5REN |= bit;
        P5OUT |= bit;
    } else if (port == 6) {
        P6REN |= bit;
        P6OUT |= bit;
    } else if (port == 7) {
        P7REN |= bit;
        P7OUT |= bit;
    } else if (port == 8) {
        P8REN |= bit;
        P8OUT |= bit;
    }

#elif MSP == G2231
    if (port == 1) {
            P1REN |= bit;
            P1OUT |= bit;
    } else if (port == 2) {
            P2REN |= bit;
            P2OUT |= bit;
    }

#endif
}

void writePortOutput(unsigned char port, unsigned char bits) {
#if MSP == F5529
    if (port == 1) {
        P1OUT = bits;
    } else if (port == 2) {
        P2OUT = bits;
    } else if (port == 3) {
        P3OUT = bits;
    } else if (port == 4) {
        P4OUT = bits;
    } else if (port == 5) {
        P5OUT = bits;
    } else if (port == 6) {
        P6OUT = bits;
    } else if (port == 7) {
        P7OUT = bits;
    } else if (port == 8) {
        P8OUT = bits;
    }

#elif MSP == G2231
    if (port == 1) {
        P1OUT = bits;
    } else if (port == 2) {
        P2OUT = bits;
    }

#endif
}

void writePinOutput(unsigned char port, unsigned char pin, unsigned char state) {
    unsigned char bit = 1 << pin;
#if MSP == F5529
    if (port == 1) {
        if (state) {
            P1OUT |= bit;
        } else {
            P1OUT &= ~bit;
        }
    } else if (port == 2) {
        if (state) {
            P2OUT |= bit;
        } else {
            P2OUT &= ~bit;
        }
    } else if (port == 3) {
        if (state) {
            P3OUT |= bit;
        } else {
            P3OUT &= ~bit;
        }
    } else if (port == 4) {
        if (state) {
            P4OUT |= bit;
        } else {
            P4OUT &= ~bit;
        }
    } else if (port == 5) {
        if (state) {
            P5OUT |= bit;
        } else {
            P5OUT &= ~bit;
        }
    } else if (port == 6) {
        if (state) {
            P6OUT |= bit;
        } else {
            P6OUT &= ~bit;
        }
    } else if (port == 7) {
        if (state) {
            P7OUT |= bit;
        } else {
            P7OUT &= ~bit;
        }
    } else if (port == 8) {
        if (state) {
            P8OUT |= bit;
        } else {
            P8OUT &= ~bit;
        }
    }
#elif MSP == G2231
    if (port == 1) {
        if (state) {
            P1OUT |= bit;
        } else {
            P1OUT &= ~bit;
        }
    } else if (port == 2) {
        if (state) {
            P2OUT |= bit;
        } else {
            P2OUT &= ~bit;
        }
    }

#endif
}

unsigned char readPortInput(unsigned char port) {
#if MSP == F5529
    if (port == 1) {
        return P1IN;
    } else if (port == 2) {
        return P2IN;
    } else if (port == 3) {
        return P3IN;
    } else if (port == 4) {
        return P4IN;
    } else if (port == 5) {
        return P5IN;
    } else if (port == 6) {
        return P6IN;
    } else if (port == 7) {
        return P7IN;
    } else if (port == 8) {
        return P8IN;
    }

#elif MSP == G2231
    if (port == 1) {
        return P1IN;
    } else if (port == 2) {
        return P2IN;
    }

#endif
}

unsigned char readPinInput(unsigned char port, unsigned char pin) {
#if MSP == F5529
    if (port == 1) {
        return (P1IN >> pin) & 1;
    } else if (port == 2) {
        return (P2IN >> pin) & 1;
    } else if (port == 3) {
        return (P3IN >> pin) & 1;
    } else if (port == 4) {
        return (P4IN >> pin) & 1;
    } else if (port == 5) {
        return (P5IN >> pin) & 1;
    } else if (port == 6) {
        return (P6IN >> pin) & 1;
    } else if (port == 7) {
        return (P7IN >> pin) & 1;
    } else if (port == 8) {
        return (P8IN >> pin) & 1;
    }

#elif MSP == G2231
    if (port == 1) {
        return (P1IN >> pin) & 1;
    } else if (port == 2) {
        return (P2IN >> pin) & 1;
    }

#endif
}

void enableHighToLowInterrupt(unsigned char port, unsigned char pin) {
    unsigned char bit = 1 << pin;
    if (port == 1) {
        P1IE |= bit;
        P1IES |= bit;
    } else if (port == 2) {
        P2IE |= bit;
        P2IES |= bit;
    }
}

void enableLowToHighInterrupt(unsigned char port, unsigned char pin) {
    unsigned char bit = 1 << pin;
    if (port == 1) {
        P1IE |= bit;
        P1IES &= ~bit;
    } else if (port == 2) {
        P2IE |= bit;
        P2IES &= ~bit;
    }
}

void setISR(unsigned char port, void (*isr)()) {
    if (port == 1) {
        port_1_isr = isr;
    } else if (port == 2) {
        port_2_isr = isr;
    }
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1_ISR(void) {
    port_1_isr();

}

#pragma vector=PORT2_VECTOR
__interrupt void Port_2_ISR(void) {
    port_2_isr();
}
#endif /* INCLUDES_SHERWINS_MSP430_LIB_H_ */
