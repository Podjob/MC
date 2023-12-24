#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main() {
  DDRB &= ~(1 << PB0);
  PORTB |= (1 << PB0);
  DDRD = 0b00000001;
  PORTD = 0b000000000;
  uint8_t i = 0;

  while (1) {
    if (i == 0) {
      if ((PINB & (1 << PB0)) == 0) {
        _delay_ms(10);
        if ((PINB & (1 << PB0)) == 1) {
          PORTD |= (1 << PD0);
          i++;
        }
      }
    } else if (i == 1) {
      if ((PINB & (1 << PB0)) == 0) {
        _delay_ms(10);
        if ((PINB & (1 << PB0)) == 1) {
          while ((PINB & (1 << PB0)) == 1) {
            PORTD &= ~(1 << PD0);

            for (int j = 0; j < 10; j++) {
              if ((PINB & (1 << PB0)) == 0) {
                i++;
                break;
              }
              _delay_ms(50);
            }

            PORTD |= (1 << PD0);

            for (int j = 0; j < 10; j++) {
              if ((PINB & (1 << PB0)) == 0) {
                i++;
                break;
              }
              _delay_ms(50);
            }
          }
        }
      }
    } else if (i == 2) {
      if ((PINB & (1 << PB0)) == 0) {
        _delay_ms(10);
        if ((PINB & (1 << PB0)) == 1) {
          PORTD &= ~(1 << PD0);
          i = 0;
        }
      }
    }
  }
}
