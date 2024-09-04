                        //  a, b, c, d, e, f, g, DP
const unsigned char fnd_pin[8] = {2, 3, 4, 5, 6, 7, 8, 9};
const unsigned char fnd_digit[4] = {10, 11, 12, 13};
// const unsigned char fnd_data[16] = {0x8E, 0x9E, 0x7A, 0x9C, 0x3E, 0xEE, 
//                                     0xF6, 0xFE, 0xE4, 0xBE, 0xB6, 0x66, 0xF2, 0xDA, 0x60, 0xFC};
const unsigned char fnd_data[16] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xF7, 
                                    0xEE, 0x3E, 0x9C, 0x7A, 0x9E, 0x8E};
int temp = 301;

void FND_OUTPUT(int num);
void FND_display(int num);

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 8; i++)
  {
    pinMode(fnd_pin[i], OUTPUT);
  }

  for(int i = 0; i < 4; i++)
  {
    pinMode(fnd_digit[i], OUTPUT);
    digitalWrite(fnd_digit[i], LOW);
  }
}

void loop() {
//   // put your main code here, to run repeatedly:
  FND_display(temp);
}

void FND_OUTPUT(int num)
{
   for(int i = 0; i < 8; i++)
  {
    // 내가 원하는 비트를 체크하는 문구
    // 0000 0000(LOW)을 제외한 모든 비트는 HIGH
    digitalWrite(fnd_pin[i], (~fnd_data[num]) & (0x80 >> i));
  }
}

void FND_display(int temp)
{
  unsigned int num_1000 = temp / 1000;
  unsigned int num_100 = (temp % 1000) / 100;
  unsigned int num_10 = (temp % 100) / 10;
  unsigned int num_1 = temp % 10;

  digitalWrite(fnd_digit[0], HIGH);
  FND_OUTPUT(num_1000);
  delay(1);
  digitalWrite(fnd_digit[0], LOW);
  digitalWrite(fnd_digit[1], HIGH);
  FND_OUTPUT(num_100);
  delay(1);
  digitalWrite(fnd_digit[1], LOW);
  digitalWrite(fnd_digit[2], HIGH);
  FND_OUTPUT(num_10);
  delay(1);
  digitalWrite(fnd_digit[2], LOW);
  digitalWrite(fnd_digit[3], HIGH);
  FND_OUTPUT(num_1);
  delay(1);
  digitalWrite(fnd_digit[3], LOW);
}