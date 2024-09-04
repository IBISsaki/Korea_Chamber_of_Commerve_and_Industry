#define A_REF 
#define RESOLUTION 
#define UNIT_ADC 
#define RV 

const int analogPin = A0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  
}

void loop() {
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