/******************************************************************************
||  ESP32 Development Board
||  Seeed Studio WT32-SC01
||  Template Project
******************************************************************************/
#include <Arduino.h>
// TouchPanel
#include <Wire.h>
#include <FT62XXTouchScreen.h>
// Graphical Display
#include <SPI.h>
#include <TFT_eSPI.h>
// Graphical Interface
#include <lvgl.h>

// Environment Variables
static const uint16_t ScreenWidth = TFT_WIDTH;
static const uint16_t ScreenHeight = TFT_HEIGHT;

// DisplayDriver
static lv_disp_drv_t *lvDispDrv;
static lv_disp_t *lvDisplay;
static lv_disp_draw_buf_t lvDrawBuf;
static lv_color_t lvBuffer[ScreenWidth*10];

// Dummy InputDriver for LVGL
static lv_indev_drv_t lvIndevDrv;

static FT62XXTouchScreen TouchPanel = FT62XXTouchScreen(ScreenHeight, (uint8_t)PIN_SDA, (uint8_t)PIN_SCL);
static TFT_eSPI Display = TFT_eSPI(ScreenWidth, ScreenHeight);

// callback for LVGL to flush display memory
void cbFlushDisplay(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_ptr){
  uint32_t w = ( area->x2 - area->x1 + 1 );
  uint32_t h = ( area->y2 - area->y1 + 1 );
  Display.startWrite();
  Display.setAddrWindow( area->x1, area->y1, w, h );
  Display.pushColors( (uint16_t *)&color_ptr->full, w * h, true );
  Display.endWrite();
  lv_disp_flush_ready(drv);
}

// callback for LVGL to handle TouchPanel input
void cbReadTouch(lv_indev_drv_t *driver, lv_indev_data_t *data){
  TouchPoint point =TouchPanel.read();
  if(point.touched){
    data->state = LV_INDEV_STATE_PR;
    data->point.x = point.xPos;
    data->point.y = point.yPos;
  }else{
    data->state = LV_INDEV_STATE_REL;
  }
}

void setup() {
  // open SerialPort
  Serial.begin(115200);

  // initialize Display using TFT_eSPI
  Display.init();
  Display.setRotation(1); // USB-C port to right-bottom
  pinMode(TFT_BL, OUTPUT); // setup backlight
  digitalWrite(TFT_BL, HIGH); // enable backlight

  // initialize LVGL
  lv_init();

  // initialize DisplayDriver
  lv_disp_drv_init(lvDispDrv);
  lvDispDrv->hor_res = ScreenWidth;
  lvDispDrv->ver_res = ScreenHeight;
  lvDispDrv->flush_cb = cbFlushDisplay;
  lvDispDrv->draw_buf = &lvDrawBuf;
  lv_disp_drv_register(lvDispDrv);
  lv_disp_draw_buf_init(&lvDrawBuf, lvBuffer, NULL, ScreenWidth*10);
  lv_disp_set_default(lvDisplay);

  // initialize TouchPanel
  lv_indev_drv_init(&lvIndevDrv);
  lvIndevDrv.type = LV_INDEV_TYPE_POINTER;
  lvIndevDrv.read_cb = cbReadTouch;
}

// let LVGL handle most things
void loop() {
  lv_timer_handler();
  delay(5);
}
