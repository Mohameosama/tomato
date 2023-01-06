#include <Arduino.h>
#include <Wire.h>      
#include <DHT.h> 

// Temperature PINS
#define DHTPIN PA2 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE); 

// Gas PINS
#define AOUT PA0
#define DOUT PA4


// Touch SENSOR
#define TouchPin PA5

// Output PINS
#define Gas PA11 
#define Fire PB11
#define Touch PB3

void setup() {

  
    pinMode(DOUT, INPUT);   
    pinMode(Fire,OUTPUT);  
    pinMode(Touch,OUTPUT);
    pinMode(Gas, OUTPUT); 
    pinMode(TouchPin, INPUT);      

}

void loop() {


   
    int touchValue = digitalRead(TouchPin);

    float humidValue = dht.readHumidity();   

    float tempValue = dht.readTemperature();   

    int gasValue = analogRead(AOUT)/(4095) * 5;    // to convert the value into volts

    int gaslimit = digitalRead(DOUT); 


        // SEND DATA TO THE PI THROUGH DIGITAL OUTPUT PINS


    if (gaslimit == HIGH){

        digitalWrite(Gas, HIGH);

    }
    else{
        digitalWrite(Gas, LOW);
    }

    if (touchValue == HIGH)
    {   
        
        digitalWrite(Touch, HIGH);
    }
    else
    {
        digitalWrite(Touch, LOW);
    }

    if (tempValue >= 35)
    {
            digitalWrite(Fire,HIGH);

    }
    else{
            digitalWrite(Fire,LOW);

    }
    


}