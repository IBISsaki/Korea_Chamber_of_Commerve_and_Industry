/* 
  하드웨어 설계
  - SW는 Active HIGH
  - LED는 Active HIGH
*/

const int ledPin_1 = 5;
const int buttonPin_1 = 4;
int led_flag_1 = 0;  // 0:OFF, 1:ON
int cur_btn_val_1 = LOW, pre_btn_val_1 = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(buttonPin_1, INPUT);
  pinMode(ledPin_1, OUTPUT);

  // LED를 끄고 시작
  digitalWrite(ledPin_1, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 현재값 저장
  cur_btn_val_1 = digitalRead(buttonPin_1);

  // 스위치 동작에 따른 상태값 변경
  if (pre_btn_val_1 == LOW && cur_btn_val_1 == HIGH) {
    if (led_flag_1 == 0) {  // 꺼져 있으면 키고
      led_flag_1 = 1;
    } else {  // 켜져 있으면 끄고
      led_flag_1 = 0;
    }
  }

  // 상태값에 따른 동작 구현
  if(led_flag_1 == 1){
    digitalWrite(ledPin_1, HIGH);
    delay(100);
    digitalWrite(ledPin_1, LOW);
    delay(100);
  }

  // 이전값 갱신
  pre_btn_val_1 = cur_btn_val_1;
}
