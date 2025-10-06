#include "Arduino.h"

#define Vin 12   //*** Define the GPIO pin 12 as Vin ***
#define Vout 27  //*** Define the GPIO pin 27 as Vout ***
#define Cal 14   //*** Define the GPIO pin 14 as the node for current calculation ***

float R = 22000.0 ; //*** Resistance in ohms (22kΩ) ***

float x;    // Vout voltage in mV
float y;    // Current in μA
float c1;   // Voltage at Vout in V
float c2;   // Voltage at Cal pin in V

void setup() {

  Serial.begin(115200); //*** Define the data rate as 115200 ***
  pinMode(Vin, OUTPUT); //*** Set Vin as OUTPUT ***
  pinMode(Vout, INPUT); //*** Set Vout as INPUT ***
  pinMode(Cal, INPUT);  //*** Set Cal as INPUT ***
  
  delay(100);   //*** Set 100 ms delay ***
  
  // This task only needs to be done once, thus it is placed in setup().
  Serial.println("Vout (mV), I (uA)"); // display Vout (mV), I (uA) for Task 2 3 4
  
  for (int onPeriod = 0; onPeriod < 256; onPeriod++) 
  {
    analogWrite(Vin, onPeriod); // Output PWM at Vin (8-bit resolution: 0-255)
    
    // Read voltage levels (ESP32 ADC: 12-bit resolution, 0-4095)
    int Vout_value = analogRead(Vout); // read the voltage level at Vout 0-3.3V → 0-4095
    int c_value = analogRead(Cal);     // read the voltage level at pin D14 0-3.3V → 0-4095
    
    // Convert ADC values back to voltage (0-3.3V)
    c1 = float(Vout_value * 3.3) / 4095.0 ; // Voltage at Vout in V
    c2 = float(c_value * 3.3) / 4095.0 ;    // Voltage at Cal pin in V
    
    // Calculate voltage at Vout in mV
    x = c1 * 1000.0 ; 
    
    // Calculate current using Ohm's law: I = (Vout - Vcal) / R
    // Convert to microamperes (μA)
    y = abs(c1 - c2) / R * 1000000.0 ; 
    
    // Print results
    Serial.print(x);     // print the voltage at Vout in mV
    Serial.print(","); 
    Serial.println(y);   // print the current in μA
  }

  Serial.println("Sweep completed. Press reset button for a new sweep.");
}

void loop() {
  // Code for continuous operation can be added here
  // Currently empty since the measurement is done once in setup()
}