#include <Servo.h>
Servo quarterservo,dimeservo,nickelservo,pennyservo;

#include <Keypad.h>
const byte ROWS = 4; 
const byte COLS = 3; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {8, 7, 6, 5}; 
byte colPins[COLS] = {4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 



#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
  int total;

void setup() {
 


  quarterservo.attach(9);        //attach the servo on pins
  dimeservo.attach(10);
  nickelservo.attach(11);
  pennyservo.attach(12);
  Serial.begin(9600);
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();  

   lcd.setCursor(0,0);
  lcd.print("How Much?");
  lcd.setCursor(12,0);
quarterservo.write(110);  
dimeservo.write(110);
nickelservo.write(110);
pennyservo.write(110);

}


   int GetNumber()
{
   int num = 0;
   char key = customKeypad.getKey();
   while(key != '#')
   {
      switch (key)
      {
         case NO_KEY:
            break;

         case '0': case '1': case '2': case '3': case '4':
         case '5': case '6': case '7': case '8': case '9':
            lcd.print(key);
            num = num * 10 + (key - '0');
            break;

         case '*':
            num = 0;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("How Much?");
            lcd.setCursor(12,0);
            break;
      }

      key = customKeypad.getKey();
   }

   return num;
}

void loop() {

int   i = GetNumber();

int quarter = i/25;
int change = i%25;
int dime = change/10;
 change = change%10;
int nickel = change/5;
change = change%5;
int penny = change;


lcd.clear();
lcd.setCursor(0,0);
  lcd.print(quarter);
  lcd.print(" 25c| ");

  lcd.print(dime);
  lcd.print(" 10c| ");
  lcd.setCursor(0,1);

  lcd.print(nickel);
  lcd.print(" 5c| ");

  lcd.print(penny);
  lcd.print(" 1c| ");

lcd.print("wait");
delay(500);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("dispensing");
delay(500);
lcd.print(".");
delay(500);
lcd.print(".");
delay(500);
lcd.print(".");


Serial.print("quarter: ");
 Serial.print(quarter);
 Serial.print("\n");
  Serial.print("dime: ");
 Serial.print(dime);
 Serial.print("\n");
 Serial.print("nickel: ");
 Serial.print(nickel);
 Serial.print("\n");
 Serial.print("penny: ");
 Serial.print(penny);
 Serial.print("\n");

 
for(int i=0;i<quarter;i++){
  quarterservo.write(0);
  delay(300);
  quarterservo.write(110);
  delay(300);
}
for(int i=0;i<dime;i++){
  dimeservo.write(0);
  delay(300);
  dimeservo.write(110);
  delay(300);
}
for(int i=0;i<nickel;i++){
  nickelservo.write(0);
  delay(300);
  nickelservo.write(110);
  delay(300);
}
for(int i=0;i<penny;i++){
  pennyservo.write(0);
  delay(300);
  pennyservo.write(110);
  delay(300);
}

lcd.clear();
lcd.setCursor(0,0);
lcd.print("How Much?");
lcd.setCursor(12,0);

 
  
  }




  


