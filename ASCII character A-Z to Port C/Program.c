#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/delay.h>

int main()
 { 
    unsigned char myList[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    unsigned char i;
    DDRC = 0xFF;
    for (i = 0; i <26; i++)
    {
	 PORTC  = myList[i];
	 _delay_ms(500);
    }
    while(1);
    return 0;
 }
