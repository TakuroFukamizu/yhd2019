#include <M5Stack.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(&Wire, 0x72);
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  M5.Lcd.setBrightness(128);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);
  
  Serial.println("PCA9685");
  M5.Lcd.println("PCA9685");
 
  pwm1.begin();
  pwm1.setPWMFreq(1600);  // This is the maximum PWM frequency
 
  pwm2.begin();
  pwm2.setPWMFreq(1600);  // This is the maximum PWM frequency
}

void loop() {
}
