#define NbLed 24

uint32_t DataValue = 0b010101010101010101010101;

const uint16_t LATCHPIN = 3;
const uint16_t CLKPIN = 4;
const uint16_t SRDATAPIN = 2;

void setup() {
  DDRD = PORTD | 0b00011100;
  PORTD = PORTD & (~0b000010000);
  PORTD = PORTD & (~0b000010000);
}

void loop() {
  LedUpdate(DataValue, NbLed);
}

void LedUpdate(uint32_t Data, uint16_t NbDeLed) {
  uint32_t mask = 1;
  for (int i = 0; i < NbDeLed; i++) {
    uint32_t Treat = Data & mask;
    for (int j = 0; j < NbDeLed; j++) {
      bool Value =  (Treat >> j) & 1;
      if (Value) {
        PORTD = PORTD | 0b00000100;
      } else {
        PORTD = PORTD & (~0b000000100);
      }
      PORTD = PORTD | 0b00010000;
      PORTD = PORTD & (~0b000010000);
    }
    PORTD = PORTD | 0b00001000;
    PORTD = PORTD & (~0b000010000);
    mask = mask << 1;
  }
}
