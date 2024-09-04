/* 
  하드웨어 설계
  - 2pin sw_1는 Active LOW
  - 3pin LED_1는 Active LOW
  - 4pin sw_2는 Active HIGH
  - 5pin LED_2는 Active HIGH
*/
const int ledPin_1 = 5;
const int buttonPin_1 = 2;
int led_flag_1 = 0;   // 0:OFF, 1:ON
int cur_btn_val_1 = 0, pre_btn_val_1 = 0;   // cur : 현재값, pre : 이전값

// 사용자 함수 선언
// ISR(인터럽트 서비스 루틴)
void buttonPressed(void)
{
  if(led_flag_1 == 0){    // 꺼져 있으면 키고
      led_flag_1 = 1;
    }
    else{
      digitalWrite(ledPin_1, LOW);
      led_flag_1 = 0;
    }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(buttonPin_1, INPUT);
  pinMode(ledPin_1, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin_1), buttonPressed, RISING);

  // led를 끄고 시작(시스템 초기화)
  digitalWrite(ledPin_1, LOW);


}

void loop() {

  // 스위치 동작에 따른 상태값 변경
  if(led_flag_1 == 1){
    digitalWrite(ledPin_1, HIGH);
    delay(100);
    digitalWrite(ledPin_1, LOW);
    delay(100);
  }
}