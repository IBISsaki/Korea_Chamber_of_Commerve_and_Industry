unsigned char led_data[4] = {0x04,0x08,0x10,0x20};
unsigned char ary_size = sizeof(led_data)/sizeof(led_data[0]);
volatile uint8_t *ppDDRD = DDRD;

void setup() {
  // put your setup code here, to run once:
  // ARDUINO_PIN_2(PD2)
  *ppDDRD |= 0x3C;
}


void loop() {
  // 1. LED 전체 점멸
  // put your main code here, to run repeatedly:
  // PORTD |= 0x3C;   // 원하는 비트를 1로 변경(7,6)
  // delay(100);
  // PORTD &= ~0x3C;   // 원하는 비트를 0로 변경(7,6)
  // delay(100);

  // 2. LED 쉬프트(배열이용) 
  // for(int i=0; i<ary_size; i++){
  //   PORTD = led_data[i];
  //   delay(100);
  // } 

  // 3. LED 쉬프트(쉬프트 연산자 이용), <<, >>
  for(int i=0; i<4; i++){
    PORTD = 0x04 << i;
    delay(100);
  }

}
