const int LED = 3;
char str[10] = {0};
int cnt = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // 1. C언어 스타일 코딩
  // ========== 문자열 저장 부분 ===========
  while(1){
    if(Serial.available()){
      char userInput = Serial.read();
      if(userInput == '\r'){
        str[cnt] = '\0';
        cnt = 0;
        break;
      }
      else{
        str[cnt] = userInput;
        cnt++;
      }
    }  
  }
  Serial.print(str);

  // ============== 문자열을 이용한 제어 부분 =====================
  if(strcmp(str,"LED0_ON") == 0) digitalWrite(LED, HIGH);
  else if(strcmp(str,"LED0_OFF") == 0) digitalWrite(LED, LOW);

  // 2. C++언어 스타일 코딩(Serial.readString함수 이용)
  // if(Serial.available()){
  //   String rx_data = Serial.readString();
  //   rx_data.trim();   // \n,\r을 제거
  //   if(rx_data == "LED0_ON") digitalWrite(LED, HIGH);
  //   else if(rx_data == "LED0_OFF") digitalWrite(LED, LOW);
  // }
  
}












