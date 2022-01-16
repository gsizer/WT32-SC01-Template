/******************************************************************************
||  ESP32 Development Board
||  Seeed Studio WT32-SC01
||  Template Project
******************************************************************************/
#include <Arduino.h>
// Touch Panel
#include <Wire.h>
#include <FT62XXTouchScreen.h>
// Graphical Display
#include <SPI.h>
#include <TFT_eSPI.h>

// System Constants
const uint16_t ScreenWidth = 320;
const uint16_t ScreenHeight = 480;

// Global Objects
TFT_eSPI Display = TFT_eSPI(ScreenWidth, ScreenHeight);
FT62XXTouchScreen TouchPanel = FT62XXTouchScreen(ScreenWidth, PIN_SDA, PIN_SCL);
TouchPoint LastTouch;

// Global Variables
uint32_t TouchCount = 0;

void setup(){
  // Hardware Display
  Display.init();
  Display.setRotation(1);
  Display.setTextColor(TFT_ORANGE);
  Display.fillScreen(TFT_BLACK);
  // Backlight
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
  // Touch Panel
  TouchPanel.begin();
  // attempt serial connection
  Serial.begin(115200);
  Serial.println("");
}

void loop(){
  LastTouch = TouchPanel.read();
  if(LastTouch.touched){
    // log it
    TouchCount++;
    Serial.printf("Touch: %u at %u:%u\n", TouchCount, LastTouch.xPos, LastTouch.yPos);
  }
  delay(10);
}
