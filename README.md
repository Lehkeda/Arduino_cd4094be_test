## Arduino CD4094BE CMOS 8-Stage Shift-and-Store Bus Register

  ### Wiring
  | Pin Name |     pin No (IC)  |  Pin No (Microcontroller)  |
  | :------------: | :------------: | :------------: |
  | Clock | 3 | 8 |
  | Data| 2 | 7 |
  | Output enable | 15 | 6 |
  | Strobe | 1 | +5v |
  | VDD |16| +5v |
  | VSS | 8 | GND |
  | D1->D8 (O/P | 4..7, 1 4..11  | (Connected to LEDs) |
  | Qs, Qs`(NC) | 9, 10 | (Cascadeing more ICs) |
  
 ### PS
  - I will always set Strobe pin HIGH by connecting it 
   directly to 5v so the register always moves
   the data to storage register. Becuase that's 
   what I want in most cases in order to make this
   IC work properly
   
  - Connect negative - terminal of the LEDs to GND
   and positive + terminal to output of the IC
