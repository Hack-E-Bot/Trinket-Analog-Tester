/*
TrinketKeyboard example
For Trinket by Adafruit Industries
*/

#include <TrinketKeyboard.h>

#define PIN_BUTTON_CAPITAL_A 0


void setup()
{
  // button pins as inputs
  analogReference(INTERNAL1V);
  
  pinMode(PIN_BUTTON_CAPITAL_A, INPUT);
  //pinMode(2, INPUT);
  //pinMode(4, INPUT);
  //digitalWrite(2, LOW);
  //digitalWrite(4, LOW);
  // setting input pins to high means turning on internal pull-up resistors
  digitalWrite(PIN_BUTTON_CAPITAL_A, HIGH);
  // remember, the buttons are active-low, they read LOW when they are not pressed

  // start USB stuff
  TrinketKeyboard.begin();
  
}

void loop()
{
  TrinketKeyboard.poll();
  int photocellReading = analogRead(3);

  // the poll function must be called at least once every 10 ms
  // or cause a keystroke
  // if it is not, then the computer may think that the device
  // has stopped working, and give errors

  if (digitalRead(PIN_BUTTON_CAPITAL_A) == LOW)
  {
    // type out a string using the Print class
    TrinketKeyboard.print(" A=");
    TrinketKeyboard.print(photocellReading);     // the raw analog reading
  }
}
