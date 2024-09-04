/* 
  하드웨어 설계
  - 6pin sw_1는 Active HIGH
  - 4pin LED_1는 Active HIGH (0.3초 점멸) (300ms)
  - 7pin sw_2는 Active HIGH
  - 5pin LED_2는 Active HIGH (0.5초 점멸) (500ms)
*/
#include "PinChangeInterrupt.h"

const int buttonPin_1 = 6;
const int ledPin_1 = 4;
const int buttonPin_2 = 7;
const int ledPin_2 = 5;

int led_flag_1 = 0;   // 0:OFF, 1:ON
int led_flag_2 = 0;

// 사용자 함수 선언
// ISR(인터럽트 서비스 루틴)
void buttonPressed_1(void)
{
  if(led_flag_1 == 0){    // 꺼져 있으면 키고
    led_flag_1 = 1;
  }
  else{
    digitalWrite(ledPin_1, LOW);
    led_flag_1 = 0;
  }
}

void buttonPressed_2(void)
{
  if(led_flag_2 == 0){
    led_flag_2 = 1;
  }
  else{
    digitalWrite(ledPin_2, LOW);
    led_flag_2 = 0;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(buttonPin_1, INPUT);
  pinMode(ledPin_1, OUTPUT);
  attachPCINT(digitalPinToPCINT(buttonPin_1), buttonPressed_1, RISING);

  pinMode(buttonPin_2, INPUT);
  pinMode(ledPin_2, OUTPUT);
  attachPCINT(digitalPinToPCINT(buttonPin_2), buttonPressed_2, RISING);

  // led를 끄고 시작(시스템 초기화)
  digitalWrite(ledPin_1, LOW);
  digitalWrite(ledPin_2, LOW);
}

void loop() {

  // 스위치 동작에 따른 상태값 변경
  if(led_flag_1 == 1){
    digitalWrite(ledPin_1, HIGH);
    delay(300);
    digitalWrite(ledPin_1, LOW);
    delay(300);
  }

  if(led_flag_2 == 1){
    digitalWrite(ledPin_2, HIGH);
    delay(500);
    digitalWrite(ledPin_2, LOW);
    delay(500);
  }
}