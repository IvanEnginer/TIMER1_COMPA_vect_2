#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
int number = 0;

ISR(TIMER1_COMPA_vect)
{
	_delay_ms(500);
	number++;
	switch(number)
		{
			case 0:{PORTB=0x00; break;}
			case 1:{PORTB=0x01; break;}
			case 2:{PORTB=0x02; break;}
			case 3:{PORTB=0x04; break;}
			case 4:{PORTB=0x08; break;}
			case 5:{PORTB=0x10; break;}
			case 6:{PORTB=0x20; break;}
			case 7:{PORTB=0x40; break;}
			case 8:{PORTB=0x80; break;}
			case 9:{PORTB=0x100; break;}
		}
		if (number == 10)
		{
			number=0;
		}
	TCNT1H=0x00;
	TCNT1L=0x00;
}

int main(void)
{

	PORTB=0x00;
	DDRB=0xFF;
	TCCR1A=0x00;
	TCCR1B=0x02;
	TCNT1H=0x00;
	TCNT1L=0x00;
	ICR1H=0x00;
	ICR1L=0x00;
	OCR1AH=0xFF;
	OCR1AL=0xFF;
	TIMSK=0x10;
	sei();
	
    while(1)
    {
        
    }
}