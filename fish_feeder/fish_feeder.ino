
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

long int count = 0;  
int one = 2;
int two = 3;
int three = 4;
int manual = 5;
int stat = 6;
int led = 7;

int feedingTime = 1;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(2, INPUT);
   pinMode(3, INPUT);
    pinMode(4, INPUT);
     pinMode(5, INPUT);
      pinMode(6, INPUT);
       pinMode(7, OUTPUT);
       
  Serial.begin(9600);
  myservo.write(125);          
}

void loop() {
  int a = digitalRead(one);
  int b = digitalRead(two);
  int c = digitalRead(three);
  int d = digitalRead(manual);
  int e = digitalRead(stat);
  if (e == HIGH){
    for(int i=0;i<feedingTime;i++){
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
    }
  }
  
  if (a == HIGH){
    feedingTime = 1;
    digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
  }
  else if (b == HIGH){
    feedingTime = 2;
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
  }

  else if (c == HIGH) {
    feedingTime = 3;
    digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
  }

 if (d == HIGH){
  feed(); 
 }

 if (feedingTime == 1){
  if (count == 0){
    feed();
    count = 86400;
  }
 }
 else if (feedingTime == 2){
  if ((count == 0) || (count == 43200)){
    feed();
    if (count == 0){
      count = 86400;
    }
  }
 }
 else if (feedingTime == 3){
  if ((count == 0) || (count == 28800) ||(count == 57600)){
    feed();
    if (count == 0){
      count = 86400;
    }
  }
 }
count--;
//for debugging.

Serial.println("feeding times: ");
Serial.println(feedingTime);
Serial.println("count:: ");
Serial.println(count);
delay (1000);
}

void feed(){
  digitalWrite(led, HIGH);
   myservo.write(70);              
    delay(1000);                      
    myservo.write(125);              
    delay(1000);  
  digitalWrite(led, LOW);                      
}

