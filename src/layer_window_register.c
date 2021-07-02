/**
 * File:   layer_window.c
 * Author: AWTK Develop Team
 * Brief:  将窗口显示到不同的层上。
 *
 * Copyright (c) 2021 - 2021 Guangzhou ZHIYUAN Electronics Co.,Ltd.
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
 * 2021-06-30 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "tkc/mem.h"
#include "tkc/utils.h"
#include "layer_window_register.h"
#include "base/widget_factory.h"
#include "layer_window/layer_window.h"

ret_t layer_window_register(void) {
  return widget_factory_register(widget_factory(), WIDGET_TYPE_LAYER_WINDOW, layer_window_create);
}

const char* layer_window_supported_render_mode(void) {
  return "OpenGL|AGGE-BGR565|AGGE-BGRA8888|AGGE-MONO";
}
