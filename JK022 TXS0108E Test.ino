/*This program is made for test HW-0108 
 *This information for connect arduino and Testing like next
 *The next part
 *     Arduino   |    Testing
 *      3.3V     |     A08
 *      5V       |     A09
 *      A3       |     A10
 *      A2       |     A11
 *      A1       |     A12
 *      A0       |     A13
 *      GND      |     A14
 *The upperb part
 *    Arduino    |    Testing 
 *      5V       |     V17
 *      GND      |     U17
 *      5        |     T17
 *      6        |     S17
 */
unsigned char Apower = 3;
unsigned char rec0 = A0;
unsigned char rec1 = A1;
unsigned char rec2 = A2;
unsigned char rec3 = A3;
unsigned char sem = 5;
unsigned char led = 6;
int tmp0;
int tmp1;
int tmp2;
int tmp3;
int level;

void setup() {
  Serial.begin(9600);
  pinMode(rec0,INPUT);
  pinMode(rec1,INPUT);
  pinMode(rec2,INPUT);
  pinMode(rec3,INPUT);
  pinMode(sem,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  digitalWrite(led,LOW);
  tmp0 = (analogRead(rec0)*5)/102;
  tmp1 = (analogRead(rec1)*5)/102;
  tmp2 = (analogRead(rec2)*5)/102;
  tmp3 = (analogRead(rec3)*5)/102;
  if((tmp0>45) && (tmp1>45) && (tmp2>45) && (tmp3>45))
  {
    delay(600);
    tmp0 = (analogRead(rec0)*5)/102;
    tmp1 = (analogRead(rec1)*5)/102;
    tmp2 = (analogRead(rec2)*5)/102;
    tmp3 = (analogRead(rec3)*5)/102;
    if((tmp0>45) && (tmp1>45) && (tmp2>45) && (tmp3>45))
    {
      digitalWrite(led,HIGH);
      Serial.println("This circuit modular is good");
      Serial.println();
      Serial.println();
      for(;;)
      {
        level = digitalRead(sem);
        if(level == HIGH) break;
        delay(100);
      }
    }else{
      Serial.println("Something wrong have happened,please try again");
      for(;;)
      {
        level = digitalRead(sem);
        if(level ==HIGH) break;
        delay(100);
      }
    }
  }
  for(;;)
  {
    level = digitalRead(sem);
    if(level ==HIGH) break;
    delay(100);
  }
}
