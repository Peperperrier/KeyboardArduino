/** ****************************************************************************
* \file        KeyboardArduino
* \author      Anthony PERRIER
* \brief       keyboard emultor based on arduino built with 32u4µC
*
* \date        Created on 2020 July
*
* \details     Keyboard 6 buttons
*               allow to use : F2, F5, F6, F11, F12, ENTER
*              HOW TO TEST : 
*               https://www.keyboardtester.com/tester.html
* -----------------------------------------------------------------------------
* "THE BEER-WARE LICENSE" (Revision 42):
* As long as you retain this notice you can do whatever you want with this stuff. 
* If we meet some day, and you think this stuff is worth it, 
* you can buy me a beer in return.
*
* modified by Anthony PERRIER
*
* -----------------------------------------------------------------------------
**************************************************************************** */
#include <Keyboard.h>

// set pin numbers for the five buttons:
const int    touch_1          = 1;
volatile int state_1          = LOW; // To make sure variables shared between an ISR
const int    touch_2          = 0;
volatile int state_2          = LOW; // To make sure variables shared between an ISR
const int    touch_3          = 2;
volatile int state_3          = LOW; // To make sure variables shared between an ISR
const int    touch_4          = 14;
volatile int state_4          = LOW; // To make sure variables shared between an ISR
const int    touch_5          = 16;
volatile int state_5          = LOW; // To make sure variables shared between an ISR
const int    touch_6          = 10;
volatile int state_6          = LOW; // To make sure variables shared between an ISR


void setup() {
  // put your setup code here, to run once:
  pinMode(touch_1,       INPUT_PULLUP);
  pinMode(touch_2,       INPUT_PULLUP);
  pinMode(touch_3,       INPUT_PULLUP); 
  pinMode(touch_4,       INPUT_PULLUP);
  pinMode(touch_5,       INPUT_PULLUP);
  pinMode(touch_6,       INPUT_PULLUP);
  // Serial.begin(9600);
  // initialize mouse control:
  Keyboard.begin();
}

/*  
 * Because only 5 pins are available with ISR, we manage buttons manually, with IO read + state saved
 * list of available key = https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
 * Software create for Pro Micro board (µC = 32u4-based)
 * pins available with interrupt = 0, 1, 2, 3, 7 (cf.  https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/)
 * 
 * HOW TO TEST
*/
void loop() {

  if ((digitalRead(touch_1) == LOW) && (state_1 != LOW))  Keyboard.write(KEY_F2);            //check current and previous state + check current = LOW
  state_1 = digitalRead(touch_1);                                                            //Save previous state
  if ((digitalRead(touch_2) == LOW) && (state_2 != LOW))  Keyboard.write(KEY_F5);            //check current and previous state + check current = LOW
  state_2 = digitalRead(touch_2);                                                            //Save previous state
  if ((digitalRead(touch_3) == LOW) && (state_3 != LOW))  Keyboard.write(KEY_F6);            //check current and previous state + check current = LOW
  state_3 = digitalRead(touch_3);                                                            //Save previous state
  if ((digitalRead(touch_4) == LOW) && (state_4 != LOW))  Keyboard.write(KEY_F11);           //check current and previous state + check current = LOW
  state_4 = digitalRead(touch_4);                                                            //Save previous state
  if ((digitalRead(touch_5) == LOW) && (state_5 != LOW))  Keyboard.write(KEY_F12);           //check current and previous state + check current = LOW
  state_5 = digitalRead(touch_5);                                                            //Save previous state
  if ((digitalRead(touch_6) == LOW) && (state_6 != LOW))  Keyboard.write(KEY_RETURN);        //check current and previous state + check current = LOW
  state_6 = digitalRead(touch_6);                                                            //Save previous state
  
}
