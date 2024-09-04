#include <Servo.h>

const int SERVO = 10;
Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(SERVO,544,2500);
  servo.write(0);

  delay(1000);

  for(int cnt=0; cnt<3; cnt++){
    servo.write(0);
    delay(100);
    servo.write(180);
    delay(100);
  }

  servo.detach();
}

void loop() {
  // put your main code here, to run repeatedly:


}
