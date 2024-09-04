/* 
  하드웨어 설계
  - SW는 Active LOW
  - LED는 Active LOW
*/

const int ledPin = 3;
const int buttonPin = 2;
int led_flag = 0;   // 0:OFF, 1:ON

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // LED를 끄고 시작
  digitalWrite(ledPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonInput = digitalRead(buttonPin);

  if(buttonInput == LOW){
    if(led_flag == 0){      // 꺼져 있으면 키고
      digitalWrite(ledPin, LOW);
      led_flag = 1;
    }
    else{                   // 켜져 있으면 끄고
      digitalWrite(ledPin, HIGH);
      led_flag = 0;
    }
    delay(300);
  }
}
