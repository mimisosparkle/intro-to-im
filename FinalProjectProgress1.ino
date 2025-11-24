// all values for LED pins
const int LED1 = 2; 
const int LED2 = 4;
const int LED3 = 6;
const int LED4 = 8;
const int LED5 = 10;

void setup() {
Serial.begin(9600); //baud rate 9600
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
pinMode(LED5, OUTPUT);
}

void loop() {

int sensorValue = analogRead(A2); //for testing potentiometer values
Serial.println(sensorValue);

//conditions for what LED turns on
if (sensorValue >= 0 && sensorValue < 100){ //first LED (going from left to right) lights up
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
}

else if (sensorValue >= 100 && sensorValue < 200){ //second LED lights up because potentiometer value is within range
  digitalWrite(LED2, HIGH);
  digitalWrite(LED1, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
}

else if (sensorValue >= 200 && sensorValue < 300){ //third LED lights up
  digitalWrite(LED3, HIGH);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
}

else if (sensorValue >= 300 && sensorValue <400){ //fourth LED lights up
  digitalWrite(LED4, HIGH);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED5, LOW);
}

else if (sensorValue >= 400 && sensorValue < 500){ //fifth LED lights up
  digitalWrite(LED5, HIGH);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
}

else{ //when all statemtns are false, all LEDs turn off
digitalWrite(LED1, LOW);
digitalWrite(LED2, LOW);
digitalWrite(LED3, LOW);
digitalWrite(LED4, LOW);
digitalWrite(LED5, LOW);
}

}
