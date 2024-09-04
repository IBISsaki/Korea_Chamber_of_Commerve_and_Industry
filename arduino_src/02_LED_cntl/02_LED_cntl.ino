void setup() {
  // put your setup code here, to run once:
  
  //ADUINO_PIN_2(PD2);
  DDRD = 0x04;

}

void loop() {
  PORTD = 0x04;
  delay(100);  
  PORTD = 0x00;
  delay(100);  

}
