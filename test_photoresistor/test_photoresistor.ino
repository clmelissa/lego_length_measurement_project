int photoresistor_pin = A0;
int buttonPin = 7;
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(photoresistor_pin, INPUT);
  
 
}

void loop() {
 if (digitalRead(buttonPin == HIGH))
 {
  for (int i  ; i< 500;i++)
  {
    Serial.println(analogRead(photoresistor_pin));
    delay(100);
  }
 }

 delay(200);
 
}
