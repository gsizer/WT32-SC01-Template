/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include <lvgl.h>
#endif

#ifndef FONTALTERNITY16
#define FONTALTERNITY16 1
#endif

#if FONTALTERNITY16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0021 "!" */
    0xff, 0xfc, 0x3c,

    /* U+0022 "\"" */
    0xde, 0xf7, 0x20,

    /* U+0023 "#" */
    0x33, 0x7f, 0xff, 0xe6, 0x3, 0x37, 0xff, 0xfe,
    0x66, 0x33, 0x0,

    /* U+0024 "$" */
    0x6, 0x6, 0xdd, 0xdb, 0xb3, 0x6, 0x60, 0xcc,
    0xd, 0xb0, 0x33, 0x6, 0x60, 0xcf, 0xdb, 0xfb,
    0x60,

    /* U+0025 "%" */
    0x79, 0xfe, 0x6d, 0x33, 0x58, 0xee, 0x13, 0x61,
    0x9c, 0xeb, 0x74, 0xd9, 0xfc, 0x78,

    /* U+0026 "&" */
    0xfe, 0xf, 0xe0, 0xe6, 0xe, 0xc1, 0xf8, 0xde,
    0x3d, 0xc6, 0x18, 0xc1, 0x8f, 0xbc, 0xfb, 0x80,

    /* U+0027 "'" */
    0xfe,

    /* U+0028 "(" */
    0x3d, 0xfc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc,
    0x1f, 0x3c,

    /* U+0029 ")" */
    0xf7, 0x86, 0x31, 0x8c, 0x63, 0x18, 0xc7, 0xef,
    0x0,

    /* U+002A "*" */
    0x18, 0x5a, 0x7e, 0xfe, 0x3c, 0x7e, 0x24,

    /* U+002B "+" */
    0xc, 0x6, 0x3, 0x1f, 0xff, 0xf8, 0x60, 0x30,
    0x18, 0xc, 0x0,

    /* U+002C "," */
    0xfe,

    /* U+002D "-" */
    0xff, 0xff, 0xc0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x1, 0xc0, 0x30, 0xe, 0x3, 0x80, 0xe0, 0x18,
    0x7, 0x1, 0xc0, 0x70, 0xc, 0x3, 0x80, 0x0,

    /* U+0030 "0" */
    0x1f, 0x7, 0xf1, 0xc7, 0x70, 0x7c, 0x7, 0x80,
    0xf0, 0x1f, 0x7, 0x71, 0xc7, 0xf0, 0x7c, 0x0,

    /* U+0031 "1" */
    0xff, 0x33, 0x33, 0x33, 0x33, 0x30,

    /* U+0032 "2" */
    0xff, 0xdf, 0xfc, 0x1, 0x80, 0x3f, 0xff, 0xff,
    0x80, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xff, 0x80,

    /* U+0033 "3" */
    0xff, 0xff, 0xf8, 0xe, 0x1, 0x80, 0x70, 0x1d,
    0x87, 0x78, 0x3, 0x0, 0x7f, 0xff, 0xff, 0x0,

    /* U+0034 "4" */
    0xc0, 0x78, 0xf, 0x1, 0xe0, 0x3f, 0xf7, 0xfe,
    0xc0, 0x18, 0x3, 0x0, 0x60, 0xc, 0x1, 0x80,

    /* U+0035 "5" */
    0xff, 0x9f, 0xf0, 0x0, 0x0, 0xf, 0xf9, 0xff,
    0x80, 0x18, 0x3, 0x0, 0x7f, 0xfb, 0xfe, 0x0,

    /* U+0036 "6" */
    0x3f, 0xcf, 0xfb, 0x0, 0x60, 0xd, 0xf9, 0xbf,
    0xb0, 0x1e, 0x3, 0xc0, 0x6f, 0xf8, 0xfe, 0x0,

    /* U+0037 "7" */
    0xff, 0xdf, 0xf0, 0x0, 0x3, 0x80, 0xe0, 0x18,
    0x7, 0x1, 0xc0, 0x70, 0xc, 0x3, 0x80, 0x0,

    /* U+0038 "8" */
    0x3f, 0xef, 0xfb, 0xe, 0x63, 0x8e, 0x70, 0xdd,
    0x87, 0x38, 0xe3, 0x38, 0x6f, 0xfb, 0xfe, 0x0,

    /* U+0039 "9" */
    0x7f, 0x9f, 0xfb, 0x1, 0xe0, 0x3f, 0xf6, 0x7e,
    0xc0, 0x18, 0x3, 0x0, 0x6f, 0xf9, 0xfe, 0x0,

    /* U+003A ":" */
    0xf0, 0x3c,

    /* U+003B ";" */
    0xfc, 0x3d, 0xc0,

    /* U+003C "<" */
    0xe, 0x38, 0xe3, 0x8e, 0xa, 0xe, 0xe, 0xe,

    /* U+003D "=" */
    0xff, 0xff, 0xc0, 0x0, 0xf, 0xff, 0xfc,

    /* U+003E ">" */
    0xe0, 0xe0, 0xe0, 0xa0, 0xe3, 0x8e, 0x38, 0xe0,

    /* U+003F "?" */
    0xff, 0xdf, 0xfc, 0x1, 0x80, 0x31, 0xfe, 0x3f,
    0x0, 0x0, 0x0, 0x0, 0x3, 0x0, 0x60, 0x0,

    /* U+0040 "@" */
    0x3f, 0x9f, 0xfb, 0x1, 0xe0, 0x3c, 0x7, 0x9f,
    0xf3, 0xe6, 0x0, 0xc0, 0x1f, 0xfc, 0xff, 0x80,

    /* U+0041 "A" */
    0x3e, 0x7, 0xe0, 0x7c, 0xf, 0xc1, 0x98, 0x70,
    0xf, 0xf1, 0xfe, 0x70, 0xc, 0x3, 0x80, 0x0,

    /* U+0042 "B" */
    0xff, 0xdf, 0xfc, 0x1, 0x80, 0x37, 0xfe, 0xff,
    0xc0, 0x18, 0x3, 0x0, 0x6f, 0xf9, 0xfe, 0x0,

    /* U+0043 "C" */
    0x1f, 0x1f, 0xdc, 0x5c, 0xc, 0x6, 0x3, 0x1,
    0xc0, 0x71, 0x1f, 0xc7, 0xc0,

    /* U+0044 "D" */
    0xff, 0x8f, 0xfc, 0x0, 0xe0, 0x7, 0x30, 0x33,
    0x3, 0x30, 0x33, 0x7, 0x30, 0xe3, 0xfc, 0x3f,
    0x80,

    /* U+0045 "E" */
    0xff, 0xff, 0xfc, 0x0, 0x0, 0xf, 0xf9, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xf3, 0xfe, 0x0,

    /* U+0046 "F" */
    0xff, 0xff, 0xfc, 0x0, 0x0, 0xf, 0xf9, 0xff,
    0x30, 0x6, 0x0, 0xc0, 0x18, 0x3, 0x0, 0x0,

    /* U+0047 "G" */
    0x1f, 0xf, 0xe7, 0x13, 0x80, 0xcf, 0xf3, 0xfc,
    0xf, 0x83, 0x70, 0xcf, 0xb1, 0xec,

    /* U+0048 "H" */
    0x30, 0x33, 0x3, 0x30, 0x33, 0x3, 0xff, 0xbf,
    0xfb, 0x30, 0x33, 0x3, 0x30, 0x33, 0x3, 0x30,
    0x30,

    /* U+0049 "I" */
    0xff, 0xff, 0xfc,

    /* U+004A "J" */
    0xc, 0x30, 0xc3, 0xc, 0x30, 0xc7, 0x3b, 0xce,
    0x0,

    /* U+004B "K" */
    0xc1, 0xf0, 0xec, 0x33, 0x1c, 0xce, 0x37, 0xd,
    0xa3, 0xec, 0xf3, 0x38, 0xec, 0x1c,

    /* U+004C "L" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc3,
    0xc3, 0xdf, 0xdf,

    /* U+004D "M" */
    0x0, 0x8, 0x1, 0xc0, 0x3e, 0x3, 0xe0, 0x3f,
    0xb, 0xf9, 0xbd, 0xfb, 0xcf, 0x3c, 0x63, 0xc4,
    0x30,

    /* U+004E "N" */
    0x80, 0x78, 0xf, 0x81, 0xfc, 0x3f, 0xc7, 0xbe,
    0xf1, 0xde, 0x1b, 0xc0, 0x78, 0xf, 0x0, 0x80,

    /* U+004F "O" */
    0x1f, 0x7, 0xf1, 0xc7, 0x70, 0x7c, 0x7, 0x80,
    0xf0, 0x1f, 0x7, 0x71, 0xc7, 0xf0, 0x7c, 0x0,

    /* U+0050 "P" */
    0x7f, 0xcf, 0xfc, 0x1, 0x80, 0x3f, 0xff, 0xff,
    0x80, 0x0, 0x0, 0x0, 0xc, 0x1, 0x80, 0x0,

    /* U+0051 "Q" */
    0x1f, 0x7, 0xf1, 0xc7, 0x70, 0x7c, 0x7, 0x9c,
    0xf1, 0xdf, 0x1f, 0x71, 0xc7, 0x98, 0x79, 0x80,

    /* U+0052 "R" */
    0x7f, 0xcf, 0xfc, 0x1, 0x80, 0x3f, 0xff, 0xff,
    0x81, 0xc0, 0x1c, 0x1, 0xcc, 0x19, 0x81, 0x80,

    /* U+0053 "S" */
    0x3f, 0xef, 0xfd, 0x80, 0x30, 0x7, 0xf8, 0x7f,
    0x80, 0x18, 0x3, 0x0, 0x7f, 0xfb, 0xfe, 0x0,

    /* U+0054 "T" */
    0xfd, 0xff, 0x70, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0,

    /* U+0055 "U" */
    0xc0, 0x78, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1f, 0x7, 0x71, 0xc7, 0xf0, 0x7c, 0x0,

    /* U+0056 "V" */
    0xe0, 0xfc, 0x1d, 0x83, 0x38, 0xe3, 0x18, 0x77,
    0xe, 0xe0, 0xd8, 0x1d, 0x1, 0x80, 0x30, 0x0,

    /* U+0057 "W" */
    0xe0, 0xe7, 0xc1, 0xdd, 0x83, 0x33, 0x8e, 0xe3,
    0x19, 0x87, 0x73, 0xe, 0xee, 0xd, 0x98, 0x1d,
    0x70, 0x18, 0xe0, 0x31, 0x80,

    /* U+0058 "X" */
    0xe1, 0xcc, 0x31, 0xce, 0x1d, 0x81, 0xc0, 0x18,
    0x7, 0x81, 0xf8, 0x73, 0x8c, 0x33, 0x87, 0x0,

    /* U+0059 "Y" */
    0xe1, 0xd8, 0xe3, 0x30, 0xec, 0x1c, 0x3, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0,

    /* U+005A "Z" */
    0xff, 0xff, 0xe0, 0x38, 0x1c, 0xe, 0x3, 0x1,
    0xc0, 0xe0, 0x0, 0x1f, 0xff, 0xfc,

    /* U+005B "[" */
    0xff, 0xfc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc,
    0x3f, 0xfc,

    /* U+005C "\\" */
    0xe0, 0xc, 0x1, 0xc0, 0x1c, 0x1, 0xc0, 0x18,
    0x3, 0x80, 0x38, 0x3, 0x80, 0x30, 0x7, 0x0,

    /* U+005D "]" */
    0xff, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc7, 0xff,
    0x80,

    /* U+005E "^" */
    0x18, 0x7e, 0xff, 0xc3,

    /* U+005F "_" */
    0xff, 0xff, 0xfc,

    /* U+0060 "`" */
    0x70, 0xe1, 0xc0,

    /* U+007B "{" */
    0xc, 0x73, 0xc, 0x30, 0xcf, 0x3c, 0x30, 0xc3,
    0x7, 0xc,

    /* U+007C "|" */
    0xff, 0xff, 0xff,

    /* U+007D "}" */
    0xc3, 0x83, 0xc, 0x30, 0xc3, 0xcf, 0x30, 0xc3,
    0x3c, 0xe0,

    /* U+007E "~" */
    0x7b, 0x7f, 0xb3, 0x80
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 63, .box_w = 2, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 113, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 6, .adv_w = 175, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 17, .adv_w = 200, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 34, .adv_w = 188, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 48, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 64, .adv_w = 63, .box_w = 2, .box_h = 4, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 65, .adv_w = 113, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 75, .adv_w = 113, .box_w = 5, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 84, .adv_w = 144, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 91, .adv_w = 175, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 102, .adv_w = 63, .box_w = 2, .box_h = 4, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 103, .adv_w = 175, .box_w = 9, .box_h = 2, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 106, .adv_w = 63, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 107, .adv_w = 188, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 139, .adv_w = 88, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 145, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 161, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 177, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 193, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 209, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 225, .adv_w = 188, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 241, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 257, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 273, .adv_w = 63, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 275, .adv_w = 63, .box_w = 2, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 278, .adv_w = 138, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 286, .adv_w = 175, .box_w = 9, .box_h = 6, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 293, .adv_w = 138, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 301, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 207, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 333, .adv_w = 181, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 349, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 365, .adv_w = 175, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 378, .adv_w = 213, .box_w = 12, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 395, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 411, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 427, .adv_w = 188, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 441, .adv_w = 213, .box_w = 12, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 458, .adv_w = 63, .box_w = 2, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 461, .adv_w = 125, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 470, .adv_w = 188, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 484, .adv_w = 163, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 495, .adv_w = 213, .box_w = 12, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 512, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 528, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 544, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 560, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 576, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 592, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 608, .adv_w = 188, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 622, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 638, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 654, .adv_w = 263, .box_w = 15, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 675, .adv_w = 188, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 691, .adv_w = 188, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 705, .adv_w = 188, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 719, .adv_w = 113, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 729, .adv_w = 188, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 745, .adv_w = 113, .box_w = 5, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 754, .adv_w = 150, .box_w = 8, .box_h = 4, .ofs_x = 0, .ofs_y = 12},
    {.bitmap_index = 758, .adv_w = 200, .box_w = 11, .box_h = 2, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 761, .adv_w = 125, .box_w = 6, .box_h = 3, .ofs_x = 0, .ofs_y = 12},
    {.bitmap_index = 764, .adv_w = 113, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 774, .adv_w = 63, .box_w = 2, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 777, .adv_w = 113, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 787, .adv_w = 156, .box_w = 9, .box_h = 3, .ofs_x = 0, .ofs_y = 12}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 33, .range_length = 64, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 123, .range_length = 4, .glyph_id_start = 65,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    33, 52,
    33, 54,
    33, 55,
    33, 57,
    38, 12,
    38, 14,
    38, 33,
    44, 52,
    44, 54,
    44, 55,
    44, 57,
    48, 12,
    48, 14,
    48, 33,
    50, 52,
    50, 54,
    50, 55,
    50, 57,
    52, 12,
    52, 13,
    52, 14,
    52, 26,
    52, 27,
    52, 33,
    52, 47,
    54, 12,
    54, 13,
    54, 14,
    54, 26,
    54, 27,
    54, 33,
    54, 47,
    55, 12,
    55, 13,
    55, 14,
    55, 26,
    55, 27,
    55, 33,
    57, 12,
    57, 13,
    57, 14,
    57, 26,
    57, 27,
    57, 33,
    57, 47
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -37, -44, -44, -41, -118, -118, -31, -60,
    -39, -39, -61, -109, -109, -31, -11, -18,
    -18, -25, -61, -61, -61, -61, -61, -30,
    -23, -52, -30, -52, -30, -30, -27, -30,
    -48, -26, -48, -26, -26, -24, -60, -44,
    -60, -44, -44, -23, -35
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 45,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 20,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t fontAlternity16 = {
#else
lv_font_t fontAlternity16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 19,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if FONTALTERNITY16*/

