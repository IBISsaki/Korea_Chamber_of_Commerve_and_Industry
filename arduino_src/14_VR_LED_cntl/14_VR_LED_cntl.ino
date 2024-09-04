const int Xin = A0;
const int Yin = A1;
const int KEYin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(KEYin, INPUT_PULLUP);  
}

void loop() {
  int xVal = analogRead(Xin);
  int yVal = analogRead(Yin);
  int buttonVal = digitalRead(KEYin);

  Serial.print("x = ");
  Serial.println(xVal, DEC);

  Serial.print("y = ");
  Serial.println(yVal, DEC);

  Serial.println("Button is ");
  if(buttonVal == HIGH)
  {
    Serial.println("not pressed");
  }
  else
  {
    Serial.println("PRESSED");
  }
  delay(300);
}