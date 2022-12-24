#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

int main()
 { 
    unsigned char i;
    DDRB  = 0xFF;
    for (i = 0; i <= 255; i++)
       PORTB  = i;
   return 0;
 }
