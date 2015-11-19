int photoresistor_pin = A0;
void setup() {
  Serial.begin(9600);
 
}

void loop() {
 Serial.println(analogRead(photoresistor_pin));
 delay(100);
}
