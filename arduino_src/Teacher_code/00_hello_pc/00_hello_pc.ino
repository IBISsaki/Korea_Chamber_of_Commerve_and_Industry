void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("setup");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.begin(115200);
  Serial.println(10, DEC);
  delay(100);
}
