/*******************************************************************************
 * Size: 32 px
 * Bpp: 2
 * Opts: 
 ******************************************************************************/

#include "lvgl.h"
#ifndef NUM_32PX
#define NUM_32PX 1
#endif

#if NUM_32PX

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+002E "." */
    0x7d, 0xbd, 0xbd,

    /* U+002F "/" */
    0x0, 0x0, 0x0, 0x10, 0x0, 0x0, 0x0, 0xf0,
    0x0, 0x0, 0x7, 0x0, 0x0, 0x0, 0x38, 0x0,
    0x0, 0x2, 0xc0, 0x0, 0x0, 0xe, 0x0, 0x0,
    0x0, 0xb0, 0x0, 0x0, 0x7, 0x40, 0x0, 0x0,
    0x3c, 0x0, 0x0, 0x1, 0xd0, 0x0, 0x0, 0xe,
    0x0, 0x0, 0x0, 0x70, 0x0, 0x0, 0x3, 0x80,
    0x0, 0x0, 0x2c, 0x0, 0x0, 0x0, 0xe0, 0x0,
    0x0, 0xb, 0x0, 0x0, 0x0, 0x74, 0x0, 0x0,
    0x3, 0xc0, 0x0, 0x0, 0x1d, 0x0, 0x0, 0x0,
    0xe0, 0x0, 0x0, 0x7, 0x0, 0x0, 0x0, 0x38,
    0x0, 0x0, 0x2, 0xc0, 0x0, 0x0, 0xe, 0x0,
    0x0, 0x0, 0x20, 0x0, 0x0, 0x0,

    /* U+0030 "0" */
    0x0, 0x7f, 0x90, 0x0, 0x3f, 0xff, 0x80, 0xb,
    0xf5, 0xfd, 0x1, 0xf8, 0x3, 0xf0, 0x3f, 0x0,
    0xf, 0x47, 0xe0, 0x0, 0xfc, 0xbc, 0x0, 0xb,
    0xcb, 0xc0, 0x0, 0x7c, 0xfc, 0x0, 0x7, 0xcf,
    0x80, 0x0, 0x3d, 0xf8, 0x0, 0x3, 0xdf, 0x80,
    0x0, 0x3d, 0xf8, 0x0, 0x3, 0xdf, 0xc0, 0x0,
    0x3d, 0xbc, 0x0, 0x7, 0xcb, 0xc0, 0x0, 0xbc,
    0x3d, 0x0, 0xf, 0xc3, 0xf0, 0x0, 0xf8, 0x1f,
    0x80, 0x3f, 0x0, 0xfe, 0x5f, 0xe0, 0x3, 0xff,
    0xf8, 0x0, 0xb, 0xfd, 0x0, 0x0, 0x0, 0x0,
    0x0,

    /* U+0031 "1" */
    0x0, 0x1e, 0x0, 0x3e, 0x0, 0xfe, 0x7, 0xfe,
    0x2f, 0xbe, 0x3d, 0x3e, 0x30, 0x3e, 0x0, 0x3e,
    0x0, 0x3e, 0x0, 0x3e, 0x0, 0x3e, 0x0, 0x3e,
    0x0, 0x3e, 0x0, 0x3e, 0x0, 0x3e, 0x0, 0x3e,
    0x0, 0x3e, 0x0, 0x3e, 0x0, 0x3e, 0x0, 0x3e,
    0x0, 0x3e,

    /* U+0032 "2" */
    0x0, 0x0, 0x0, 0x0, 0x1b, 0xfe, 0x0, 0xb,
    0xff, 0xfd, 0x2, 0xfd, 0x7, 0xf0, 0x3e, 0x0,
    0x1f, 0x8b, 0xc0, 0x0, 0xfc, 0x64, 0x0, 0xf,
    0xc0, 0x0, 0x0, 0xf8, 0x0, 0x0, 0x1f, 0x40,
    0x0, 0x2, 0xf0, 0x0, 0x0, 0x7e, 0x0, 0x0,
    0xf, 0xc0, 0x0, 0x2, 0xf0, 0x0, 0x0, 0xbd,
    0x0, 0x0, 0x1f, 0x80, 0x0, 0x3, 0xf0, 0x0,
    0x0, 0xfc, 0x0, 0x0, 0x3f, 0x0, 0x0, 0xf,
    0xc0, 0x0, 0x3, 0xf9, 0x55, 0x54, 0x7f, 0xff,
    0xff, 0xc7, 0xff, 0xff, 0xfc,

    /* U+0033 "3" */
    0x0, 0x0, 0x0, 0x0, 0xb, 0xfe, 0x0, 0x7,
    0xff, 0xfd, 0x0, 0xfd, 0xb, 0xf0, 0x2f, 0x0,
    0x1f, 0x83, 0xd0, 0x0, 0xfc, 0x28, 0x0, 0xf,
    0xc0, 0x0, 0x0, 0xf8, 0x0, 0x0, 0x1f, 0x40,
    0x0, 0x7, 0xe0, 0x0, 0x1b, 0xf8, 0x0, 0x2,
    0xff, 0x40, 0x0, 0x6, 0xfe, 0x0, 0x0, 0x3,
    0xf4, 0x0, 0x0, 0xf, 0xc0, 0x0, 0x0, 0xbc,
    0x0, 0x0, 0xb, 0xcb, 0xc0, 0x0, 0xbc, 0x7d,
    0x0, 0xf, 0xc3, 0xf0, 0x2, 0xf4, 0x1f, 0xe5,
    0xff, 0x0, 0x7f, 0xff, 0x80, 0x0, 0xbf, 0x90,
    0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0xf, 0x40, 0x0, 0x0, 0x2f, 0x40,
    0x0, 0x0, 0x7f, 0x40, 0x0, 0x0, 0xff, 0x40,
    0x0, 0x2, 0xff, 0x40, 0x0, 0x7, 0xdf, 0x40,
    0x0, 0xf, 0x8f, 0x40, 0x0, 0x3f, 0xf, 0x40,
    0x0, 0xbc, 0xf, 0x40, 0x1, 0xf4, 0xf, 0x40,
    0x3, 0xe0, 0xf, 0x40, 0xf, 0xc0, 0xf, 0x40,
    0x2f, 0x0, 0xf, 0x40, 0x7d, 0x0, 0xf, 0x40,
    0xbf, 0xff, 0xff, 0xfd, 0xbf, 0xff, 0xff, 0xfd,
    0x0, 0x0, 0xf, 0x40, 0x0, 0x0, 0xf, 0x40,
    0x0, 0x0, 0xf, 0x40, 0x0, 0x0, 0xf, 0x40,
    0x0, 0x0, 0xf, 0x40,

    /* U+0035 "5" */
    0x2, 0xff, 0xff, 0xd0, 0xf, 0xff, 0xff, 0x40,
    0x3d, 0x55, 0x54, 0x1, 0xf0, 0x0, 0x0, 0x7,
    0xc0, 0x0, 0x0, 0x2e, 0x0, 0x0, 0x0, 0xf4,
    0x0, 0x0, 0x3, 0xeb, 0xf9, 0x0, 0x1f, 0xff,
    0xff, 0x0, 0xbf, 0x40, 0xbf, 0x2, 0xe0, 0x0,
    0xbd, 0x0, 0x0, 0x0, 0xfc, 0x0, 0x0, 0x2,
    0xf0, 0x0, 0x0, 0x7, 0xc0, 0x0, 0x0, 0x2f,
    0xb, 0x0, 0x0, 0xbc, 0x7d, 0x0, 0x3, 0xe0,
    0xfc, 0x0, 0x3f, 0x41, 0xfd, 0x7, 0xf8, 0x1,
    0xff, 0xff, 0x40, 0x0, 0xbf, 0xe0, 0x0,

    /* U+0036 "6" */
    0x0, 0x2, 0xf4, 0x0, 0x0, 0x1f, 0x80, 0x0,
    0x0, 0xfc, 0x0, 0x0, 0xb, 0xd0, 0x0, 0x0,
    0x7e, 0x0, 0x0, 0x3, 0xf0, 0x0, 0x0, 0x2f,
    0x40, 0x0, 0x1, 0xf9, 0x54, 0x0, 0xf, 0xff,
    0xfd, 0x0, 0x7f, 0x41, 0xbe, 0x3, 0xf0, 0x0,
    0x7d, 0x1f, 0x40, 0x0, 0xfc, 0xbc, 0x0, 0x2,
    0xf2, 0xf0, 0x0, 0xb, 0xcb, 0xc0, 0x0, 0x2f,
    0x2f, 0x0, 0x0, 0xbc, 0x7d, 0x0, 0x3, 0xf0,
    0xfc, 0x0, 0x3f, 0x41, 0xfe, 0x57, 0xfc, 0x1,
    0xff, 0xff, 0xc0, 0x0, 0x7f, 0xf4, 0x0,

    /* U+0037 "7" */
    0xbf, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0x15,
    0x55, 0x57, 0xe0, 0x0, 0x0, 0xbc, 0x0, 0x0,
    0xf, 0x40, 0x0, 0x2, 0xf0, 0x0, 0x0, 0x3d,
    0x0, 0x0, 0xb, 0xc0, 0x0, 0x0, 0xf4, 0x0,
    0x0, 0x2f, 0x0, 0x0, 0x3, 0xd0, 0x0, 0x0,
    0xbc, 0x0, 0x0, 0xf, 0x80, 0x0, 0x1, 0xf0,
    0x0, 0x0, 0x2f, 0x0, 0x0, 0x3, 0xd0, 0x0,
    0x0, 0x7c, 0x0, 0x0, 0xf, 0xc0, 0x0, 0x0,
    0xf8, 0x0, 0x0, 0x1f, 0x40, 0x0, 0x2, 0xf0,
    0x0, 0x0,

    /* U+0038 "8" */
    0x0, 0x7f, 0xf8, 0x0, 0xf, 0xff, 0xfd, 0x0,
    0xbe, 0x56, 0xfc, 0x3, 0xd0, 0x1, 0xf8, 0x1f,
    0x0, 0x3, 0xe0, 0x7c, 0x0, 0xf, 0x80, 0xf4,
    0x0, 0x7d, 0x3, 0xf4, 0x7, 0xf0, 0x2, 0xff,
    0xfe, 0x0, 0x7, 0xff, 0xf4, 0x0, 0xbf, 0xff,
    0xf8, 0x7, 0xfd, 0x5b, 0xf8, 0x3f, 0x80, 0x7,
    0xf0, 0xfc, 0x0, 0xb, 0xd3, 0xe0, 0x0, 0xf,
    0x4f, 0x40, 0x0, 0x3d, 0x3e, 0x0, 0x1, 0xf0,
    0xbc, 0x0, 0xf, 0xc0, 0xf8, 0x0, 0xbc, 0x1,
    0xff, 0xff, 0xd0, 0x0, 0xbf, 0xf8, 0x0,

    /* U+0039 "9" */
    0x0, 0x6f, 0xe4, 0x0, 0xb, 0xff, 0xf8, 0x0,
    0xff, 0xab, 0xfc, 0xb, 0xf0, 0x3, 0xf8, 0x3f,
    0x0, 0x3, 0xf0, 0xf8, 0x0, 0xf, 0xc7, 0xd0,
    0x0, 0x2f, 0x1f, 0x40, 0x0, 0xfc, 0x3d, 0x0,
    0x3, 0xe0, 0xfc, 0x0, 0x1f, 0x42, 0xf4, 0x0,
    0xfc, 0x2, 0xf9, 0x6f, 0xd0, 0x1, 0xff, 0xff,
    0x0, 0x0, 0x3, 0xf4, 0x0, 0x0, 0x1f, 0x80,
    0x0, 0x0, 0xfc, 0x0, 0x0, 0x7, 0xe0, 0x0,
    0x0, 0x3f, 0x0, 0x0, 0x2, 0xf4, 0x0, 0x0,
    0xf, 0x80, 0x0, 0x0, 0xbc, 0x0, 0x0,

    /* U+003A ":" */
    0xfc, 0xfc, 0xbc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xbc, 0xfc, 0xfc
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 256, .box_w = 4, .box_h = 3, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 3, .adv_w = 256, .box_w = 15, .box_h = 25, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 97, .adv_w = 256, .box_w = 14, .box_h = 23, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 178, .adv_w = 256, .box_w = 8, .box_h = 21, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 220, .adv_w = 256, .box_w = 14, .box_h = 22, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 297, .adv_w = 256, .box_w = 14, .box_h = 23, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 378, .adv_w = 256, .box_w = 16, .box_h = 21, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 462, .adv_w = 256, .box_w = 15, .box_h = 21, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 541, .adv_w = 256, .box_w = 15, .box_h = 21, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 620, .adv_w = 256, .box_w = 14, .box_h = 21, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 694, .adv_w = 256, .box_w = 15, .box_h = 21, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 773, .adv_w = 256, .box_w = 15, .box_h = 21, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 852, .adv_w = 256, .box_w = 4, .box_h = 14, .ofs_x = 6, .ofs_y = 1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 46, .range_length = 13, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
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
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 2,
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
const lv_font_t num_32px = {
#else
lv_font_t num_32px = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 25,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0)
    .underline_position = -3,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if NUM_32PX*/

