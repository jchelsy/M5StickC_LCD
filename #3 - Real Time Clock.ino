#include <M5StickC.h>

// initialize time/date
RTC_TimeTypeDef RTC_TimeStruct;
RTC_DateTypeDef RTC_DateStruct;

// setup routine on startup (runs once):
void setup() {
  // initialize the M5StickC object (LCD screen)
  M5.begin();

  // rotate the display to landscape
  M5.Lcd.setRotation(1);

  // make the LCD background black
  M5.Lcd.fillScreen(BLACK);

  // initialize the time
  RTC_TimeTypeDef TimeStruct;
  // set starting clock time
  TimeStruct.Hours   = 10;
  TimeStruct.Minutes = 15;
  TimeStruct.Seconds = 45;

  // set the time with the given starting values
  M5.Rtc.SetTime(&TimeStruct);

  // initialize the date
  RTC_DateTypeDef DateStruct;
  // set the starting...
  DateStruct.WeekDay = 5; // weekday
  DateStruct.Month = 6;   // month
  DateStruct.Date = 5;    // day
  DateStruct.Year = 2020; // year

  // set the date with the given starting values
  M5.Rtc.SetData(&DateStruct);
}

// loop routine (runs repeatedly, forever):
void loop() {
  // get the updated date and time data    
  M5.Rtc.GetTime(&RTC_TimeStruct);
  M5.Rtc.GetData(&RTC_DateStruct);
  // set the text size (2x)  
  M5.Lcd.setTextSize(2);
  // set the cursor (text location/font)
  M5.Lcd.setCursor(14, 20, 4);
  // output the time
  M5.Lcd.printf("%02d:%02d\n",RTC_TimeStruct.Hours, RTC_TimeStruct.Minutes);

  // set the text size (2x)
  M5.Lcd.setTextSize(2);
  // set the cursor (text location/font)
  M5.Lcd.setCursor(20, 0, 1);
  // output the date
  M5.Lcd.printf("%04d-%02d-%02d\n",RTC_DateStruct.Year, RTC_DateStruct.Month,RTC_DateStruct.Date);

  // set the cursor (text location/font)
  M5.Lcd.setCursor(44, 64, 1);
  // output the weekday
  M5.Lcd.printf("Week:%d\n",RTC_DateStruct.WeekDay);

  // wait 1/2 sec before restarting loop
  delay(500);
}
