#include <msp430g2533.h>//<msp430.h>                //<msp430g2533.h>

#define RED BIT0
#define GREEN BIT6

/**
 * blink.c
 */
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;       // stop watchdog timer
    P1DIR |= RED + GREEN;           // configure P1.0 and _1.6 as output

    P1OUT |= RED;                   //Inititally turn red ON
    P1OUT &= ~GREEN;                //Initially turn green off
    volatile unsigned int i;        // volatile to prevent optimization

    while(1)
    {

        for(i=6000; i>0; i--);     // delay
        P1OUT ^= (RED+GREEN);               // toggle P1.0
    }
}
