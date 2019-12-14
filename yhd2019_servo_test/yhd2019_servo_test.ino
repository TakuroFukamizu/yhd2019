#include <Servo.h>

#define BTN_A 7
//#define BTN_B 13

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
bool dir = true;

void setup() {
  myservo.attach(9);

  pinMode(BTN_A, INPUT); 
//  pinMode(BTN_B, INPUT); 
}

void loop() {
  if (digitalRead(BTN_A)) { // low = turn on
    dir = !dir;
    if (dir) {
      for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(2);                       // waits 15ms for the servo to reach the position
      }
    } else {
      for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(2);                       // waits 15ms for the servo to reach the position
      }
    }
  }
}
