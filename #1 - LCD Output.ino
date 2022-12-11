#include <M5StickC.h>

// setup routine on startup (runs once):
void setup(){
  // initialize the M5StickC object (LCD screen)
  M5.begin();
  
  // rotate the display to landscape
  M5.Lcd.setRotation(1);
  
  // make the LCD background white
  M5.Lcd.fillScreen(WHITE);
  
  // set the text to write in the middle of
  // the screen and increase the text size
  M5.Lcd.setCursor(2, 30, 4);
  // change the text color
  M5.Lcd.setTextColor(BLACK);
  
  // output "Jonah Chelsy" to the LCD screen
  M5.Lcd.print("Jonah Chelsy");
}

// loop routine (runs repeatedly, forever):
void loop() {
  // empty
}
