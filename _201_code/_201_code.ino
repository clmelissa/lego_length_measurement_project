#include <AFMotor.h>


AF_Stepper motor(200,1); //connect motor to port 2 ( M1 and M2)
const int sensorPin = A0; // pin number where we connect the photoresistor
const int button = 11; // pin number where we connect button

int buttonPressed = 0 ; // variable for reading the push button
int detect_block = 300; // value to compare with photoresistor reading
// to detect the block
int light = 0;  // variable for photoresistor reading
long start_time = 0, end_time= 0;
double time_ = 0;
double speed_calculate = 3.35 ; // speed that we use to calculate distance
double length_lego = 0; // length of the lego
int num_step = 0; // keep count of number of step the stepper motor have done
bool start_lego = false;
bool end_lego = false;

                      
void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(sensorPin, INPUT);
  
  motor.setSpeed(10); //15 rpm
}

void loop() {
 // buttonPressed = digitalRead(button); // reading the state of the push button

 // if(buttonPressed == HIGH) //pressed
 // { 
    while(!end_lego)
    {
      motor.step(1, FORWARD, MICROSTEP); // move one step
      num_step ++;
      light = analogRead(sensorPin);
      if (light < 300 && !start_lego)
      {
        start_lego = true;
        start_time = millis(); //record the start time
      }
      if ( light > 300 && start_lego )
      {
        end_lego = true;
        end_time = millis();
      }
      
      
    }
    time_ = (end_time - start_time)/ 1000.00; 
    // in millisecond, decide later if we need to convert it to second

    length_lego = time_*speed_calculate;
    // calculate the lego length
    Serial.println (time_);
    Serial.println (start_time);
    Serial.println (end_time);
    Serial.print("The length of the block is ");
    Serial.print(length_lego);
    Serial.println(" cm");
    end_lego = false;
    start_lego= false;
    motor.step(80, BACKWARD, MICROSTEP); // move back to start position
    delay (400000);
  //}
}
