#include <AFMotor.h>

AF_Stepper motor(200, 1); //control 1 stepper motor(steps per revolution = 200) connected to port 1

void setup() {
  Serial.begin(9600); //baud rate set in java gui
  motor.setSpeed(50); //fixed speed for now
  motor.release();
  delay(1000);
}

void loop() {
  String input;
  int stepMove;
  int Step;
  //Read in the characters being sent from Java.
  input = Serial.readString();
  stepMove = input.toInt();
  Step = abs(stepMove);
  //Serial.println(stepMove);
  //Serial.println(Step);

  if (stepMove > 0) {
    motor.step(Step, FORWARD, SINGLE);
    motor.release();
  }

  if (stepMove < 0) {
    motor.step(Step, BACKWARD, SINGLE);
    motor.release();
  }

  if (stepMove == 0) {
    motor.release();
  }

}
