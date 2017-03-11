//*** 1- Documentation
//This program is used to control a robot car using a app that communicates with Arduino trough a bluetooth module

#include <AFMotor.h>
#include <Servo.h>
//creates two objects to control the terminal 3 and 4 of motor shield
AF_DCMotor motor1(1);
Servo myServo;
int angle = 11;
char command;

void setup()
{
  myServo.attach(10);
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Stop(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.
    //Serial.println(command);
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
    }
  }
}

void forward()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
}

void back()
{
  motor1.setSpeed(255);
  motor1.run(BACKWARD); //rotate the motor counterclockwise
}

void left()
{
  for (angle = 0; angle < 160; angle += 10)
  {
    myServo.write(angle);
  }
}

void right()
{
  for (angle = 160; angle >= 30; angle -= 10) {
    myServo.write(angle);
  }
}

void Stop()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE); //turn motor1 off
}