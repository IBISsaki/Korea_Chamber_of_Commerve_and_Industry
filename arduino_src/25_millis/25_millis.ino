unsigned long t_prev = 0;
unsigned long t_delay = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long t_now = millis();
  if(t_now - t_prev >= t_delay)
  {
    t_prev = t_now;
    Serial.println(t_now);
  }
  
}
