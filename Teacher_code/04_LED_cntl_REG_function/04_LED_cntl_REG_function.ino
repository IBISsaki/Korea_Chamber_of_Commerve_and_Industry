// 사용자 함수 선언
void myPinMode(int pin_num, int mode);
void myDigitalWrite(int pin_num, int val);

// 전역 변수 선언
const int LED = 8;
unsigned char led_data[4] = {0x04,0x08,0x10,0x20};
unsigned char ary_size = sizeof(led_data)/sizeof(led_data[0]);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  // ARDUINO_PIN_2(PD2)
  myPinMode(LED, OUTPUT);
}

void loop() {
  // 1. LED 전체 점멸
  // put your main code here, to run repeatedly:
  // PORTD |= 0x01 << PORT3;
  myDigitalWrite(LED, HIGH);   // 원하는 비트를 1로 변경(7,6)
  delay(1000);
  // PORTD &= ~(0x01 << PORT3);
  myDigitalWrite(LED, LOW);   // 원하는 비트를 0로 변경(7,6)
  delay(1000);
}

void myPinMode(int pin_num, int mode){
  int pin_array[14] = {0,1,2,3,4,5,6,7,0,1,2,3,4,5};
  int pin;

  if( pin_num < 0 || pin_num > 13){
    Serial.println("0~13까지만 허용됩니다.");
    return;
  }
  else{
    pin = pin_array[pin_num];
  }

  if(pin_num > 7){
    if(mode == OUTPUT) DDRB |= 0x01 << pin;
    else if(mode == INPUT) DDRB &= ~(0x01 << pin);
  }
  else{
    if(mode == OUTPUT) DDRD |= 0x01 << pin;
    else if(mode == INPUT) DDRD &= ~(0x01 << pin);
  }
}

void myDigitalWrite(int pin_num, int val){
  int pin_array[14] = {0,1,2,3,4,5,6,7,0,1,2,3,4,5};
  int pin;

  if( pin_num < 0 || pin_num > 13){
    Serial.println("0~13까지만 허용됩니다.");
    return;
  }
  else{
    pin = pin_array[pin_num];
  }

  if(pin_num > 7){
    if(val == HIGH) PORTB |= 0x01 << pin;
    else if(val == LOW) PORTB &= ~(0x01 << pin);
  }
  else{
    if(val == HIGH) PORTD |= 0x01 << pin;
    else if(val == LOW) PORTD &= ~(0x01 << pin);
  }
}
