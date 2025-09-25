#include "Arduino.h"

#define Vin  //*** Define the GPIO pin 12 as Vin ***
#define Vout   //*** Define the GPIO pin 27 as Vout ***
//#define Cal //*** Define the GPIO pin 14 as the node for current calcultion ***

//float R = ; //*** Resistance in Mohm ***

float x;
float y;
// float c;

void setup() {

  Serial.begin(); //*** Define the data rate as 115200 ***
  pinMode(Vin, ); //*** Set Vin as OUTPUT ***
  pinMode(Vout, ); //*** Set Vout as INPUT ***
  // pinMode(Cal, ); //*** Set Cal as INPUT ***
  
  delay();   //*** Set 100 ms delay ***
  //This task only needs to be done once, thus it is placed in setup().
  Serial.println(" "); // display duty cycle,Vout for TASK 1 or I,Vout for Task 2 3 4
  for (int onPeriod = 0; onPeriod < 256; onPeriod++) 
    {
    
    analogWrite( ,onPeriod);// Output PWM at Vin      
    int Vout_value = analogRead(); // read the voltage level at Vout 
    // int c_value = analogRead(); // read the voltage level at the node for current calcultion  
    // c=  ;//calculate the voltage at the node for current calcultion  
    x =  ; // calculate duty cycle for TASK 1 or the voltage at Vout in mV for Task 2 3 4
    y =  ; // calculate the voltage at Vout in V for TASK 1 or current in uA for Task 2 3 4
    Serial.print(x); 
    Serial.print(","); // seperate values by comma 
    Serial.println(y);
  }

  // Press reset button for a new sweep
}

void loop() {
  // Code for continuous operation can be added here
 
}
git commit -m "Initial commit
