# Digital Timer
 
Include your responses to the bold questions below. Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

## Part A. Solder your LCD panel
**Take a picture of your soldered panel and add it here!** <br>
![Soldered Panel](https://github.com/zachgitt/IDD-Fa19-Lab2/blob/master/soldered_panel.jpeg)

## Part B. Writing to the LCD
**a. What voltage level do you need to power your display?** <br>
5V is required to power the display.

**b. What voltage level do you need to power the display backlight?** <br>
3V is required to power the backlight.
   
**c. What was one mistake you made when wiring up the display? How did you fix it?** <br>
With precision and good fortune, I made no mistakes!

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?** <br>
Changing lcd.print("Zach") would print my name instead.
 
**e. Include a copy of your Lowly Multimeter code in your lab write-up.**
![Lowly Multimeter](https://github.com/zachgitt/IDD-Fa19-Lab2/blob/master/lowly_multimeter.jpeg)
```
// include the library code:
#include <LiquidCrystal.h>

int sensorPin = A0;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  int sensorValue = analogRead(sensorPin);
  lcd.print(sensorValue); 
}

```

## Part C. Using a time-based digital sensor
**Upload a video of your working rotary encoder here.** <br>
[![Rotary Sensor](https://github.com/zachgitt/IDD-Fa19-Lab2/blob/master/thumbnail.png)](https://youtu.be/vKqY6U2_1ak)

## Part D. Make your Arduino sing!
**a. How would you change the code to make the song play twice as fast?** <br>
The following was the code used to play the song. Changing it from 1000ms to 500ms note duration played the song at twice the speed.
```
/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 500 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
```
 
**b. What song is playing?** <br>
Changing the melody and note durations to the following plays star wars.
```
int melody[] = {
  NOTE_D3,NOTE_D3,NOTE_D3,NOTE_G3,NOTE_D4,NOTE_C4,NOTE_B3,NOTE_A3,NOTE_G4,NOTE_D4, \
  NOTE_C4,NOTE_B3,NOTE_A3,NOTE_G4,NOTE_D4,NOTE_C4,NOTE_B3,NOTE_C4,NOTE_A3,0};
 
int noteDurations[] = {
  10,10,10,2,2,10,10,10,2,4, \
  10,10,10,2,4,10,10,10,2,4};
```

**c. HEY JUDE ** <br>
I wanted to play hey jude on the speaker so I looked up the notes on https://noobnotes.net/hey-jude-the-beatles/ and translated into the arduino pitch notes and estimated the durations per note as saved below.
```
int melody[] = {
  NOTE_C5,NOTE_A4,NOTE_A4,NOTE_C5,NOTE_D5,NOTE_G4, \
  NOTE_G4,NOTE_A4,NOTE_AS4,NOTE_F5,NOTE_F5,NOTE_E5,NOTE_C5,NOTE_D5,NOTE_C5,NOTE_AS4,NOTE_A4, \
  NOTE_C5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_G5,NOTE_F5,NOTE_E5,NOTE_F5,NOTE_D5,NOTE_C5, \
  NOTE_F4,NOTE_G4,NOTE_A4,NOTE_D5,NOTE_C5,NOTE_C5,NOTE_AS4,NOTE_A4,NOTE_E4,NOTE_F4 
  };
 
int noteDurations[] = {
  4,2,8,8,8,1, \
  8,8,8,2,8,8,8,8,6,8,2, \
  8,8,6,8,8,8,8,8,8,2, \
  8,8,8,6,4,8,8,8,8,2};
```
[![Hey Jude](https://github.com/zachgitt/IDD-Fa19-Lab2/blob/master/heyjudethumbnail.png)](https://youtu.be/28Ix02nsFSc)

## Part E. Make your own timer
**a. Make a short video showing how your timer works, and what happens when time is up!** <br>
The [code](https://github.com/zachgitt/IDD-Fa19-Lab2/blob/master/rotarySpeakerLCD.ino) I wrote allows you to interact with the rotary to start the loop:
1. Twist Rotary to Start Countdown
2. Countdown from 5 to 0
3. Buzz on the Speaker and on the LCD
4. Reset After 2 Seconds
[![Rotary Speaker LCD](https://github.com/zachgitt/IDD-Fa19-Lab2/blob/master/rotarySpeakerLCDthumbnail.png)](https://youtu.be/VuWtbvCIDqo)

