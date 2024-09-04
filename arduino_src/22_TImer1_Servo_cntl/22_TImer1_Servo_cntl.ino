#include <TimerOne.h>

const int SERVO = 10;
const int buttonPin = 2;
int servo_flag = 0;

void buttonPressed()
{
  if(servo_flag == 0)
  {
    Timer1.initialize(20000);
    Timer1.pwm(SERVO, 0);
    servo_flag = 1;
  }
  else
  {
    Timer1.disablePwm(SERVO);
    servo_flag = 0;
  }
}

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize(20000);
  Timer1.pwm(SERVO, 0);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed, RISING);

 // 0~1023
}

void loop() {
  // put your main code here, to run repeatedly:
  if(servo_flag == 1)
  {
    // 0도
    Timer1.setPwmDuty(SERVO, 27);
    delay(500);
    // 90도
    Timer1.setPwmDuty(SERVO, 77);
    delay(500);
    // 180도
    Timer1.setPwmDuty(SERVO, 128);
    delay(500);
  }
 
  // 2번핀 스위치 한번 누르면 움직이고, 한번 더 누르면 멈춤, active high, 인터럽트 이용 
}
