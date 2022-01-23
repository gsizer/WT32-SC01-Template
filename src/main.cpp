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
const uint16_t ScreenWidth = 480;
const uint16_t ScreenHeight = 320;
const uint16_t ScreenRotation = 1;
const String Hardware = "WT32-SC01";

//********************************
// Global Objects
TFT_eSPI Display = TFT_eSPI();
FT62XXTouchScreen TouchPanel = FT62XXTouchScreen(ScreenHeight, PIN_SDA, PIN_SCL);
TouchPoint LastTouch;

//********************************
// Global Variables
uint32_t TouchCount = 0;
bool NeedRedraw = false;

//********************************
// BUTTON depends on Display and TouchPanel existing
// no error checking yet
class button{
  //********************************
  private:
    uint8_t _x, _y, _w, _h;
    const char *_label;
    void(*_callback)()=nullptr;
    //********
    void _press(){
      Display.fillRoundRect(_x, _y, _w, _h, 4, TFT_CYAN);
      Display.setTextColor(TFT_BLACK);
      Display.drawCentreString(_label, _x+(_w/2), _y+(_h/2), 4);
      (*_callback)();
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
    bool checkTouch(uint8_t x, uint8_t y){
      if(x>_x && x<(_x+_w)){
        // button laterally hit
        if( y>_y && y<(_y+_h)){
          // button vertically hit
          // execute code at callback
          _press();
          return true;
        }
      }
      _release();
      return false;
    }
};

//********************************
// put callback functions above button declarations so the address
// is in memory when being targeted as a callback

//********************************
// btnHOME callback
static void btnHOMEcb(){
  Display.fillRoundRect(84, 10, ScreenWidth-10, ScreenHeight-10, 4, TFT_DARKCYAN);
}

//********************************
// btnWIFI
static void btnWIFIcb(){
  Display.fillRoundRect(84, 10, ScreenWidth-10, ScreenHeight-10, 4, TFT_GREEN);
}

//********************************
// btnBTLE
static void btnBTLEcb(){
  Display.fillRoundRect(84, 10, ScreenWidth-10, ScreenHeight-10, 4, TFT_BLUE);
}

//********************************
// Screen Objects
enum scrNames { scrBTLE, scrWIFI, scrHOME };
scrNames CurrentScreen = scrHOME;

const char *btnLabels[3] = {"BTLE", "WIFI", "HOME"};
button btnBTLE = button(10, 10, 64, 64, btnLabels[0], &btnBTLEcb);
button btnWIFI = button(10, 84, 64, 64, btnLabels[1], &btnWIFIcb);
button btnHOME = button(10, 158, 64, 64, btnLabels[2], &btnHOMEcb);

//********************************
void setup(){
  // Hardware Display
  Display.init();
  Display.setRotation(ScreenRotation);
  Display.setTextColor(TFT_ORANGE);
  Display.fillScreen(TFT_BLACK);
  Display.drawCentreString(Hardware, ScreenWidth/2, ScreenHeight/2, 4);
  // Backlight
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
  // Touch Panel
  TouchPanel.begin();
  // GUI
  // attempt serial connection
  Serial.begin(115200);
  Serial.println("");
}

//********************************
void loop(){
  LastTouch = TouchPanel.read();
  if(LastTouch.touched){
    if(btnBTLE.checkTouch(LastTouch.xPos, LastTouch.yPos)){};
    if(btnWIFI.checkTouch(LastTouch.xPos, LastTouch.yPos)){};
    if(btnHOME.checkTouch(LastTouch.xPos, LastTouch.yPos)){};
  }
}
