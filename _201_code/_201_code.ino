#include <AFMotor.h>


AF_Stepper motor(200,2); //connect motor to port 2 ( M3 and M4)
const int sensorPin = A0; // pin number where we connect the photoresistor
const int button = 11; // pin number where we connect button

int buttonPressed = 0 ;// variable for reading the push button
int detect_block = 300; // value to compare with photoresistor reading
// to detect the block
int light = 0;  // variable for photoresistor reading
long start_time = 0, end_time= 0, time_ms = 0;
int speed_calculate ; // speed that we use to calculate distance
int length_lego = 0; // length of the lego
int num_step = 0; // keep count of number of step the stepper motor have done
                      
void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(sensorPin, INPUT);
  
  motor.setSpeed(15); //15 rpm
}

void loop() {
  buttonPressed = digitalRead(button); // reading the state of the push button

  if(buttonPressed == HIGH) //pressed
  { 

    while(num_step < 200)
    {
      motor.step(1, FORWARD, MICROSTEP); // move one step
      num_step ++;
      light = analogRead(sensorPin);
      while ( light < detect_block); // wait to detect block (do nothing while waiting)
    
      start_time = millis(); //record the start time

      while (light > detect_block); // wait to detect laser again

      end_time = millis();
      
    }
    time_ms = start_time - end_time; 
    // in millisecond, decide later if we need to convert it to second

    length_lego = time_ms*speed_calculate;
    // calculate the lego length
    Serial.println("The length of the block is ");
    Serial.print(length_lego);
    Serial.print("cm");

    motor.step(200, BACKWARD, MICROSTEP); // move back to start position
    
  }
}
