#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/delay.h>

int main()
 {
    unsigned char num[]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f}; 
    char i,d1,d2;
    DDRD=0xFF;
    DDRB |= ((1<<0)|(1<<1));
    DDRA=0;
    PORTA =0x00;
   
   while (1)
   {
      if ((PINA  & 0x01)==0)
      {
      for (i=0; i<100; i++)
      {
	 d1=i/10;
	 d2=i%10;
	 PORTD=num[d1];
	 PORTB |= (1<<0);
	 _delay_ms(50);
	 PORTB &= ~(1<<0);
	 
	 PORTD=num[d2];
	 PORTB |= (1<<1);
	 _delay_ms(50);
	 PORTB &= ~(1<<1);
	 while ((PINA  & 0x01)==0);
      }
   }

      else
      {
      if ((PINA  & 0x02)==0)
      {
      for (i=99; i>0; i--)
      {
	 d1=i/10;
	 d2=i%10;
	 PORTD=num[d1];
	 PORTB |= (1<<0);
	 _delay_ms(50);
	 PORTB &= ~(1<<0);
	 
	 PORTD=num[d2];
	 PORTB |= (1<<1);
	 _delay_ms(50);
	 PORTB &= ~(1<<1);
	 while ((PINA  & 0x02)==0);
      }
      }
   }
}
   return 0;
}
