/* 
  하드웨어 설계
  - SW는 Active HIGH
  - LED는 Active HIGH
*/

unsigned long t1_prev = 0;
unsigned long t1_delay = 300;

unsigned long t2_prev = 0;
unsigned long t2_delay = 500;

const int ledPin_1 = 4;
const int buttonPin_1 = 2;
int led_flag_1 = 0;  // 0:OFF, 1:ON

const int ledPin_2 = 5;
const int buttonPin_2 = 3;
int led_flag_2 = 0;  // 0:OFF, 1:ON


// 사용자 함수 선언
// ISR(인터럽트 서비스 루틴)
void buttonPressed_1(void){
  // 스위치 동작에 따른 상태값 변경
  if (led_flag_1 == 0) {  // 꺼져 있으면 키고
    led_flag_1 = 1;
  } else {  // 켜져 있으면 끄고
    led_flag_1 = 0;
  }
}

void buttonPressed_2(void){
  // 스위치 동작에 따른 상태값 변경
  if (led_flag_2 == 0) {  // 꺼져 있으면 키고
    led_flag_2 = 1;
  } else {  // 켜져 있으면 끄고
    led_flag_2 = 0;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(buttonPin_1, INPUT);
  pinMode(ledPin_1, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin_1), buttonPressed_1, RISING);
  pinMode(buttonPin_2, INPUT);
  pinMode(ledPin_2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin_2), buttonPressed_2, RISING);

  // LED를 끄고 시작
  digitalWrite(ledPin_1, LOW);
  digitalWrite(ledPin_2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 상태값에 따른 동작 구현
  unsigned long t1_now = millis();
  if(t1_now - t1_prev >= t1_delay)
  {
    t1_prev = t1_now;
    if(led_flag_1 == 1){
      digitalWrite(ledPin_1, digitalRead(ledPin_1) ? LOW:HIGH);
    }
    // else
    // {
    //   digitalWrite(ledPin_1, LOW);
    // }
  }

  unsigned long t2_now = millis();
  if(t2_now - t2_prev >= t2_delay)
  {
    t2_prev = t2_now;
    if(led_flag_2 == 1){
      digitalWrite(ledPin_2, digitalRead(ledPin_2) ? LOW:HIGH);
    }
    //     else
    // {
    //   digitalWrite(ledPin_2, LOW);
    // }
  }
}