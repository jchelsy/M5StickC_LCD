#include <M5StickC.h>

/* define custom (16-bit) colors [uint16_t] */
/* ======================================== */
#define white           0xFFFF  // (255,255,255)
#define black           0x0000  // (0,0,0)

#define red             0xF800  // (255,0,0)
#define maroon          0xB000  // (180,0,0)
#define orange          0xFDA0  // (255,180,0)
#define dark_orange     0xE280  // (230,80,0)
#define gold            0xFEA0  // (255,215,0)
#define yellow          0xFFE0  // (255,255,0)
#define light_yellow    0xFFEC  // (255,255,100)
#define green           0x0400  // (0,130,0)
#define lime            0x07E0  // (0,255,0)
#define blue            0x001F  // (0,0,255)
#define deep_skyblue    0x065F  // (0,200,255)
#define light_skyblue   0x865F  // (130,200,250)
#define purple          0x8010  // (130,0,130)
#define magenta         0xF81F  // (255,0,255)


// initialize a boolean for button press detection
bool normalText = true;

// setup routine on startup (runs once):
void setup(){
  // initialize the M5StickC object (LCD screen)
  M5.begin();
  
  // rotate the display to landscape
  M5.Lcd.setRotation(1);
  
  /* set the LCD screen to display the default text */
  makeDefault();
}

// loop routine (runs repeatedly, forever):
void loop() {
  // update the M5StickC object (LCD screen)
  M5.update();
  
  // if Button A is pressed:
  if(M5.BtnA.isPressed()) {
    // if boolean 'normalText' is true:
    // (only change the screen once)
    // (if this isn't included, the screen will flash
    //  repeatedly, due to constant screen updates)
    if(normalText == true) {
      /* RAINBOW-FY the LCD display! */
      makeRainbow();
      
      // set the boolean 'normalText' to false
      // (so when the button is released, the statement
      //  below will set the screen back to the default)
      normalText = false;
    }
  }
  // otherwise (button not pressed):
  else {
    // if boolean 'normalText' is false:
    // (if the button was just released)
    if(normalText == false) { // LATER ADD: if(!normalText)
      /* Set the LCD screen back to default */
      makeDefault();
      
      // set the boolean 'normalText' back to true
      //  (so that the screen will change on the next button press)
      normalText = true;
    }
  }
}

/* Method to add a RAINBOW version of the text to the LCD display */
void makeRainbow() {
  /* add alternating rainbow colors ABOVE the text */
  M5.Lcd.fillRect( 0, 0,  160, 4, maroon    );
  M5.Lcd.fillRect( 0, 4,  160, 4, dark_orange );
  M5.Lcd.fillRect( 0, 8,  160, 4, yellow );
  M5.Lcd.fillRect( 0, 12, 160, 4, green  );
  M5.Lcd.fillRect( 0, 16, 160, 4, deep_skyblue   );
  M5.Lcd.fillRect( 0, 20, 160, 4, purple );
  
  /* add alternating rainbow colors BELOW the text */
  M5.Lcd.fillRect( 0, 56, 160, 4, purple );
  M5.Lcd.fillRect( 0, 60, 160, 4, deep_skyblue   );
  M5.Lcd.fillRect( 0, 64, 160, 4, green  );
  M5.Lcd.fillRect( 0, 68, 160, 4, yellow );
  M5.Lcd.fillRect( 0, 72, 160, 4, dark_orange );
  M5.Lcd.fillRect( 0, 76, 160, 4, maroon    );
  
  // set the text to write in the middle of
  // the screen and increase the text size
  M5.Lcd.setCursor(2, 27, 4);
  
  /* output a rainbow colored "Jonah" */
  M5.Lcd.setTextColor(maroon);        // red    "J"
  M5.Lcd.print("J");
  M5.Lcd.setTextColor(dark_orange);   // orange "o"
  M5.Lcd.print("o");
  M5.Lcd.setTextColor(gold);          // yellow "n"
  M5.Lcd.print("n");
  M5.Lcd.setTextColor(green);         // green  "a"
  M5.Lcd.print("a");
  M5.Lcd.setTextColor(blue);          // blue   "h"
  M5.Lcd.print("h");
  /* output a space */
  M5.Lcd.print(" ");                  //        " "
  /* output a rainbow colored "Chelsy" */
  M5.Lcd.setTextColor(red);           // red    "C"
  M5.Lcd.print("C");
  M5.Lcd.setTextColor(orange);        // orange "h"
  M5.Lcd.print("h");
  M5.Lcd.setTextColor(light_yellow);  // yellow "e"
  M5.Lcd.print("e");
  M5.Lcd.setTextColor(lime);          // green  "l"
  M5.Lcd.print("l");
  M5.Lcd.setTextColor(light_skyblue); // blue   "s"
  M5.Lcd.print("s");
  M5.Lcd.setTextColor(magenta);       // purple "y"
  M5.Lcd.print("y");
}

/* Method to add the default text to the LCD display */
void makeDefault() {
  // make the LCD background black
  M5.Lcd.fillScreen(black);
  
  // set the text to write in the middle of
  // the screen and increase the text size
  M5.Lcd.setCursor(2, 27, 4);
  // change text color
  M5.Lcd.setTextColor(white);
  
  // output "Jonah Chelsy" to the LCD screen
  M5.Lcd.print("Jonah Chelsy");
}
