                        //  a, b, c, d, e, f, g, DP
const unsigned char fnd_pin[8] = {2, 3, 4, 5, 6, 7, 8, 9};
const unsigned char fnd_data[16] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xF6, 
                                    0xEE, 0x3E, 0x9C, 0x7A, 0x9E, 0x8E};

  void FND_OUTPUT(int num);

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 8; i++)
  {
    pinMode(fnd_pin[i], OUTPUT);
  }

  for(int i = 0; i < 16; i++)
  {
    digitalWrite(fnd_data[i], HIGH);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  // for(int i = 0; i < 16; i++)
  // {
  // FND_OUTPUT(i);
  // delay(1000);
  // }
  // // 1
  // FND_OUTPUT(1);
  // delay(500);
  // // 2
  // FND_OUTPUT(2);
  // delay(500);
}

void FND_OUTPUT(int num)
{
   for(int i = 0; i < 8; i++)
  {
    // 내가 원하는 비트를 체크하는 문구
    // 0000 0000(LOW)을 제외한 모든 비트는 HIGH
    digitalWrite(fnd_pin[i], fnd_data[num] & (0x80 >> i));
  }
}