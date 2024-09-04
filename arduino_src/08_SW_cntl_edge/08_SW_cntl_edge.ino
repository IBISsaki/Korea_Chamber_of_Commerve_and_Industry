/* 
  하드웨어 설계
  - sw는 Active LOW
  - LED는 Active LOW
*/
const int ledPin = 3;
const int buttonPin = 2;
int led_flag = 0;   // 0:OFF, 1:ON
int cur_btn_val = 1, pre_btn_val = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // led를 끄고 시작(시스템 초기화)
  digitalWrite(ledPin, HIGH);
}

void loop() {
  cur_btn_val = digitalRead(buttonPin);     // 현재값 저장
  if(pre_btn_val == LOW && cur_btn_val == HIGH)  // pre_btn_val > cur_btn_val
  {
    if(led_flag == 0){    // 꺼져 있으면 키고
      digitalWrite(ledPin, LOW);
      led_flag = 1;
    }
    else{                 // 켜져 있으면 끄고
      digitalWrite(ledPin, HIGH);
      led_flag = 0;
    }
  }
  pre_btn_val = cur_btn_val;  // 이전값 갱신
}

/*
void loop() {
  // put your main code here, to run repeatedly:
  int buttonInput = digitalRead(buttonPin);

  if(buttonInput == LOW){
    if(led_flag == 0){    // 꺼져 있으면 키고
      digitalWrite(ledPin, LOW);
      led_flag = 1;
    }
    else{                 // 켜져 있으면 끄고
      digitalWrite(ledPin, HIGH);
      led_flag = 0;
    }
    
  }
}
*/