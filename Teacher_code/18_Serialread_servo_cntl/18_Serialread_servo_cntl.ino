#include <Servo.h>

const int SERVO = 10;
Servo servo;
int degree= 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  servo.attach(SERVO,544,2500);
  servo.write(degree);

  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 2. C++언어 스타일 코딩(Serial.readString함수 이용)
  if(Serial.available()){
    String rx_data = Serial.readString();
    Serial.print(rx_data);
    rx_data.trim();   // \n,\r을 제거
    degree = rx_data.toInt();
    if(degree>=0 && degree <= 180){
      servo.write(degree);
    }
  }
}
