#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/delay.h>

int main()
 { 
   DDRA  = 0xFF;
    PORTA = 0xAA;
    unsigned char i;
    for (i=0; i<1000; i++)
    {
       PORTA = ~PORTA;
       _delay_ms (100);
    }
   while (1);
   return 0;
 }
