#include <avr/io.h>
#include <avr/interrupt.h>        
#include <util/delay.h>



SIGNAL(SIG_INTERRUPT0)  
{
      PORTA=0X00;
   _delay_ms(50000); 
}

int main(void)
{ 
 DDRA=0XFF;
 DDRD = 0xFE;
 SREG |= 0x80;                    
 EIMSK = 0x01;	//
 EICRA=0X03;	//Rising Enge Trigger
                
 sei();                       
 while(1){
  PORTA=0XFF;                 
  }
 }
