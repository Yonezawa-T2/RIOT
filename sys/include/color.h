/*
 * Copyright (C) 2014 - 2016 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @defgroup    sys_color Color
 * @ingroup     sys
 * @brief       The color sys module supports handling RGB and HSV color
 * @{
 *
 * @file
 * @brief       Headers for the color handling module
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 * @author      Cenk Gündoğan <mail@cgundogan.de>
 */

#ifndef __COLOR_H
#define __COLOR_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Data-structure describing a RGB color
 */
typedef struct {
    uint8_t r;          /**< red value      [0 - 255] */
    uint8_t g;          /**< green value    [0 - 255] */
    uint8_t b;          /**< blue value     [0 - 255] */
} color_rgb_t;

/**
 * @brief Data-structure for holding HSV colors
 */
typedef struct {
    float h;            /**< hue value        [0.0 - 360.0] */
    float s;            /**< saturation value [0.0 - 1.0] */
    float v;            /**< value            [0.0 - 1.0] */
} color_hsv_t;


/**
 * @brief Convert RGB color to HSV color
 *
 * @param[in] rgb       Input color encoded in RGB space
 * @param[out] hsv      Output color encoded in HSV space
 */
void color_rgb2hsv(color_rgb_t *rgb, color_hsv_t *hsv);

/**
 * @brief Convert HSV color to RGB color
 *
 * @param[in] hsv       Input color encoded in HSV space
 * @param[out] rgb      Output color encoded in RGB space
 */
void color_hsv2rgb(color_hsv_t *hsv, color_rgb_t *rgb);

/**
 * @brief Convert a @p hex value of the form 0x00RRGGBB to an RGB color struct
 *
 * @note                the two most significant bytes of @p hex will be ignored
 *
 * @param[in] hex       Input color encoded in hex
 * @param[out] rgb      Output color encoded in RGB space
 */
void color_hex2rgb(const uint32_t hex, color_rgb_t *rgb);

/**
 * @brief Convert a @p rgb struct to a @p hex value of the form 0x00RRGGBB
 *
 * @note                the two most significant bytes of @p hex will be 0
 *
 * @param[in] rgb       Input color encoded in RGB space
 * @param[out] hex      Output color encoded in hex
 */
void color_rgb2hex(const color_rgb_t *rgb, uint32_t *hex);

/**
 * @brief Convert a hex color string of the form 'RRGGBB' to a color_rgb_t struct
 *
 * @note                @p str MUST contain only hexadecimal digits.
 *                      Expect unexpected behaviour, otherwise.
 *
 * @param[in] str       Input color encoded as string of the form 'RRGGBB'
 * @param[out] rgb      Output color encoded in RGB space
 */
void color_str2rgb(const char *str, color_rgb_t *color);

/**
 * @brief Convert a color_rgb_t struct to a hex color string of the form 'RRGGBB'
 *
 * @note                @p str MUST be big enough to hold 6 characters
 *
 * @param[in] rgb       Input color encoded in RGB space
 * @param[out] str      Output color encoded as string of the form 'RRGGBB'
 */
void color_rgb2str(const color_rgb_t *rgb, char *str);

#ifdef __cplusplus
}
#endif

#endif /* __COLOR_H */
/** @} */
