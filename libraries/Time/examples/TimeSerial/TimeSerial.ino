/* 
 * TimeSerial.pde
 * example code illustrating Time library set through serial port messages.
 *
 * Messages consist of the letter T followed by ten digit time (as seconds since Jan 1 1970)
 * you can send the text on the next line using Serial Monitor to set the clock to noon Jan 1 2013
 T1357041600  
 *
 * A Processing example sketch to automatically send the messages is inclided in the download
 * On Linux, you can use "date +T%s\n > /dev/ttyACM0" (UTC time zone)
 */ 
 
#include <Time.h>  
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

// For the Adafruit shield, these are the default.
#define TFT_DC 9
#define TFT_CS 10

#define TIME_HEADER  "T"   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
int firstRun = 1;
int minuteUpdate;

void setup()  {
  //Serial.begin(9600);
  tft.begin();
  //while (!Serial) ; // Needed for Leonardo only
  pinMode(13, OUTPUT);
  int setSec = 30;
  int setMin = 40;
  int setHr = 4;
  int setDay = 14;
  int setMon = 5;
  int setYr = 2015;
  //********************************//
  setTime(setHr, setMin, setSec, setDay, setMon, setYr); // <---- SET TIME HERE!!!!
  //********************************//
  tft.fillScreen(ILI9341_BLACK);
  tft.fillRect(0, 0, tft.width(), 20, ILI9341_RED);
  minuteUpdate = setMin - 1;
  //setSyncProvider( requestSync);  //set function to call when sync required
  //Serial.println("Waiting for sync message");
}

void loop(){   
  /*
  if (Serial.available()) {
    processSyncMessage();
  } // Sync Arduino clock to the time received on the serial port
  */
  if (timeStatus()!= timeNotSet) {
    if (minute() != minuteUpdate) {
      digitalClockDisplay(); 
      minuteUpdate = minute();
    }
  }
  if (timeStatus() == timeSet) {
    digitalWrite(13, HIGH); // LED on if synced
  } else {
    digitalWrite(13, LOW);  // LED off if needs refresh
  }
  delay(1000);
}

void digitalClockDisplay(){
  // digital clock display of the time
  tft.setTextSize(2);
  
  tft.setCursor(20, 2),
  tft.print(hour());
  printDigits(minute());
  //printDigits(second());
  tft.print("    ");
  tft.print(month());
  tft.print("/");
  tft.print(day());
  tft.print("/");
  tft.print(year()); 
  tft.println(); 
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  tft.print(":");
  if(digits < 10)
    tft.print('0');
  tft.print(digits);
}


