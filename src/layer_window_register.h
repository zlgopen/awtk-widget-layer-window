/**
 * File:   layer_window_register.h
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


#ifndef TK_LAYER_WINDOW_REGISTER_H
#define TK_LAYER_WINDOW_REGISTER_H

#include "base/widget.h"

BEGIN_C_DECLS

/**
 * @method  layer_window_register
 * 注册控件。
 *
 * @annotation ["global"]
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t layer_window_register(void);

/**
 * @method  layer_window_supported_render_mode
 * 获取支持的渲染模式。
 *
 * @annotation ["global"]
 *
 * @return {const char*} 返回渲染模式。
 */
const char* layer_window_supported_render_mode(void);

END_C_DECLS

#endif /*TK_LAYER_WINDOW_REGISTER_H*/
