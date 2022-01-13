/******************************************************************************
||  ESP32 Development Board
||  Seeed Studio WT32-SC01
||  Template Project
******************************************************************************/
#include <Arduino.h>
// Graphical Display
#include <SPI.h>
#include <TFT_eSPI.h>
// Touch Interface
#include <Wire.h>
#include <FT62XXTouchScreen.h>

// System Variables
static const uint16_t ScreenWidth = TFT_WIDTH;
static const uint16_t ScreenHeight = TFT_HEIGHT;

// Global Objects
static TFT_eSPI Display = TFT_eSPI(ScreenWidth, ScreenHeight);
static FT62XXTouchScreen TouchPanel = FT62XXTouchScreen(ScreenHeight, PIN_SDA, PIN_SCL);
static TouchPoint LastTouch;

void setup(){
  // attempt serial connection
  Serial.begin(115200);
  // Hardware Display
  Display.init();
  Display.setRotation(1);
  Display.fillScreen(TFT_BLACK);
  // Backlight
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
  // Touch Panel
  TouchPanel.begin();
}

void loop(){
  delay(10);
  LastTouch = TouchPanel.read();
  if(Serial.availableForWrite() && LastTouch.touched){
    Serial.printf("Touched at %u:%u\n", LastTouch.xPos, LastTouch.yPos);
  }
}
