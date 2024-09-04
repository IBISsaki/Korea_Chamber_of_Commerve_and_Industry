const int buttonPin = 2;
const int ledPin = 3;
int led_flag = 0; // 0:off, 1:on

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(ledPin, OUTPUT);
pinMode(buttonPin, INPUT);

digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
int buttonInput = digitalRead(buttonPin);
  // digitalWrite(ledPin, buttonInput);

  if(buttonInput == HIGH)
  {
    if(led_flag == 0)
    {
      digitalWrite(ledPin, HIGH);
      led_flag = 1;
    }
    else
    {
      digitalWrite(ledPin, LOW);
      led_flag = 0;
    }
    delay(1000);
  }
}
