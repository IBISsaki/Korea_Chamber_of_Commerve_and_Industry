#include <TimerOne.h>

const int LED = 10;

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize();
  Timer1.pwm(LED, 0);

  Timer1.setPeriod(1000000);    // 1Hz
  Timer1.setPwmDuty(LED, 511);  // 0~1023
}

void loop() {
  // put your main code here, to run repeatedly:

}
