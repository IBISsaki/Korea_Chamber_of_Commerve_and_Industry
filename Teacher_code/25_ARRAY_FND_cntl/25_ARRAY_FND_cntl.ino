#define time_val  1

#include "TimerOne.h"

static unsigned int time_S = 0;
                          // a, b, c, d, e, f, g, dp
const int FND_DATA_PIN[8] = {2, 3, 4, 5, 6, 7, 8, 9};
                           // D1, D2, D3, D4
const int FND_DIGIT_PIN[4] = {10, 11, 12, 13};
int i = 0, j = 0, k = 0;

const unsigned char FND_DATA[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
                                    0x7F,0x6F,0x5F,0x7C,0x58,0x5E,0x79,0x71};
const unsigned char FND_DIGIT[4] = {0x01, 0x02, 0x04, 0x08};                                

void setup() {
  // put your setup code here, to run once:
  display_init();

  Timer1.initialize(1000000); // 주기가 1초인 타이머 설정
  Timer1.attachInterrupt(timer1_callback);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  display_numbers(time_S);
}

// 사용자 함수
void timer1_callback()    // 1초마다 호출
{
  time_S++;
}

void display_init(){
  for(int x=0; x<8; x++){   
    pinMode(FND_DATA_PIN[x], OUTPUT);
  }
  for(int y=0; y<4; y++){  
    pinMode(FND_DIGIT_PIN[y], OUTPUT);
  }
}

void display_clear(){
  for(int x=0; x<8; x++){   
    digitalWrite(FND_DATA_PIN[x], HIGH);
  }
  for(int y=0; y<4; y++){  
    digitalWrite(FND_DIGIT_PIN[y], LOW);
  }
}

void display_numbers(int num){   // 8475
  int num_tbl[4] = {};

  num_tbl[0] = (num/10000)/1000;        // 천의 자리
  num_tbl[1] = (num%1000)/100;  // 백의 자리
  num_tbl[2] = (num%100)/10;    // 십의 자리
  num_tbl[3] = num%10;          // 일의 자리
  
  for(i=0; i<4; i++){
    display_clear();
    for(k=0; k<8; k++){
      digitalWrite(FND_DATA_PIN[k], (~FND_DATA[num_tbl[i]])&(0x01<<k));
    }
    for(j=0; j<4; j++){
      digitalWrite(FND_DIGIT_PIN[j], FND_DIGIT[i]&(0x01<<j));
    }
    delay(time_val);
  }
}
