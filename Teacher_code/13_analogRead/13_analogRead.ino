#define A_REF       5.0
#define RESOLUTION  1024
#define UNIT_ADC    A_REF/RESOLUTION
#define VR          10000.0

const int analogPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  float analogValue = analogRead(analogPin);
  float volt = analogValue * UNIT_ADC;
  float reg = (VR*volt) / A_REF;

  Serial.print(analogValue, 0);
  Serial.print(", ");
  Serial.print(volt, 2);
  Serial.print(" V, ");
  Serial.print(reg);
  Serial.println(" ohm");
  delay(300);

}

// char temp[20];
// char buffer[20];
// int i = 123;
// float f = 32.4;
// char c = 'A';
// char str[] = "Hello";

// void setup() {
//   Serial.begin(115200);

//   dtostrf(f, 4, 1, temp);
//   sprintf(buffer, "%d , %s , %c , %s", i, temp, c, str);

//   Serial.print(buffer);
// }

// void loop() {

// }