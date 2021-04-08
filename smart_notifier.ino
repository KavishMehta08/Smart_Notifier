#include <SoftwareSerial.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_SSD1306.h>
#include<Fonts\FreeSansBold18pt7b.h>
#include<Fonts\FreeMono9pt7b.h>
#include<Fonts\FreeSerif9pt7b.h>
#include <Wire.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

SoftwareSerial notifier(0, 1);
String datee, timee, week;
float pressLength_milliSeconds = 0;
 
int optionOne_milliSeconds = 100;
int optionTwo_milliSeconds = 500;        
 

int buttonPin = 7; 
char recvchar;
String recvchar1;
int c;
String c1;
int x = 0, y =0;


 
void setup(){
 
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
   display.display();
  delay(2000);
  display.clearDisplay();
  //display.setFont(&FreeSansBold18pt7b);
  display.setTextSize(2.0);
  display.setTextColor(WHITE);
  display.setCursor(16,16);
  display.print("Hello");
   display.setTextSize(2.0);
  display.setTextColor(WHITE);
  display.setCursor(16,34);
  display.print("WELCOME");
  
  display.display();
  pinMode(buttonPin, INPUT_PULLUP);     
 notifier.begin(9600);
 } 
 
 
void loop() {
  
 recvchar = notifier.read();
  while (digitalRead(buttonPin) == LOW ){ 
 
    delay(100);
    pressLength_milliSeconds = pressLength_milliSeconds + 100;   
 }
if (pressLength_milliSeconds >= optionTwo_milliSeconds){
   
    notifier.write('y');
  datee = notifier.readString();
 display.clearDisplay();
  display.setFont(&FreeSerif9pt7b);
  display.setTextSize(1.0);
  display.setTextColor(WHITE);
  display.setCursor(0,12);
  display.print(datee);
 display.display();
 delay(3000);
  display.clearDisplay();
  display.display();
 
     } 
 
  
  else if(pressLength_milliSeconds >= optionOne_milliSeconds){
  notifier.write('x');
  recvchar1 = notifier.readString();
   display.clearDisplay();
  display.setFont(&FreeSerif9pt7b);
  display.setTextSize(1.0);
  display.setTextColor(WHITE);
  display.setCursor(0,12);
  display.print("NO.OF STEPS :");
  display.setFont(&FreeMono9pt7b);
  display.setTextSize(1.0);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
  display.print(recvchar1);
   display.display();
  delay(3000);
  display.clearDisplay();
  display.display();
  }

  if(recvchar == 'I') {
    display.clearDisplay();
   display.setFont(&FreeMono9pt7b);
  display.setTextSize(1.0);
  display.setTextColor(WHITE);
  display.setCursor(0,12);
  display.print("CALL FROM :");
  display.display();
  recvchar1 = notifier.readString();
  display.setTextSize(1.0);
  display.setTextColor(WHITE);
  display.setFont(&FreeSerif9pt7b);
  display.setCursor(0,34);
  display.print(recvchar1);
  display.display();
  

 }

  else if(recvchar == 'M'){
    display.clearDisplay();
    display.setTextSize(1.0);
  display.setTextColor(WHITE);
  display.setFont(&FreeMono9pt7b);
  display.setCursor(0,12);
  display.print("Missed call!");
   display.setTextSize(1.0);
  display.setTextColor(WHITE);
 display.setFont(&FreeSerif9pt7b);
  display.setCursor(0,34);
  display.print(recvchar1);
  display.display();
  
  
  }
  else if(recvchar == 'J')
  {
     display.clearDisplay();
  display.setFont(&FreeSerif9pt7b);
  display.setTextSize(1.0);
  display.setTextColor(WHITE);
  display.setCursor(0,30);
  display.print("MOTION");
  display.setCursor(0,50);
  display.print("DETECTED");
  display.display();
    
    }

pressLength_milliSeconds = 0;
 
                 
 
}
