#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include<util/delay.h>

#define RS 0
#define RW 1
#define EN 2

unsigned int count=0,val;

void LcdCommand (unsigned char cmd)
{
   PORTC = cmd;
   PORTB &= ~(1<<RS);
   PORTB &= ~(1<<RW);
   PORTB |= (1<<EN);
   _delay_ms(10);
   PORTB &= ~(1<<EN);
   _delay_ms(100);
}

void LcdData (unsigned char data)
{
   PORTC = data;
   PORTB |=(1<<RS);
   PORTB &= ~(1<<RW);
   PORTB |= (1<<EN);
   _delay_ms(10);
   PORTB &= ~(1<<EN);
   _delay_ms(100);
}
void Lcd_init()
{
   DDRC = 0xff;
   DDRB = 0xff;
   _delay_ms(1);
   LcdCommand(0x38);
   LcdCommand(0x0E);
   LcdCommand(0x06);
   LcdCommand(0x01);
   _delay_ms(100);
}  

void LcdPrint(unsigned char *str)
{
   unsigned char i=0;
   while(str[i] !=0)
   {
      LcdData (str[i]);
      i++;
   }
}  

ISR(ADC_vect)
{
	 val = ADCL;
	 val = (ADCH<<8) | val;
	 LcdCommand (0x88);
	 LcdData (0x30+(val/1000));
	 LcdData (0x30+((val/100)%10));
	 LcdData (0x30+((val/10)%10));
	 LcdData (0x30+(val%10));
	 
	 ADCSRA |= (1<<ADSC);
}

ISR (INT0_vect)
 {
	 count++;
	 LcdCommand (0x89);		
	 LcdData (0x30+(count/1000));		
	 LcdData (0x30+((count/100)%10));
	 LcdData (0x30+((count/10)%10));
	 LcdData (0x30+(count%10));
 }

int main()
 { 
	 unsigned int val;
	Lcd_init(); 
	 DDRA = 0;
	 ADCSRA = 0x87;
	 ADMUX = 0xC0;
	 LcdCommand (0x80);
	 LcdPrint ("Temp =        C");
	 while(1)
	 {
	       ADCSRA |= (1<<ADSC);
	    
	       while((ADCSRA & (1<<ADIF)) ==0);
	       val =ADCL;
	       val = (ADCH << 8) | val;
	       val = val * (0.0025/0.01);
	       LcdCommand (0x88);
	       LcdData (0x30+((val/1000)));
	       LcdData (0x30+((val/100)%10));
	       LcdData (0x30+(val/10)%10);
	       LcdData (0x30+(val%10));
	 }
   return 0;
 }
