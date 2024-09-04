/* 
  하드웨어 설계
  - 2pin sw_1는 Active LOW
  - 3pin LED_1는 Active LOW
  - 4pin sw_2는 Active HIGH
  - 5pin LED_2는 Active HIGH
*/
// const int ledPin_1 = 3;
// const int buttonPin_1 = 2;
// ----------------------------------
const int ledPin_2 = 5;
const int buttonPin_2 = 4;

// int led_flag_1 = 0;   // 0:OFF, 1:ON
// ----------------------------------
int led_flag_2 = 0;

// int cur_btn_val_1 = 1, pre_btn_val_1 = 1;   // cur : 현재값, pre : 이전값
// ----------------------------------
int cur_btn_val_2 = 0, pre_btn_val_2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // pinMode(buttonPin_1, INPUT);
  // pinMode(ledPin_1, OUTPUT);
// ----------------------------------
  pinMode(buttonPin_2, INPUT);
  pinMode(ledPin_2, OUTPUT);

  // led를 끄고 시작(시스템 초기화)
  // digitalWrite(ledPin_1, HIGH);
// ----------------------------------
  digitalWrite(ledPin_2, LOW);

}

void loop() {
  // cur_btn_val_1 = digitalRead(buttonPin_1);     // 현재값 저장
  // if(pre_btn_val_1 == HIGH && cur_btn_val_1 == LOW)  // pre_btn_val > cur_btn_val
  // {
  //   if(led_flag_1 == 0){    // 꺼져 있으면 키고
  //     digitalWrite(ledPin_1, LOW);
  //     led_flag_1 = 1;
  //   }
  //   else{                 // 켜져 있으면 끄고
  //     digitalWrite(ledPin_1, HIGH);
  //     led_flag_1 = 0;
  //   }
  // }
  // pre_btn_val_1 = cur_btn_val_1;  // 이전값 갱신
// -------------------------------------------------------------------------------------------
  cur_btn_val_2 = digitalRead(buttonPin_2);     // 현재값 저장

  // 스위치 동작에 따른 상태값 변경
  if(pre_btn_val_2 == LOW && cur_btn_val_2 == HIGH)  // pre_btn_val > cur_btn_val
  {
    if(led_flag_2 == 0){    // 꺼져 있으면 키고

      led_flag_2 = 1;
    }
    else{

      led_flag_2 = 0;
    }
  }
    if(led_flag_2 == 1){
      digitalWrite(ledPin_2, HIGH);
      delay(100);
      digitalWrite(ledPin_2, LOW);
      delay(100);
    }
  
  pre_btn_val_2 = cur_btn_val_2;  // 이전값 갱신
}