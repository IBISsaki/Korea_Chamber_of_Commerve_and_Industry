/* 
  하드웨어 설계
  - SW1는 Active LOW
  - LED1는 Active LOW
  - SW2는 Active HIGH
  - LED2는 Active HIGH
*/

const int ledPin_1 = 3;
const int buttonPin_1 = 2;
int led_flag_1 = 0;  // 0:OFF, 1:ON
int cur_btn_val_1 = HIGH, pre_btn_val_1 = HIGH;

const int ledPin_2 = 5;
const int buttonPin_2 = 4;
int led_flag_2 = 0;  // 0:OFF, 1:ON
int cur_btn_val_2 = LOW, pre_btn_val_2 = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(buttonPin_1, INPUT);
  pinMode(ledPin_1, OUTPUT);
  pinMode(buttonPin_2, INPUT);
  pinMode(ledPin_2, OUTPUT);

  // LED를 끄고 시작
  digitalWrite(ledPin_1, HIGH);
  digitalWrite(ledPin_2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 현재값 저장
  cur_btn_val_1 = digitalRead(buttonPin_1);
  cur_btn_val_2 = digitalRead(buttonPin_2);

  if (pre_btn_val_1 == HIGH && cur_btn_val_1 == LOW) {
    if (led_flag_1 == 0) {  // 꺼져 있으면 키고
      digitalWrite(ledPin_1, LOW);
      led_flag_1 = 1;
    } else {  // 켜져 있으면 끄고
      digitalWrite(ledPin_1, HIGH);
      led_flag_1 = 0;
    }
  }

  if (pre_btn_val_2 == HIGH && cur_btn_val_2 == LOW) {
    if (led_flag_2 == 0) {  // 꺼져 있으면 키고
      digitalWrite(ledPin_2, HIGH);
      led_flag_2 = 1;
    } else {  // 켜져 있으면 끄고
      digitalWrite(ledPin_2, LOW);
      led_flag_2 = 0;
    }
  }

  // 이전값 갱신
  pre_btn_val_1 = cur_btn_val_1;
  pre_btn_val_2 = cur_btn_val_2;
}
