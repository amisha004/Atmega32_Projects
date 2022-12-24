#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>
#define RS 0
#define RW 1
#define EN 2
#define  KEY_PRT  PORTD
#define  KEY_DDR  DDRD
#define  KEY_PIN  PIND

unsigned char keypad[4][4] = {{'7','8','9','/'}, {'4','5','6','*'}, {'1','2','3','-'}, {'o','0','=','+'}};

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
    unsigned char  col,row,key;
   DDRD = 0XFF;
   KEY_DDR = 0X0F;
   KEY_PRT = 0XFF;
   Lcd_init();
   LcdPrint("KEY:   ");
   
   while (1)
   {
      PORTD=0XF0;
      while((PIND &0XF0)!=0XF0);
      while((PIND &0XF0)==0XF0);
      col = PIND &0XF0;
	 _delay_ms(20);
      while((PIND &0XF0)!=0XF0)
	{
	 PORTD = 0XFE;		     
	       if((PIND & 0XF0)!=0XF0)
	       {
	       row =0;
	       break;
	       }
	       PORTD = 0XFD;
	       if((PIND & 0XF0)!=0XF0)
	       {
	       row =1;
	       break;
	       }
	       PORTD = 0XFB;
	       if((PIND & 0XF0)!=0XF0)
	       {
	       row =2;
	       break;
	       }
	       PORTD = 0XF7;
	       if((PIND & 0XF0)!=0XF0)
	       {
	       row =3;
	       break;
	       }
	  }
	       if(col==0XE0)
		  key = keypad[row][0];

	       else if(col==0XD0)
		  key = keypad[row][1];

	       else if(col==0XB0)
		  key = keypad[row][2];

	       else 
		  key = keypad[row][3];    
		  LcdCommand(0x85);
		  LcdData(key);
   }
   return 0;
 }
