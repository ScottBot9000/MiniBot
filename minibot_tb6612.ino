// This is the library for the TB6612 that contains the class Motor and all the
// functions
#include <SparkFun_TB6612.h>

// Pins for all inputs, keep in mind the PWM defines must be on PWM pins
// the default pins listed are the ones used on the Redbot (ROB-12097) with
// the exception of STBY which the Redbot controls with a physical switch
#define AIN1 2
#define BIN1 7
#define AIN2 4
#define BIN2 8
#define PWMA 5
#define PWMB 6
#define STBY 9

// these constants are used to allow you to make your motor configuration 
// line up with function names like forward.  Value can be 1 or -1
const int offsetA = 1;
const int offsetB = 1;

// Initializing motors.  The library will allow you to initialize as many
// motors as you have memory for.  If you are using functions like forward
// that take 2 motors as arguements you can either write new functions or
// call the function more than once.
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

void setup() {

  pinMode(3, INPUT);
  pinMode(10, INPUT);
  
  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(9600);

}

void loop() {

  int ch1 = pulseIn(3, HIGH, 250000);
  int ch2 = pulseIn(10, HIGH, 250000);
  //Serial.print("Channel 1:");
  //Serial.println(ch1);

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      
  int ch1_speed = map(constrain(ch1,1000,2000),1000,2000,-255,255);
  int ch2_speed = map(constrain(ch2,1000,2000),1000,2000,-255,255);

  if (abs(ch1_speed)>10) {
  motor1.drive(ch1_speed);
  }
  else {
  motor1.brake();
  }
  
  if (abs(ch2_speed)>10) {
  motor2.drive(ch2_speed);
  }
  else {
  motor2.brake();
  }
  
}
