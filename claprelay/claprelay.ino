
// AO -> No Connection
// G  -> GND
// +  -> 5V
// DO -> D2

int relay = 13;  // Internal Arduino LED
int digitalPin = 2; // Digital Input Pin we're using

int digitalVal = 0; // Current value read from D2
int prevVal = 0;    // Previous Value
int stat = 0;    // Is the "Lamp" on or off currently

void setup()
{
  pinMode(relay, OUTPUT);     // Configure on-board LED pin as an output
  digitalWrite(relay, stat);  // Set LED to On or Off to simulate Lamp
  pinMode(digitalPin, INPUT); // Configure D2 as an input from Sound Sensor module

  Serial.begin(9600);     // Open Serial Port
  Serial.println("Sound Sensor Test");

  digitalVal = digitalRead(digitalPin); // Read current value from Sound Sensor
  Serial.println(digitalVal); // Print current value of sound sensor (0 or 1)
  prevVal = digitalVal;     // Keep track of prior value (so we know when it changes)
}

void loop()
{
  digitalVal = digitalRead(digitalPin); // Read current value from Sound Sensor
  if (digitalVal != prevVal)  // Detect change
  {
    Serial.println(digitalVal);  // Print new value
    stat = !stat; // If lamp was On, turn it Off and vice-versa
    digitalWrite(relay, stat);  // Set LED to On or Off to simulate Lamp
    delay(500); // Delay 500ms to "debounce" input
    digitalVal = digitalRead(digitalPin); // Read current value again
    Serial.println(digitalVal); // Print new value
    prevVal = digitalVal; // Keep track of prior value
  }
}
