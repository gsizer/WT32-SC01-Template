/******************************************************************************
||  ESP32 Development Board
||  Seeed Studio WT32-SC01
||  Template Project
******************************************************************************/
#include <Arduino.h>
static const uint16_t ScreenWidth = 480;
static const uint16_t ScreenHeight = 320;
static const bool psRAMFound = psramFound();

// TouchPanel
#include <Wire.h>
#include <FT62XXTouchScreen.h>
FT62XXTouchScreen TouchPanel = FT62XXTouchScreen(ScreenHeight, (uint8_t)PIN_SDA, (uint8_t)PIN_SCL);

// Graphical Display
#include <SPI.h>
#include <TFT_eSPI.h>
TFT_eSPI Display = TFT_eSPI(ScreenWidth, ScreenHeight);

// Graphical Interface
#include <lvgl.h>

// DisplayDriver
static lv_disp_drv_t *lvDispDrv;
static lv_disp_t *lvDisplay;
static lv_disp_draw_buf_t lvDrawBuf;
static lv_color_t lvBuffer[ScreenWidth*10];

// Dummy InputDriver for LVGL
static lv_indev_drv_t lvIndevDrv;

// callback for LVGL to flush display memory
void cbFlushDisplay(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_ptr){
  uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );
    Display.startWrite();
    Display.setAddrWindow( area->x1, area->y1, w, h );
    Display.pushColors( ( uint16_t * )&color_ptr->full, w * h, true );
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
  // open USB-Serial port
  Serial.begin(115200);

  // initialize Display
  Display.init();
  Display.setRotation(1); // USB-C port to right-bottom
  Display.fillScreen(TFT_BLACK); // flush the memory
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
  lv_disp_draw_buf_init(&lvDrawBuf, lvBuffer, NULL, );
  lv_disp_set_default(lvDisplay);

  // initialize TouchPanel
  lv_indev_drv_init(&lvIndevDrv);
  lvIndevDrv.type = LV_INDEV_TYPE_POINTER;
  lvIndevDrv.read_cb = cbReadTouch;
  lv_indev_drv_register(&lvIndevDrv);
}

void loop() {
  // wait only as long as needed by LVGL timers
  delay(lv_timer_handler());
}
