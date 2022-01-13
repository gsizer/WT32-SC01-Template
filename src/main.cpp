/******************************************************************************
||  ESP32 Development Board
||  Seeed Studio WT32-SC01
||  Template Project
******************************************************************************/
#include <Arduino.h>
// Graphical Display
#include <SPI.h>
#include <TFT_eSPI.h>
// Graphical User Interface
#include "esp_freertos_hooks.h"
#include <lvgl.h>
// Touch Interface
#include <Wire.h>
#include <FT62XXTouchScreen.h>

// System Variables
static const uint16_t ScreenWidth = TFT_WIDTH;
static const uint16_t ScreenHeight = TFT_HEIGHT;

// Global Objects
static TFT_eSPI Display = TFT_eSPI(ScreenWidth, ScreenHeight);
static lv_obj_t *HomeScreen;
static FT62XXTouchScreen TouchPanel = FT62XXTouchScreen(ScreenHeight, PIN_SDA, PIN_SCL);
static TouchPoint LastTouch;

static void cb_tick_task(void){
  LV_ATTRIBUTE_TICK_INC(portTICK_RATE_MS);
}

// HomeScreen event handler
static void cbEventHandler(lv_event_t *event){
  if(Serial.availableForWrite()){
    Serial.println("You Touched Me.");
  }
}

static void cbDisplayFlush(lv_disp_drv_t *displayDriver, const lv_area_t *area, lv_color_t *colorP){
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);
    Display.startWrite();
    Display.setAddrWindow(area->x1, area->y1, w, h);
    Display.pushColors((uint16_t*)&colorP->full, w * h, true);
    Display.endWrite();
    lv_disp_flush_ready(displayDriver);
}

static void cbTouchInput(lv_indev_drv_t *inputDriver, uint8_t event_id){
  TouchPoint touchPoint = TouchPanel.read();
  if(touchPoint.touched == true){
    // do something with touch point information
    LastTouch = touchPoint;
  }
  if(Serial.availableForWrite()){
    Serial.printf("at %u,%u\n", LastTouch.xPos, LastTouch.yPos);
  }
}

void setup(){
  // attempt serial connection
  Serial.begin(115200);
  esp_err_t err = esp_register_freertos_tick_hook((esp_freertos_tick_cb_t)cb_tick_task);
  // Hardware Display
  Display.init();
  Display.setRotation(1);
  // Backlight
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
  // LVGL Display Driver
  lv_init();
  static lv_color_t buffer[ScreenWidth*10];
  static lv_disp_draw_buf_t *lvDisplayBuffer;
  static lv_disp_drv_t lvDisplayDriver;
  lv_disp_draw_buf_init(lvDisplayBuffer, buffer, NULL, ScreenWidth*10);
  lv_disp_drv_init(&lvDisplayDriver);
  lvDisplayDriver.hor_res = 480;
  lvDisplayDriver.ver_res = 320;
  lvDisplayDriver.flush_cb = cbDisplayFlush;
  lvDisplayDriver.draw_buf = lvDisplayBuffer;
  lv_disp_drv_register(&lvDisplayDriver);
  // Touch Panel
  TouchPanel.begin();
  static lv_indev_drv_t *lvInputDevice;
  lv_indev_drv_init(lvInputDevice);
  lvInputDevice->type = LV_INDEV_TYPE_POINTER;
  lvInputDevice->feedback_cb = cbTouchInput;
  lvInputDevice->disp = lv_disp_get_default();
  lv_indev_drv_register(lvInputDevice);
  // Push HomeScreen
  HomeScreen = lv_obj_create(NULL);
  lv_obj_set_pos(HomeScreen, 0, 0);
  lv_obj_set_size(HomeScreen, ScreenWidth, ScreenHeight);
  lv_obj_add_event_cb(HomeScreen, cbEventHandler, LV_EVENT_ALL, NULL);
  lv_scr_load(HomeScreen);
}

void loop(){
  lv_task_handler();
  delay(1);
}
