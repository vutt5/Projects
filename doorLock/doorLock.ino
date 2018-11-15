#include <Servo.h>
Servo door;

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
int password=1111;
int doorcondition = 0;
int greenLED = 10;
int redLED = 13;
int d=4;
int c=5;

void setup() {
 

pinMode(greenLED, OUTPUT);
pinMode(redLED, OUTPUT);
  door.attach(9);        //attach the servo on pins
  Serial.begin(9600);
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();  

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("********************");
  lcd.setCursor(0,1);
  lcd.print("  LAM` ON CHO PASS");
  lcd.setCursor(0,2);
  lcd.print("  NHA^'N # KHI XONG");
  lcd.setCursor(0,3);
  lcd.setBacklight(0);
door.write(0);  

}


   


void loop() {
int   a = analogRead(A0);
int   b = analogRead(A1);
if (a>1000){
  
  unlockDoor();
  lcd.setBacklight(0);
} 
if (b>1000){
  
  lockDoor();
} lcd.setBacklight(0);

char costomKey = customKeypad.getKey();
if(costomKey){
int   i = GetNumber();

if (i == 999){
 password = GetPass();
 lcd.setBacklight(0);
}
else if (i != password){
  
  invalidCode();
  lcd.setBacklight(0);
}
else if ( i == password) {
  
  unlockDoor();
  lcd.setBacklight(0);
}

}




  }

int GetNumber()
{lcd.setBacklight(200);
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
            displayCodeEntryScreen();
            break;
      }

      key = customKeypad.getKey();
   }

   return num;
}


  
 int GetPass()
{lcd.setBacklight(200);
   int num = 0;
   char key = customKeypad.getKey();
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("********************");
  lcd.setCursor(0,1);
  lcd.print("****THAY PASS HA?***");
  lcd.setCursor(0,2);
  lcd.print("******GHI DI:");
  lcd.setCursor(0,3);
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
  lcd.print("********************");
  lcd.setCursor(0,1);
  lcd.print("****THAY PASS HA?***");
  lcd.setCursor(0,2);
  lcd.print("******GHI DI:");
  lcd.setCursor(0,3);
            break;
      }

      key = customKeypad.getKey();
   }
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("NEW PASSWORD SET");
   delay(2000);
   displayCodeEntryScreen();
   return num;
}







  

  void invalidCode()
{
  lcd.setBacklight(200);
  digitalWrite(redLED, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("********************");
  lcd.setCursor(0,1);
  lcd.print("**  MAY` LA` AI?  **");
  lcd.setCursor(0,2);
  lcd.print("**  SAI PASS ROI  **");
  lcd.setCursor(0,3);
  lcd.print("********CU'T*****");
  lcd.print(d);
  lcd.print("***");
  d=d-1;
  if (d>0){
  delay(5000);
  digitalWrite(redLED, LOW);
  displayCodeEntryScreen();
}
  else{
 lcd.clear();
  lcd.setBacklight(0); 
  d=4;
   }
    
  }




  void unlockDoor()
{
  lcd.setBacklight(200);
  digitalWrite(10, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("********************");
  lcd.setCursor(0,1);
  lcd.print("**    DU'NG ROI   **");
  lcd.setCursor(0,2);
  lcd.print("**    WELCOME!!   **");
  lcd.setCursor(0,3);
  lcd.print("********************");
  
  //add any code to unlock the door here

   door.write(95);
  delay(3000);
  digitalWrite(10, LOW);
  displayCodeEntryScreen();
  d=4;
}


void lockDoor()
{
  digitalWrite(10, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("********************");
  lcd.setCursor(0,1);
  lcd.print("**    CLOSING     **");
  lcd.setCursor(0,2);
  lcd.print("**    THANKS      **");
  lcd.setCursor(0,3);
  lcd.print("********************");
  
  //add any code to unlock the door here

   door.write(0);
  delay(2000);
  digitalWrite(10, LOW);
  displayCodeEntryScreen();
  d=4;
}




void displayCodeEntryScreen()
{lcd.setBacklight(200);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("********************");
  lcd.setCursor(0,1);
  lcd.print("  LAM` ON CHO PASS  ");
  lcd.setCursor(0,2);
  lcd.print("  NHA^'N # KHI XONG");
  lcd.setCursor(0,3);
  
}


  


