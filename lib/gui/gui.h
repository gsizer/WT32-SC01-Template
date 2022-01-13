#ifndef GUI_H
#define GUI_H
#include <stdint.h>

class gui{
  private:
    uint8_t _x = 0, _y = 0, _w = 480, _h = 320;
  public:
    gui(uint8_t width, uint8_t height);
    void setPosition(uint8_t x, uint8_t y);
    void setSize(uint8_t w, uint8_t h);
};

gui::gui(uint8_t width, uint8_t height){
  _x=0;
  _y=0;
  _w=width;
  _h=height;
}

void gui::setPosition(uint8_t x, uint8_t y){
  _x=x;
  _y=y;
}

void gui::setSize(uint8_t w, uint8_t h){
  _w=w;
  _h=h;
}

#endif // GUI_H
