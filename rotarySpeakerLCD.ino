/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

#define ENC_A 6 //these need to be digital input pins
#define ENC_B 7
#define NOTE_C4  262

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int countdown = 5;
int currtime;
int stage = 0;

void setup() {
  
  // Setup lCD
  lcd.begin(16, 2);
  lcd.print("Countdown");

  /* Setup rotary encoders */
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
  Serial.begin (9600);
  Serial.println("Start");
}

void loop() {
  
  switch(stage) {
    
    // Countdown not started
    case 0:
      lcd.setCursor(0, 0);
      lcd.print("Turn Rotary");

      // Check if rotary turned
      static unsigned int counter4x = 0;      //the SparkFun encoders jump by 4 states from detent to detent
      static unsigned int counter = 0;
      static unsigned int prevCounter = 0;
      int tmpdata;
      tmpdata = read_encoder();
      if( tmpdata) {
        counter4x += tmpdata;
        counter = counter4x/4;
        if (prevCounter != counter){
          lcd.clear();
          currtime = millis()/1000;
          stage = 1;
        }
        prevCounter = counter;
      }
      break;

    // Rotary twisted
    case 1:
    
      // Countdown
      int timer = countdown - (millis()/1000 - currtime);
      if (timer > 0) {
        lcd.setCursor(0, 0);
        lcd.print("Countdown");
        lcd.setCursor(0, 1);
        lcd.print(timer);
      }
      // Reset Loop
      else if (timer < -2) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Done!"); 
        delay(10);
        stage = 0;
      } 
      // Countdown Complete
      else {
        // Play C4, middle C
        tone(8, NOTE_C4, 1000);
        lcd.print("zzzz");
      }
      
    } // switchend

}

/* returns change in encoder state (-1,0,1) */
int read_encoder()
{
  static int enc_states[] = {
    0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0  };
  static byte ABab = 0;
  ABab *= 4;                   //shift the old values over 2 bits
  ABab = ABab%16;      //keeps only bits 0-3
  ABab += 2*digitalRead(ENC_A)+digitalRead(ENC_B); //adds enc_a and enc_b values to bits 1 and 0
  return ( enc_states[ABab]);
 
 
}
