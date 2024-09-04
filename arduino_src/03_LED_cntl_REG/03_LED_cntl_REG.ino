void setup() {
  // put your setup code here, to run once:
  
  //ADUINO_PIN_2(PD2);
  DDRD |= 0x80;
  DDRD |= 0x40;
}

void loop() {
  // PORTD = 0xC0; // 원하는 비트를 1로 변경(7, 6)
  // delay(100);  
  // PORTD = 0x00;  // 원하는 비트를 0로 변경 (7, 6)
  // delay(100);  
  PORTD |= 0xC0; // 원하는 비트를 1로 변경(7, 6)
  delay(100);  
  PORTD &= 0x3F;  // 원하는 비트를 0로 변경 (7, 6)
  delay(100);  


}
