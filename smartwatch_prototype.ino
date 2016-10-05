/* EE 521 Project Code */

#include <Time.h>  
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include <boards.h>
#include <RBL_nRF8001.h>
#include "RBL_services.h"
#include <EEPROM.h>
#include <SimpleTimer.h>
#include <Wire.h>      // this is needed for FT6206
#include <Adafruit_FT6206.h>

// The FT6206 uses hardware I2C (SCL/SDA)
Adafruit_FT6206 ctp = Adafruit_FT6206();

// For the Adafruit shield, these are the default.
#define TFT_DC 9
#define TFT_CS 10
#define BOXSIZE 40
#define SYNC_BYTE 0xa5
byte g_RedVal = 0;
byte g_GreenVal = 0;
byte g_BlueVal = 0;

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
SimpleTimer disconnectionTimer;

int oldcolor, currentcolor;

int firstRun = 1;
int minuteUpdate;
int secondUpdate;
int hourUpdate;
int yearUpdate;
int monthUpdate;
int dayUpdate;

byte packet[5];
byte counter = 0;
int timerId;

int setSec = 0;
int setMin = 0;
int setHr = 4;
int setDay = 4;
int setMon = 6;
int setYr = 2015;

void setup()  {
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
  tft.fillRect(0, 0, tft.width(), 20, ILI9341_RED);
  pinMode(13, OUTPUT);
  setTime(setHr, setMin, setSec, setDay, setMon, setYr);
  secondUpdate = setSec - 1;
  
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(LSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  SPI.begin();
  if (! ctp.begin(40)) {  // pass in 'sensitivity' coefficient
    Serial.println("Couldn't start FT6206 touchscreen controller");
    while (1);
  }
  ble_set_name("WatchMe");
  ble_begin();
  //setColors();
  timerId = disconnectionTimer.setInterval(3000, checkDisconnect);
  
    // make the color selection boxes
  tft.fillRect(0, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_RED);
  tft.fillRect(BOXSIZE, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_YELLOW);
  tft.fillRect(BOXSIZE*2, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_GREEN);
  tft.fillRect(BOXSIZE*3, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_CYAN);
  tft.fillRect(BOXSIZE*4, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_BLUE);
  tft.fillRect(BOXSIZE*5, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_MAGENTA);
    // select the current color 'blue'
  tft.drawRect(BOXSIZE*4, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_WHITE);
  currentcolor = ILI9341_BLUE;
}

void loop(){   
  updateTime();
  doBluetooth();
  doColorchange();
}

void doBluetooth(){
  disconnectionTimer.run();
  
  while(ble_available())
  {
    for (byte i = 0; i < 4; i += 1)
    {
      packet[i] = packet[i + 1];
      disconnectionTimer.enable(timerId);
    }
    
    packet[4] = ble_read();
    counter += 1;
    
    // Packet Format
    // [Sync Byte, Red Value, Green Value, Blue Value, Checksum]
    if ((packet[0] == SYNC_BYTE) && (counter == 5))
    {
      byte checksum = packet[1] ^ packet[2] ^ packet[3];
      
      if (packet[4] == checksum)
      {
        g_RedVal = packet[1];
        g_GreenVal = packet[2];
        g_BlueVal = packet[3];
        
        setColors();
        
        counter = 0;
      }
    }
  }
  
  ble_do_events();
}

void updateTime() {
    if (timeStatus()!= timeNotSet) {
    if (year() != yearUpdate) {
      tft.fillRect(188, 0, 50, 20, ILI9341_RED);
      yearUpdate = year();
    }
    if (month() != monthUpdate) {
      tft.fillRect(115, 0, 25, 20, ILI9341_RED);
      monthUpdate = month();
    }
    if (day() != dayUpdate) {
      tft.fillRect(151, 0, 25, 20, ILI9341_RED);
      dayUpdate = day();
    }
    if (hour() != hourUpdate) {
      tft.fillRect(7, 0, 25, 20, ILI9341_RED);
      hourUpdate = hour();
    }
    if (minute() != minuteUpdate) {
      tft.fillRect(43, 0, 25, 20, ILI9341_RED);
      minuteUpdate = minute();
    }
    if (second() != secondUpdate) { 
      tft.fillRect(79, 0, 25, 20, ILI9341_RED);
      digitalClockDisplay(); 
      secondUpdate = second();
    }
  }
  if (timeStatus() == timeSet) {
    digitalWrite(13, HIGH); // LED on if synced
  } else {
    digitalWrite(13, LOW);  // LED off if needs refresh
  }
}

void digitalClockDisplay(){
  // digital clock display of the time
  tft.setTextSize(2);
  tft.setCursor(8, 2);
  if(hour() < 10)
    tft.print(' ');
  tft.print(hour());
  printDigits(minute());
  printDigits(second());
  tft.print(' ');
  if(month() < 10)
    tft.print(' ');
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

void checkDisconnect()
{
  if (!ble_connected())
  {
    //g_RedVal = 255;
    //g_GreenVal = 255;
    //g_BlueVal = 255;
    
    phoneDisconnected();
    
    disconnectionTimer.disable(timerId);
  }
}

void setColors()
{
  if (g_BlueVal >= 99) {
      tft.fillRect(79, 120, 80, 90, currentcolor);
      tft.fillRect(109, 130, 20, 50, ILI9341_WHITE);
      tft.fillRect(109, 185, 20, 10, ILI9341_WHITE);
      tft.setTextSize(.6);
      tft.setCursor(92, 199);
      tft.print("CONNECTED");
      delay(5000);
      tft.fillRect(79, 120, 80, 90, ILI9341_BLACK);
  }
    if (g_RedVal >= 99) {
      tft.fillRect(79, 120, 80, 90, currentcolor);
      tft.fillRect(109, 130, 20, 50, ILI9341_WHITE);
      tft.fillRect(109, 185, 20, 10, ILI9341_WHITE);
      tft.setTextSize(.6);
      tft.setCursor(86, 199);
      tft.print("NEW MESSAGE");
      delay(5000);
      tft.fillRect(79, 120, 80, 90, ILI9341_BLACK);
  }
    if (g_GreenVal >= 99) {
      tft.fillRect(79, 120, 80, 90, currentcolor);
      tft.fillRect(109, 130, 20, 50, ILI9341_WHITE);
      tft.fillRect(109, 185, 20, 10, ILI9341_WHITE);
      tft.setTextSize(.6);
      tft.setCursor(86, 199);
      tft.print("NEW MESSAGE");
      delay(5000);
      tft.fillRect(79, 120, 80, 90, ILI9341_BLACK);
  }
}

void phoneDisconnected()
{
      tft.fillRect(62, 120, 113, 90, ILI9341_RED);
      tft.fillRect(109, 130, 20, 50, ILI9341_WHITE);
      tft.fillRect(109, 185, 20, 10, ILI9341_WHITE);
      tft.setTextSize(.6);
      tft.setCursor(64, 199);
      tft.print("PHONE DISCONNECTED");
      delay(5000);
      tft.fillRect(62, 120, 113, 90, ILI9341_BLACK);
}

void doColorchange(){
    // Wait for a touch
  if (! ctp.touched()) {
    return;
  }

  // Retrieve a point  
  TS_Point p = ctp.getPoint();
    // flip it around to match the screen.
  p.x = map(p.x, 0, 240, 240, 0);
  p.y = map(p.y, 0, 320, 320, 0);
  if (p.y > tft.height()-BOXSIZE) {
     oldcolor = currentcolor;

     if (p.x < BOXSIZE) { 
       currentcolor = ILI9341_RED; 
       tft.drawRect(0, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_WHITE);
     } else if (p.x < BOXSIZE*2) {
       currentcolor = ILI9341_YELLOW;
       tft.drawRect(BOXSIZE, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_WHITE);
     } else if (p.x < BOXSIZE*3) {
       currentcolor = ILI9341_GREEN;
       tft.drawRect(BOXSIZE*2, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_WHITE);
     } else if (p.x < BOXSIZE*4) {
       currentcolor = ILI9341_CYAN;
       tft.drawRect(BOXSIZE*3, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_WHITE);
     } else if (p.x < BOXSIZE*5) {
       currentcolor = ILI9341_BLUE;
       tft.drawRect(BOXSIZE*4, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_WHITE);
     } else if (p.x <= BOXSIZE*6) {
       currentcolor = ILI9341_MAGENTA;
       tft.drawRect(BOXSIZE*5, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_WHITE);
     }

     if (oldcolor != currentcolor) {
        if (oldcolor == ILI9341_RED) 
          tft.fillRect(0, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_RED);
        if (oldcolor == ILI9341_YELLOW) 
          tft.fillRect(BOXSIZE, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_YELLOW);
        if (oldcolor == ILI9341_GREEN) 
          tft.fillRect(BOXSIZE*2, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_GREEN);
        if (oldcolor == ILI9341_CYAN) 
          tft.fillRect(BOXSIZE*3, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_CYAN);
        if (oldcolor == ILI9341_BLUE) 
          tft.fillRect(BOXSIZE*4, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_BLUE);
        if (oldcolor == ILI9341_MAGENTA) 
          tft.fillRect(BOXSIZE*5, tft.height()-BOXSIZE, BOXSIZE, BOXSIZE, ILI9341_MAGENTA);
     }
  }
}

