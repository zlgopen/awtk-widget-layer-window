/**
 * File:   demo1_app.c
 * Author: AWTK Develop Team
 * Brief:  basic demo
 *
 * Copyright (c) 2018 - 2020  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2018-02-16 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "awtk.h"
#include "../res/assets.inc"
#include "lcd/lcd_mem_rgba8888.h"
#include "layer_window_register.h"
#include "layer_window/layer_manager.h"

static canvas_t* s_canvas_fast = NULL;

#ifdef STM32H743xx
#define LAYER1_LCD_X 0
#define LAYER1_LCD_Y 0
#define LAYER1_LCD_W lcdltdc.pwidth
#define LAYER1_LCD_H lcdltdc.pheight

#include "ltdc.h"
#include "base/canvas.h"
#include "base/font_manager.h"
#include "lcd/lcd_mem_bgr565.h"
extern uint8_t* s_framebuffers[2];
canvas_t* canvas_create_for_layer1(xy_t x, xy_t y, wh_t w, wh_t h) {
  canvas_t* canvas = NULL;
  lcd_t* lcd = lcd_mem_bgr565_create_double_fb(w, h, s_framebuffers[0], s_framebuffers[1]);
  return_value_if_fail(lcd != NULL, NULL);

  canvas = TKMEM_ZALLOC(canvas_t);
  assert(canvas != NULL);

  return canvas_init(canvas, lcd, font_manager());
}
#define create_fast_canvas(w, h) canvas_create_for_layer1(0, 0, 1024, 600)
#else
#define LAYER1_LCD_X 10
#define LAYER1_LCD_Y 10
#define LAYER1_LCD_W 300
#define LAYER1_LCD_H 600
#define create_fast_canvas(w, h) canvas_offline_create(w, h, BITMAP_FMT_RGBA8888)
#endif

static ret_t layers_init(void) {
  layer_t* layer = NULL;
  layer_manager_t* layer_manager = layer_manager_create();
  return_value_if_fail(layer_manager != NULL, RET_BAD_PARAMS);
  layer_manager_set(layer_manager);

  s_canvas_fast = create_fast_canvas(LAYER1_LCD_W, LAYER1_LCD_H);
  layer = layer_create("fast", s_canvas_fast, LAYER1_LCD_X, LAYER1_LCD_Y, 60);
  assert(layer != NULL);
  layer_manager_add(layer_manager, layer);
  layer_start(layer);
  layer_set_show_fps(layer, TRUE);

  return RET_OK;
}

static ret_t layers_deinit(void) {
  if (s_canvas_fast != NULL) {
    canvas_reset(s_canvas_fast);
  }
  layer_manager_destroy(layer_manager());
  layer_manager_set(NULL);

  return RET_OK;
}

ret_t application_init() {
  layer_window_register();
  layers_init();
  
	window_open("main");
  window_open("layer_window");

  return RET_OK;
}

ret_t application_exit() {
  log_debug("application_exit\n");
  layers_deinit();
  return RET_OK;
}

#include "awtk_main.inc"
