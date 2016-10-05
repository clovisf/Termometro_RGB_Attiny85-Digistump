#include <Adafruit_NeoPixel.h>  
 #ifdef __AVR__  
  #include <avr/power.h>  
 #endif  
   
 // Which pin on the Arduino is connected to the NeoPixels?  
 #define PIN      0  
   
 // How many NeoPixels are attached to the Arduino?  
 #define NUMPIXELS   1  

 int sensorPin = A1;
 int sensorValue = 0;
 int Red, Green, Blue = 0;
   
 Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);  
   
 int delayval = 333; // delay  
   
 void setup() {  
   pixels.begin(); // This initializes the NeoPixel library.  
   pixels.setBrightness(80);
 }  
   
 void loop() {  
   
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.  
   
  for(int i=0;i<NUMPIXELS;i++){  

     sensorValue = (analogRead(sensorPin)- 194.3197) / 13.2447;
      
     if (sensorValue < 8){ //from total blue to green
      Blue = map(sensorValue, 0, 8, 255, 0);
      Green = map(sensorValue, 0, 8, 0, 255);
      Red = 0;
     }
     if ((sensorValue >= 8) &&(sensorValue < 30)) { // from green to yellow
     Green = 255;
     Red = map(sensorValue, 8, 30, 0, 255); 
     Blue = 0;
     }
     if (sensorValue >=30){ // yellow and up to red
      Red = 255;
      Green = map(sensorValue, 30, 45, 255, 0);
      Blue = 0;
      
     }
     
     //sensorValue = map(sensorValue, 0, 1023, 0, 255);     
   
   // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255  
   pixels.setPixelColor(i, pixels.Color(Red,Green,Blue)); // Moderately bright green color.  
   pixels.show(); // This sends the updated pixel color to the hardware.  
   delay(delayval); // Delay for a period of time (in milliseconds).  
  /* pixels.setPixelColor(i, pixels.Color(0,sensorValue,0)); // Moderately bright green color.  
   pixels.show(); // This sends the updated pixel color to the hardware.  
   delay(delayval); // Delay for a period of time (in milliseconds).  
   pixels.setPixelColor(i, pixels.Color(0,0,sensorValue)); // Moderately bright green color.  
   pixels.show(); // This sends the updated pixel color to the hardware.  
   delay(delayval); // Delay for a period of time (in milliseconds).  */
   
  }  
 }  