#include <TimerOne.h>

const int SERVO = 10;

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize(20000);
  Timer1.pwm(SERVO, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 0도
  Timer1.setPwmDuty(SERVO, 27);
  delay(500);
  // 90도
  Timer1.setPwmDuty(SERVO, 77);
  delay(500);
  // 180도
  Timer1.setPwmDuty(SERVO, 127);
  delay(500);
}
