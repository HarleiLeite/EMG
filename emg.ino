int emgPin = A0;         
             
int emgThreshold = 30;    // Adjust this threshold as needed
float emgFiltered = 0.0;  // Filtered EMG value
float alpha = 0.2;        // Filter coefficient
int delayTime = 40;       // Adjust the delay as needed
int pinLED = 12;

void setup() {
  Serial.begin(9600); 
  pinMode(pinLED, OUTPUT);
}

void loop() {
  int emgValue = analogRead(emgPin); 

  // Apply the low-pass filter
  emgFiltered = (alpha * emgValue) + ((1 - alpha) * emgFiltered);

  if (emgFiltered > emgThreshold) {
   
    digitalWrite(pinLED, HIGH);
  } else {
    
    digitalWrite(pinLED, LOW);
  }

  Serial.println(emgFiltered);

  delay(delayTime); 
}