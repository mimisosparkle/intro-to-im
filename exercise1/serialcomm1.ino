int potentiometerPin = A2;
int potentiometerValue = 0; //variable for sensor value

void setup() {
  Serial.begin(9600);  // starts serial communication
}

void loop() {
  potentiometerValue = analogRead(potentiometerPin);  // reads sensor value (0–1023)
  
  // sends value to p5 via serial as a line of text
  Serial.println(potentiometerValue);
  
  delay(20);
}

