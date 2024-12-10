
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define NUMFLAKES     10 // Number of snowflakes in the animation example

#include <Bonezegei_HCSR04.h>
const int TRIGGER_PIN = D6;
const int ECHO_PIN = D7;

Bonezegei_HCSR04 ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
 
}
void loop() {
    display.clearDisplay();

     int d=ultrasonic.getDistance();
  Serial.print("Distance:");
  Serial.print(d);
  Serial.println(" cm");
  delay(100);

    // Big text
    display.setTextSize(2);  // Larger text
    display.setTextColor(SSD1306_WHITE);
    
    display.setCursor(0, 0);
    display.println("Distance:");

    
    display.setCursor(0, 20);
    display.print(d);
    display.print(" cm");

   

    display.display();  // Show the content on the display
    
}
