#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(-1);

//int flexiForcePin1 = A1; //analog pin 1
//int flexiForcePin0 = A0;
int FLmax = 0;
int FRmax = 0;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
} 

  // Clear the buffer.
  display.clearDisplay();
  //pinMode(a1 ,INPUT);
  //pinMode(a0 ,INPUT);
  int FL=0;
  int FR = 0;
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int an0 = analogRead(A0);
  int an1 =analogRead(A1);
  
  
  int a0 = an0;
  int a1 = an1;
  float FR = ((4.851*pow(10,-7)*a0*a0*a0 )+ (-2.566*pow(10,-5)*a0*a0) + (.09215*a0)-0.04149 );
  float FL = ((4.061*pow(10,-7)*a1*a1*a1) -(-3.238*pow(10,-5)*a1*a1) +(.09604*a1) +0.06883);
  
  //int y[2]={FR , FL};
  
 
  
  
    if (FLmax < FL)
  {
    FLmax = FL;
  }
   if (FRmax < FR)
  {
    FRmax = FR;
  }
  
    Serial.print(FLmax);
   Serial.print(",");
   Serial.println(FRmax);
  
  //int z[2] = {FLmax, FRmax};
  //sending data via BT
  
 /* if(Serial.available()>0)
  {
   // Serial.write(y[2]);
    Serial.write(z[2]);
  }*/
  //display on oled
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("FL");
  display.setCursor(40, 0);
  display.print(FL);

  //display.display();
    display.setCursor(80,0);
    display.println(FLmax);
  ;
  

    display.setCursor(0,15);
  display.println("FR");
  
  display.setCursor(40,15);
  display.print(FR);
      

     display.setCursor(80,15);
    display.println(FRmax);
      display.display();
  
  delay(1);
  
  delay(1000);     
}
