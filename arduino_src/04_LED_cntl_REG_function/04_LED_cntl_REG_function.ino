// 사용자 함수 선언
int myPinMode(int pin_num, int mode);
int myDigitalWrite(int pin_num, int val);

// 전역 변수 선언
unsigned char led_data[4]{0x04, 0x08, 0x10, 0x20};
unsigned char ary_size = sizeof(led_data)/sizeof(led_data[0]);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myPinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 1. LED 전체 점멸
  // PORTB |= 0x03;
  // PORTD |= 0xC0;
  // delay(100);
  // PORTB &= 0xFC;
  // PORTD &= 0x30;
  // delay(100);

  //2. LED 쉬프트(배열이용) 
  // for(int i = 0; i < ary_size; i++)
  // {
  //   PORTD = led_data[i];
  //   delay(100);
  //   PORTD &= ~led_data[i];
  //   delay(100);
  // }

  // 3. LED 쉬프트(쉬프트 연산자 이용), <<, >>
  //  for(int i = 0; i < 4; i++)
  //  {
  //    PORTD = 0x04 << i;
  //    delay(100);
  //  }
  myDigitalWrite(3, HIGH);
  delay(100);
  myDigitalWrite(3, LOW);
  delay(100);
}

int myPinMode(int pin_num, int mode)
{
  int pin_array[14] = {0,1,2,3,4,5,6,7,0,1,2,3,4,5};
  int port;
  int pin;

  if(pin_num > 13 || pin_num < 0)
  {
    Serial.println("0~13까지만 허용됩니다.");
    return -1;
  }
  else
  {
    pin = pin_array[pin_num];
  }

  if(pin_num > 7) port = DDRB;
  else port = DDRD;
  
  if(mode == OUTPUT) port |= 0x01 << pin;
  else port |= ~(0x01 << pin);

  return 0;
}

int myDigitalWrite(int pin_num, int val)
{
  int pin_array[14] = {0,1,2,3,4,5,6,7,0,1,2,3,4,5};
  int port;
  int pin;

  if(pin_num > 13 || pin_num < 0)
  {
    Serial.println("0~13까지만 허용됩니다.");
    return -1;
  }
  else
  {
    pin = pin_array[pin_num];
  }

  if(pin_num > 7) port = PORTB;
  else port = PORTD;
  
  if(val == HIGH) port |= 0x01 << pin;
  else if(val == LOW) PORTD |= ~(0x01 << pin);

  return 0;
}