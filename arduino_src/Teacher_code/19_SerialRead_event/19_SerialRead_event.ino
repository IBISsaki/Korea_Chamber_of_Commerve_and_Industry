
void setup() {
  // initialize serial:
  Serial.begin(115200);
}

void loop() {
  // print the string when a newline arrives:

}

void serialEvent() {
  char inChar = (char)Serial.read();
  Serial.print(inChar);
}
