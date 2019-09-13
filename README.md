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

**Upload a video of your working rotary encoder here.**


## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**
 
**b. What song is playing?**


## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**

**b. Post a link to the completed lab report your class hub GitHub repo.**
