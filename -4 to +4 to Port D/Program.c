#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/delay.h>

int main()
 { 
      unsigned char x;
      unsigned char y[] = {-4,-3,-2,-1,0,1,2,3,4};
      DDRD = 0xFF;
      while(1)
      {
	 for (x=0; x<9; x++)
	    {
	       PORTD = y[x];
	       _delay_ms(500);
	    }
      }
      return 0;    
 }
