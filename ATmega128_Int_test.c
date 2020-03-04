#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>        
#include <util/delay.h>



ISR(INT0_vect)  
{

      PORTA=0X00;
   _delay_ms(3000);
	PORTA=0X01;
   _delay_ms(3000);
         PORTA=0X00;
   _delay_ms(3000);
}

int main(void)
{ 
 DDRA=0XFF;
 DDRD = 0xFE;
 //SREG |= 0x80;  //status register Bit 7 defined for global Interrupt                
 EIMSK = 0x01;	/*
 When an INT7 . INT0 bit is written to one and the I-bit in the Status Register (SREG) is set
(one), the corresponding external pin interrupt is enabled. The Interrupt Sense Control bits in the
External Interrupt Control Registers . EICRA and EICRB . defines whether the external interrupt
is activated on rising or falling edge or level sensed. Activity on any of these pins will trigger
an interrupt request even if the pin is enabled as an output. This provides a way of generating a
software interrupt.
*/
 EICRA=0X03;	//Rising Enge Trigger
/*
0 0 The low level of INTn generates an interrupt request.
0 1 Reserved
1 0 The falling edge of INTn generates asynchronously an interrupt request.
1 1 The rising edge of INTn generates asynchronously an interrupt request.
n = 3, 2, 1or 0.
When changing the ISCn1/ISCn0 bits, the interrupt must be disabled by clearing its Interrupt
Enable bit in the EIMSK Register. Otherwise an interrupt can occur when the bits are changed.
*/
 sei();       //sei()는 reset해도 메인으로 빠지고 sreg는 reset시 인터럽트를 거치고 시작하는듯                
 while(1){
  PORTA=0XFF;                 
  }
 }
