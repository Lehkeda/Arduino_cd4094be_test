/*
 * -------------------------------------------------------------------
 *       CD4094BE CMOS 8-Stage Shift-and-Store Bus Register
 * -------------------------------------------------------------------
 * Author: Hesham El-sewify (LehKeda) 
 * Last edit: 11th of March 2019
 * 
 * Wiring:
 * /---------------------------------------------------------------\
 * | Pin Name      |     Pin No (IC)  |  Pin No (Microcontroller)  |
 * ----------------------------------------------------------------|
 * | Clock         |         3        |           8                |
 * | Data          |         2        |           7                |
 * | Output enable |         15       |           6                |
 * | Strobe        |         1        |          +5v               |
 * | VDD           |         16       |          +5v               |
 * | VSS           |         8        |          GND               |
 * | D1->D8 (O/P   |    4..7, 14..11  |    (Connected to LEDs)     |
 * | Qs, Qs`(NC)   |        9, 10     |   (Cascadeing more ICs)    |
 * \---------------------------------------------------------------/
 * PS:
 * -I'll always set Strobe pin HIGH by connecting it 
 *  directly to 5v so the register always moves
 *  the data to storage register. Becuase that's 
 *  what I want in most cases in order to make this
 *  IC work properly
 *  
 * -Connect negative - terminal of the LEDs to GND
 *  and positive + terminal to output of the IC
 */
int output_enable_pin= 6;
int data_pin= 7;
int clk_pin= 8;
  
// the bits you want to send
char effect1[9]= {
  0b10000000, 0b01000000, 0b00100000, 0b00010000,
  0b00001000, 0b00000100, 0b00000010, 0b00000001, 0};
  
char effect2[10]= {
  0b11111111, 0b01111110, 0b00111100, 0b00011000,
  0b00111100, 0b01111110, 0b11111111, 0b00000000, 0};
  
char effect3[9]= {
  0b10000001, 0b11000011, 0b11100111, 0b11111111,
  0b11100111, 0b11000011, 0b10000001, 0b00000000, 0};
  
void setup() {
  pinMode(output_enable_pin, OUTPUT);
  pinMode(data_pin, OUTPUT);
  pinMode(clk_pin, OUTPUT);
}

void loop() {
  for(int i=0; i<5; i++){
    do_effect1();
    do_reverse_effect1();
  }
  turn_off();
  delay(500);  

  for(int i=0; i<5; i++){
    do_effect2();
  }
  turn_off();
  delay(500);
  
  for(int i=0; i<5; i++){
    do_effect3();
  }
  turn_off();
  delay(500);
}

void do_effect1() {
  for(int i=0; effect1[i]; i++){
    // turn off the output so the pins don't light up
    // while you're shifting bits:
    digitalWrite(output_enable_pin, LOW);

    // shift the bits out:
    // In order to get the desired shape or bits order
    // I use LSBFIRST becuaes the first bit sent gets 
    // stored in Q7 in the register and last bit in Q1.
    shiftOut(data_pin, clk_pin, LSBFIRST, effect1[i]);
  
    // turn on the output so the LEDs can light up:
    digitalWrite(output_enable_pin, HIGH);

    delay(100);
  }
}

void do_reverse_effect1() {
  for(int i=0; effect1[i]; i++){
    // turn off the output so the pins don't light up
    // while you're shifting bits:
    digitalWrite(output_enable_pin, LOW);

    shiftOut(data_pin, clk_pin, MSBFIRST, effect1[i]);
  
    // turn on the output so the LEDs can light up:
    digitalWrite(output_enable_pin, HIGH);

    delay(100);
  }
}

void do_effect2(){
  for(int i=0; effect2[i]; i++){
    // turn off the output so the pins don't light up
    // while you're shifting bits:
    digitalWrite(output_enable_pin, LOW);

    // shift the bits out:
    // In order to get the desired shape or bits order
    // I use LSBFIRST becuaes the first bit sent gets 
    // stored in Q7 in the register and last bit in Q1.
    shiftOut(data_pin, clk_pin, LSBFIRST, effect2[i]);
  
    // turn on the output so the LEDs can light up:
    digitalWrite(output_enable_pin, HIGH);

    delay(100);
  }
}

void do_effect3(){
  for(int i=0; effect3[i]; i++){
    // turn off the output so the pins don't light up
    // while you're shifting bits:
    digitalWrite(output_enable_pin, LOW);

    // shift the bits out:
    // In order to get the desired shape or bits order
    // I use LSBFIRST becuaes the first bit sent gets 
    // stored in Q7 in the register and last bit in Q1.
    shiftOut(data_pin, clk_pin, LSBFIRST, effect3[i]);
  
    // turn on the output so the LEDs can light up:
    digitalWrite(output_enable_pin, HIGH);

    delay(100);
  }
}

void turn_off(){
    // turn off the output so the pins don't light up
    // while you're shifting bits:
    digitalWrite(output_enable_pin, LOW);

    // shift the bits out:
    // In order to get the desired shape or bits order
    // I use LSBFIRST becuaes the first bit sent gets 
    // stored in Q7 in the register and last bit in Q1.
    shiftOut(data_pin, clk_pin, LSBFIRST, 0b00000000);
  
    // turn on the output so the LEDs can light up:
    digitalWrite(output_enable_pin, HIGH);
}
