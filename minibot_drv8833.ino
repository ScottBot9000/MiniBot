
#include <DRV8833.h>

// Create an instance of the DRV8833:
DRV8833 driver = DRV8833();

// Pin numbers. Replace with your own!
// For this example sketch, these pin numbers MUST be PWM.
// Attach the Arduino's pin numbers below to the
// Ain1, Ain2, Bin1, and Bin2 DRV8833 pins.
const int inputA1 = 5, inputA2 = 6, inputB1 = 9, inputB2 = 10;

const int min_speed = 30;

void setup() {

  pinMode(3, INPUT);
  pinMode(11, INPUT);
  
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Attach the motors to the input pins:
  driver.attachMotorA(inputA1, inputA2);
  driver.attachMotorB(inputB1, inputB2);
  
  //Serial.begin(9600);

}

void loop() {

  int ch1 = pulseIn(3, HIGH, 250000);
  int ch2 = pulseIn(11, HIGH, 250000);
  //Serial.print("Channel 1:");
  //Serial.println(ch1);

  //digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(100);                       
  //digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      
  int ch1_speed = map(constrain(ch1,1000,2000),1000,2000,-255,255);
  int ch2_speed = map(constrain(ch2,1000,2000),1000,2000,-255,255);

  if (ch1_speed > min_speed) {
    driver.motorAForward(ch1_speed);
  } 
  else if (ch1_speed < -min_speed) {
    driver.motorAReverse(-ch1_speed);
  }
  else {
  driver.motorAStop();
  }
  
  if (ch2_speed > min_speed) {
    driver.motorBForward(ch2_speed);
  } 
  else if (ch2_speed < -min_speed) {
    driver.motorBReverse(-ch2_speed);
  }
  else {
  driver.motorBStop();
  }
  
}
