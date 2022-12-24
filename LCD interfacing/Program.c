#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/delay.h>
#define RS 0
#define RW 1
#define EN 2
void LcdCommand (unsigned char cmd)
{
   PORTA = cmd;
   PORTB &= ~(1<<RS);
   PORTB &= ~(1<<RW);
   PORTB |= (1<<EN);
   _delay_ms(10);
   PORTB &= ~(1<<EN);
   _delay_ms(100);
}
void LcdData (unsigned char data)
{
   PORTA = data;
   PORTB |=(1<<RS);
   PORTB &= ~(1<<RW);
   PORTB |= (1<<EN);
   _delay_ms(10);
   PORTB &= ~(1<<EN);
   _delay_ms(100);
}
void Lcd_init()
{
   DDRA = 0xff;
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
int main()
 { 
   Lcd_init();
   LcdCommand(0x80);
   LcdPrint ("BVM");
   while (1);
   return 0;
 }
