#include "Arduino.h"

#define Vin 12 //*** Define the GPIO pin 12 as Vin ***
#define Vout 27  //*** Define the GPIO pin 27 as Vout ***
//#define Cal 14 //*** Define the GPIO pin 14 as the node for current calcultion ***

//float R = 22000.0; //*** Resistance in Mohm ***

float x;
float y;
// float c;

void setup() {

  Serial.begin(115200); //*** Define the data rate as 115200 ***
  pinMode(Vin, OUTPUT); //*** Set Vin as OUTPUT ***
  pinMode(Vout, INPUT); //*** Set Vout as INPUT ***
  // pinMode(Cal, INPUT); //*** Set Cal as INPUT ***
  
  delay(100);   //*** Set 100 ms delay ***
  //This task only needs to be done once, thus it is placed in setup().
  Serial.println("Duty Cycle (%), Vout (V)"); // display duty cycle,Vout for TASK 1 or I,Vout for Task 2 3 4
  for (int onPeriod = 0; onPeriod < 256; onPeriod++) 
    {
    
    analogWrite(Vin, onPeriod);// Output PWM at Vin      
    int Vout_value = analogRead(Vout); // read the voltage level at Vout 
    // int c_value = analogRead(Cal); // read the voltage level at the node for current calcultion  
    // c=  ;//calculate the voltage at the node for current calcultion  
    x = (onPeriod / 255.0) * 100.0; // calculate duty cycle for TASK 1 or the voltage at Vout in mV for Task 2 3 4
    y = (Vout_value * 3.3) / 4095.0; // calculate the voltage at Vout in V for TASK 1 or current in uA for Task 2 3 4
    Serial.print(x); 
    Serial.print(","); // seperate values by comma 
    Serial.println(y);
  }

  // Press reset button for a new sweep
}

void loop() {
  // Code for continuous operation can be added here
 
}
