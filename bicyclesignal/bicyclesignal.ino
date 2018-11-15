

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
}



void loop()
{
  int a = analogRead(A0);
  int b = analogRead(A1);
  int c = analogRead(A2);
  if (a >=1010){
  digitalWrite(2,HIGH);
  digitalWrite(10,HIGH);
  delay(150);
  digitalWrite(10,LOW);
  delay(50);
  digitalWrite(3,HIGH);
  digitalWrite(10,HIGH);
  delay(150);
  digitalWrite(10,LOW);
  delay(50);
  digitalWrite(4,HIGH);
  digitalWrite(10,HIGH);
  delay(150);
  digitalWrite(10,LOW);
  delay(50);
  digitalWrite(5,HIGH);
  digitalWrite(10,HIGH);
  delay(150);
  digitalWrite(10,LOW);
  delay(50);
  digitalWrite(6,HIGH);
 digitalWrite(10,HIGH);
  delay(150);
  digitalWrite(10,LOW);
  delay(50);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  delay(500);
  }
  if (b >=1010){
  digitalWrite(7,HIGH);
  digitalWrite(10,HIGH);
  delay(150);
  digitalWrite(10,LOW);
  delay(50);
  digitalWrite(8,HIGH);
  digitalWrite(10,HIGH);
  delay(150);
  digitalWrite(10,LOW);
  delay(50);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  delay(150);
  digitalWrite(10,LOW);
  delay(50);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  delay(150);
  digitalWrite(10,LOW);
  delay(50);
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
  delay(150);
  digitalWrite(10,LOW);
  delay(50);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  delay(500);
  }
  if (c >=1010){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    delay(400);
   
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    
    delay(400);
    
   
    }
}
