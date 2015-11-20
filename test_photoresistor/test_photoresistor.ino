int photoresistor_pin = A0;
int buttonPin = 8;
void setup() {
  Serial.begin(9600);
  //pinMode(buttonPin, INPUT);
  pinMode(photoresistor_pin, INPUT);
  
 
}

void loop() {
 //while( digitalRead(buttonPin) == HIGH)
 //{
  
    Serial.println(analogRead(photoresistor_pin));
    delay(150);
 //}


 
}
