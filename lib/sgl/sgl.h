#ifndef SGL_H
#define SGL_H

#define FONT_SMALL 1 // 8px
#define FONT_REGULAR 2 // 16px
#define FONT_LARGE 4 // 26px
#define FONT_CLOCK 6 // 48px

#include <stdint.h>

class sgl{
  private:
    char *_labelText;
    uint8_t _x, _y, _w, _h;
    uint32_t _primary, _secondary, _highlight, _notice;
  public:
    sgl(uint8_t x, uint8_t y, uint8_t w, uint8_t h);
    void sgl::sgl_set_pos(uint8_t x, uint8_t y);
    void sgl::sgl_set_size(uint8_t w, uint8_t h);
    void sgl::sgl_set_label(char *labelText);
    void sgl::sgl_set_theme(uint32_t p, uint32_t s, uint32_t h, uint32_t n);
};

sgl::sgl(uint8_t x = 0, uint8_t y = 0, uint8_t w = 480, uint8_t h = 320){
  _x=x;
  _y=y;
  _w=w;
  _h=h;
}

void sgl::sgl_set_pos(uint8_t x, uint8_t y){
  _x=x;
  _y=y;
}

void sgl::sgl_set_size(uint8_t w, uint8_t h){
  _w=w;
  _h=h;
}

void sgl::sgl_set_label(char *labelText){
  _labelText = labelText;
}

void sgl::sgl_set_theme(uint32_t primary, uint32_t secondary, uint32_t highlight, uint32_t notice){
  _primary=primary;
  _secondary=secondary;
  _highlight=highlight;
  _notice=notice;
}
#endif // SGL_H
