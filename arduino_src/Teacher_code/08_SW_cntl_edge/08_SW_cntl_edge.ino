/* 
  하드웨어 설계
  - SW는 Active LOW
  - LED는 Active LOW
*/

const int ledPin = 3;
const int buttonPin = 2;
int led_flag = 0;   // 0:OFF, 1:ON
int cur_btn_val=1, pre_btn_val=1;

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
   // 현재값 저장
  cur_btn_val = digitalRead(buttonPin);  
  
  // // 1. 중첩 if문 사용
  // if(pre_btn_val == HIGH){
  //   if(cur_btn_val == LOW){
  //     if(led_flag == 0){      // 꺼져 있으면 키고
  //       digitalWrite(ledPin, LOW);
  //       led_flag = 1;
  //     }
  //     else{                   // 켜져 있으면 끄고
  //       digitalWrite(ledPin, HIGH);
  //       led_flag = 0;
  //     }
  //   }
  // }

  if(pre_btn_val == HIGH && cur_btn_val == LOW){
    if(led_flag == 0){      // 꺼져 있으면 키고
      digitalWrite(ledPin, LOW);
      led_flag = 1;
    }
    else{                   // 켜져 있으면 끄고
      digitalWrite(ledPin, HIGH);
      led_flag = 0;
    }
  }

  // 이전값 갱신
  pre_btn_val = cur_btn_val;
}
