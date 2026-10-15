int emgPin = A0;         
             
int emgThreshold1 = 200;     // Adjust this threshold 1 as needed
int emgThreshold2 = 300;    // Adjust this threshold 2 as needed
int emgThreshold3 = 400;    // Adjust this threshold 3 as needed
float emgFiltered = 0.0;    // Filtered EMG value
float alpha = 0.2;          // Filter coefficient
int delayTime = 40;         // Adjust the delay as needed
int pinLED1 = 10;           // Led 1
int pinLED2 = 11;           // Led 2
int pinLED3 = 12;           // Led 3

void setup() {
  Serial.begin(9600); 
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinLED3, OUTPUT);
}

void loop() {
  int emgValue = analogRead(emgPin); 

  // Apply the low-pass filter
  emgFiltered = (alpha * emgValue) + ((1 - alpha) * emgFiltered);

  if (emgFiltered > emgThreshold3) {
    digitalWrite(pinLED1, HIGH);
    digitalWrite(pinLED2, HIGH);
    digitalWrite(pinLED3, HIGH);
  }
  else if (emgFiltered > emgThreshold2) {
    digitalWrite(pinLED1, HIGH);
    digitalWrite(pinLED2, HIGH);
    digitalWrite(pinLED3, LOW);
  }
  else if (emgFiltered > emgThreshold1) {
    digitalWrite(pinLED1, HIGH);
    digitalWrite(pinLED2, LOW);
    digitalWrite(pinLED3, LOW);
  }
  else {
    digitalWrite(pinLED1, LOW);
    digitalWrite(pinLED2, LOW);
    digitalWrite(pinLED3, LOW);
  }

  Serial.println(emgFiltered);

  delay(delayTime); 
}