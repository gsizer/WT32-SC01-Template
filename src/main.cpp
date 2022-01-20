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

//********************************
// System Constants
const uint16_t ScreenWidth = 320;
const uint16_t ScreenHeight = 480;

//********************************
// Global Objects
TFT_eSPI Display = TFT_eSPI(ScreenWidth, ScreenHeight);
FT62XXTouchScreen TouchPanel = FT62XXTouchScreen(ScreenWidth, PIN_SDA, PIN_SCL);
TouchPoint LastTouch;

//********************************
// Global Variables
uint32_t TouchCount = 0;

//********************************
// BUTTON_H depends on Display and TouchPanel existing
// no error checking yet
class button{
  //********************************
  private:
    uint8_t _x, _y, _w, _h;
    const char *_label;
    void(*_callback)()=nullptr;
    //********
    void _press(){
      Display.drawRoundRect(_x, _y, _w, _h, 4, TFT_CYAN);
      Display.setTextColor(TFT_BLACK);
      Display.drawCentreString(_label, _x+(_w/2), _y+(_h/2), 4);
    }
    //********
    void _release(){
      Display.fillRoundRect(_x, _y, _w, _h, 4, TFT_DARKCYAN);
      Display.setTextColor(TFT_BLACK);
      Display.drawCentreString(_label, _x+(_w/2), _y+(_h/2), 4);
    }
  //********************************
  public:
    //********
    button(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const char *l, void(*callback)()){
      _x=x;
      _y=y;
      _w=w;
      _h=h;
      _label=l;
      _callback=callback;
      _release();
    }
    //********
    void checkTouch(uint8_t x, uint8_t y){
      if(x>_x && x<(_x+_w)){
        // button laterally hit
        if( y>_y && y<(_y+_h)){
          // button vertically hit
          // execute code at callback
          _press();
          (*_callback)();
        }
      }
      _release();
    }
};

//********************************
// put callback functions above button declarations so the address
// is in memory when being targeted as a callback

//********************************
// logPress
static void logPress(){
  TouchCount++;
  if(Serial.availableForWrite()){
    Serial.printf("Touch %u at %u:%u\n", TouchCount, LastTouch.xPos, LastTouch.yPos);
  }
}

//********************************
// Screen Objects
const char *labels[3] = {"BTLE", "WIFI", "HOME"};

button btnBTLE = button(10, 10, 64, 64, labels[0], &logPress);
button btnWIFI = button(10, 84, 64, 64, labels[1], &logPress);
button btnHOME = button(10, 158, 64, 64, labels[2], &logPress);

//********************************
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

//********************************
void loop(){
  LastTouch = TouchPanel.read();
  if(LastTouch.touched){
    btnBTLE.checkTouch(LastTouch.xPos, LastTouch.yPos);
    btnWIFI.checkTouch(LastTouch.xPos, LastTouch.yPos);
    btnHOME.checkTouch(LastTouch.xPos, LastTouch.yPos);
  }
  delay(100);
}
