/*
 * sherwins_lib_io.c
 *
 *  Created on: Apr 27, 2018
 *      Author: Sherwin
 */
#include <sherwins_lib_io.h>

void (*port_1_isr)(void);
void (*port_2_isr)(void);

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

void setPullDownResistor(unsigned char port, unsigned char pin) {
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
    }  else if (port == 8) {
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

void setPullUpResistor(unsigned char port, unsigned char pin) {
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
    }  else if (port == 8) {
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

void writePinHigh(unsigned char port, unsigned char pin) {
    unsigned char bit = 1 << pin;
#if MSP == F5529
    if (port == 1) {
        P1OUT |= bit;
    } else if (port == 2) {
        P2OUT |= bit;
    } else if (port == 3) {
        P3OUT |= bit;
    } else if (port == 4) {
        P4OUT |= bit;
    } else if (port == 5) {
        P5OUT |= bit;
    } else if (port == 6) {
        P6OUT |= bit;
    } else if (port == 7) {
        P7OUT |= bit;
    } else if (port == 8) {
        P8OUT |= bit;
    }

#elif MSP == G2231
    if (port == 1) {
        P1OUT |= bit;
    } else if (port == 2) {
        P2OUT |= bit;
    }

#endif
}

void writePinLow(unsigned char port, unsigned char pin) {
    unsigned char bit = 1 << pin;
#if MSP == F5529
    if (port == 1) {
        P1OUT &= ~bit;
    } else if (port == 2) {
        P2OUT &= ~bit;
    } else if (port == 3) {
        P3OUT &= ~bit;
    } else if (port == 4) {
        P4OUT &= ~bit;
    } else if (port == 5) {
        P5OUT &= ~bit;
    } else if (port == 6) {
        P6OUT &= ~bit;
    } else if (port == 7) {
        P7OUT &= ~bit;
    } else if (port == 8) {
        P8OUT &= ~bit;
    }

#elif MSP == G2231
    if (port == 1) {
        P1OUT &= ~bit;
    } else if (port == 2) {
        P2OUT &= ~bit;
    }

#endif
}

void togglePin(unsigned char port, unsigned char pin) {
    unsigned char bit = 1 << pin;
#if MSP == F5529
    if (port == 1) {
        P1OUT ^= bit;
    } else if (port == 2) {
        P2OUT ^= bit;
    } else if (port == 3) {
        P3OUT ^= bit;
    } else if (port == 4) {
        P4OUT ^= bit;
    } else if (port == 5) {
        P5OUT ^= bit;
    } else if (port == 6) {
        P6OUT ^= bit;
    } else if (port == 7) {
        P7OUT ^= bit;
    } else if (port == 8) {
        P8OUT ^= bit;
    }

#elif MSP == G2231
    if (port == 1) {
        P1OUT ^= bit;
    } else if (port == 2) {
        P2OUT ^= bit;
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
#if MSP == F5529 || MSP == G2231
    if (port == 1) {
        P1IE |= bit;
        P1IES |= bit;
        __enable_interrupt();
    } else if (port == 2) {
        P2IE |= bit;
        P2IES |= bit;
        __enable_interrupt();
    }
#endif
}

void enableLowToHighInterrupt(unsigned char port, unsigned char pin) {
    unsigned char bit = 1 << pin;
#if MSP == F5529 || MSP == G2231
    if (port == 1) {
        P1IE |= bit;
        P1IES &= ~bit;
        __enable_interrupt();
    } else if (port == 2) {
        P2IE |= bit;
        P2IES &= ~bit;
        __enable_interrupt();
    }
#endif
}
void setISR(unsigned char port, void (*isr)(void)) {
#if MSP == F5529 || MSP == G2231
    if (port == 1) {
        port_1_isr = isr;
    } else if (port == 2) {
        port_2_isr = isr;
    }
#endif
}

void resetFlag(unsigned char port, unsigned char pin) {
    unsigned char bit = 1 << pin;
#if MSP == F5529 || MSP == G2231
    if (port == 1) {
        P1IFG &= ~bit;
    } else if (port == 2) {
        P2IFG &= ~bit;
    }

#endif
}

unsigned char getPinAndResetFlag(unsigned char port) {
#if MSP == F5529 || MSP == G2231
    if (port == 1) {
        unsigned int temp = P1IV;
        if (temp == 2) {
            return 0;
        } else if (temp == 4) {
            return 1;
        } else if (temp == 6) {
            return 2;
        } else if (temp == 8) {
            return 3;
        } else if (temp == 10) {
            return 4;
        } else if (temp == 12) {
            return 5;
        } else if (temp == 14) {
            return 6;
        } else if (temp == 16) {
            return 7;
        }
        return 0;
    } else if (port == 2) {
        unsigned int temp = P1IV;
        if (temp == 2) {
            return 0;
        } else if (temp == 4) {
            return 1;
        } else if (temp == 6) {
            return 2;
        } else if (temp == 8) {
            return 3;
        } else if (temp == 10) {
            return 4;
        } else if (temp == 12) {
            return 5;
        } else if (temp == 14) {
            return 6;
        } else if (temp == 16) {
            return 7;
        }
        return 0;
    }

#endif
}

#pragma vector=PORT1_VECTOR
__interrupt void port1ISR(void) {
    port_1_isr();
}

#pragma vector=PORT2_VECTOR
__interrupt void port2ISR(void) {
    port_2_isr();
}
