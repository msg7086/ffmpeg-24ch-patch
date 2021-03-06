/*
 * AAC decoder data
 * Copyright (c) 2005-2006 Oded Shimon ( ods15 ods15 dyndns org )
 * Copyright (c) 2006-2007 Maxim Gavrilov ( maxim.gavrilov gmail com )
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * AAC decoder data
 * @author Oded Shimon  ( ods15 ods15 dyndns org )
 * @author Maxim Gavrilov ( maxim.gavrilov gmail com )
 */

#ifndef AVCODEC_AACDECTAB_H
#define AVCODEC_AACDECTAB_H

#include "libavutil/channel_layout.h"
#include "aac.h"

#include <stdint.h>

#define AAC_MAX_CHANNELS 24
#define AAC_MAX_DEFAULT_LAYOUTS 16
#define PCE_HEIGHT_EXTENSION_SYNC 0xac
#define PCE_LAYOUT_NBR 36
#define MAX_TAG 16
#define PCE_MAX_TAG 10

static const int8_t tags_per_config[AAC_MAX_DEFAULT_LAYOUTS] = { 0, 1, 1, 2, 3, 3, 4, 5, 0, 0, 0, 5, 5, 16, 5, 0 };

/* 7.1(top) elements ordering is odd in spec: LFE is not last, there is a TOP Front element after ; in regular PCE this would not be allowed */
static const uint8_t aac_channel_layout_map[AAC_MAX_DEFAULT_LAYOUTS][MAX_TAG][4] = {
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, },
    { { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, },
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, },
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, },
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, },
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT  }, },
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT  }, },
    { { 0, } },
    { { 0, } },
    { { 0, } },
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT  }, },
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT  }, },
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_CPE, 3, AAC_CHANNEL_BACK, NORMAL_HEIGHT },
      { TYPE_SCE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, { TYPE_LFE, 1, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, { TYPE_SCE, 2, AAC_CHANNEL_FRONT, TOP_HEIGHT }, { TYPE_CPE, 4, AAC_CHANNEL_FRONT, TOP_HEIGHT },
      { TYPE_CPE, 5, AAC_CHANNEL_SIDE, TOP_HEIGHT }, { TYPE_SCE, 3, AAC_CHANNEL_SIDE, TOP_HEIGHT }, { TYPE_CPE, 6, AAC_CHANNEL_BACK, TOP_HEIGHT }, { TYPE_SCE, 4, AAC_CHANNEL_BACK, TOP_HEIGHT }, { TYPE_SCE, 5, AAC_CHANNEL_FRONT, BOTTOM_HEIGHT },
      { TYPE_CPE, 7, AAC_CHANNEL_FRONT, BOTTOM_HEIGHT },},//AV_CH_LAYOUT_22POINT2
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_FRONT, TOP_HEIGHT }, },// follow spec event though it's odd
    { { 0, } },
};

static const uint8_t aac_channel_layout_map_reordered[AAC_MAX_DEFAULT_LAYOUTS][MAX_TAG][4] = {
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, },
    { { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, },
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, },
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, },
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, },
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT  }, },
    { { TYPE_CPE, 1, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_LFE, 1, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT  }, },
    { { 0, } },
    { { 0, } },
    { { 0, } },
    { { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT  }, { TYPE_CPE, 1, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, },
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT  }, },
    { { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, { TYPE_CPE, 3, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_FRONT, NORMAL_HEIGHT },
      { TYPE_SCE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_LFE, 1, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_SIDE, NORMAL_HEIGHT },
      { TYPE_CPE, 4, AAC_CHANNEL_FRONT, TOP_HEIGHT }, { TYPE_SCE, 2, AAC_CHANNEL_FRONT, TOP_HEIGHT }, { TYPE_SCE, 3, AAC_CHANNEL_SIDE, TOP_HEIGHT }, { TYPE_CPE, 6, AAC_CHANNEL_BACK, TOP_HEIGHT }, { TYPE_CPE, 5, AAC_CHANNEL_SIDE, TOP_HEIGHT }, { TYPE_SCE, 4, AAC_CHANNEL_BACK, TOP_HEIGHT },
      { TYPE_SCE, 5, AAC_CHANNEL_FRONT, BOTTOM_HEIGHT },  { TYPE_CPE, 7, AAC_CHANNEL_FRONT, BOTTOM_HEIGHT },},//AV_CH_LAYOUT_22POINT2
    { { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_FRONT, TOP_HEIGHT }, },
    { { 0, } },
};

static const uint64_t aac_channel_layout[AAC_MAX_DEFAULT_LAYOUTS] = {
    AV_CH_LAYOUT_MONO,
    AV_CH_LAYOUT_STEREO,
    AV_CH_LAYOUT_SURROUND,
    AV_CH_LAYOUT_4POINT0,
    AV_CH_LAYOUT_5POINT0,//ISO/IEC 14496-3:2009/Amd.4:2013 , change from AV_CH_LAYOUT_5POINT0_BACK
    AV_CH_LAYOUT_5POINT1,//ISO/IEC 14496-3:2009/Amd.4:2013
    AV_CH_LAYOUT_7POINT1_WIDE,//ISO/IEC 14496-3:2009/Amd.4:2013, change from AV_CH_LAYOUT_7POINT1
    0,
    0,
    0,
    AV_CH_LAYOUT_6POINT1,//ISO/IEC 14496-3:2009/Amd.4:2013
    AV_CH_LAYOUT_7POINT1,//ISO/IEC 14496-3:2009/Amd.4:2013
    AV_CH_LAYOUT_22POINT2,//ISO/IEC 14496-3:2009/Amd.4:2013
    AV_CH_LAYOUT_7POINT1_TOP,//ISO/IEC 14496-3:2009/Amd.4:2013
    0,
};

/* number of tags for the pce_channel_layout_map table */
static const int8_t tags_pce_config[PCE_LAYOUT_NBR] = {0, 10, 9, 8, 7, 8, 7, 6, 6, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2,  1, 1};

static const uint8_t pce_channel_layout_map[PCE_LAYOUT_NBR][PCE_MAX_TAG][4] = {
    { { 0, } },
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_FRONT, TOP_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_FRONT, TOP_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_CPE, 3, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_CPE, 4, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_CPE, 5, AAC_CHANNEL_BACK, TOP_HEIGHT }, { TYPE_SCE, 2, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_SCE, 3, AAC_CHANNEL_BACK, TOP_HEIGHT }, },//AV_CH_LAYOUT_HEXADECAGONAL
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_FRONT, TOP_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_FRONT, TOP_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_SCE, 2, AAC_CHANNEL_SIDE, TOP_HEIGHT }, { TYPE_CPE, 3, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_SCE, 3, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_CPE, 4, AAC_CHANNEL_BACK, TOP_HEIGHT }, { TYPE_SCE, 4, AAC_CHANNEL_BACK, TOP_HEIGHT }, },// 0x3FF37, 15ch
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_FRONT, TOP_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_FRONT, TOP_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_SCE, 2, AAC_CHANNEL_SIDE, TOP_HEIGHT }, { TYPE_CPE, 3, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_SCE, 3, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_CPE, 4, AAC_CHANNEL_BACK, TOP_HEIGHT }, },// 0x2FF37, 14ch
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_FRONT, TOP_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_FRONT, TOP_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_SCE, 2, AAC_CHANNEL_SIDE, TOP_HEIGHT }, { TYPE_CPE, 3, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_SCE, 3, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_SCE, 4, AAC_CHANNEL_BACK, TOP_HEIGHT }, },// 0x17F37, 13ch
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_FRONT, TOP_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_FRONT, TOP_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_SCE, 2, AAC_CHANNEL_SIDE, TOP_HEIGHT }, { TYPE_CPE, 3, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_SCE, 3, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, },// 0x7F37, 12ch
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_FRONT, TOP_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_SIDE, TOP_HEIGHT }, { TYPE_CPE, 3, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_SCE, 2, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, },// 0x5F37, 11ch
    { { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_SCE, 0, AAC_CHANNEL_SIDE, TOP_HEIGHT }, { TYPE_CPE, 3, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, },//0xFF3, 10ch
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_SIDE, TOP_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_SCE, 2, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_OCTAGONAL | AV_CH_TOP_CENTER , 9 ch
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_OCTAGONAL
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_7POINT1
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_7POINT1_WIDE
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_7POINT1_WIDE_BACK
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_FRONT, TOP_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_7POINT1_TOP with LFE last in PCE
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_6POINT1
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_6POINT1_BACK
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_7POINT0
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_7POINT0_FRONT
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_HEXAGONAL
    { { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_6POINT1_FRONT
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_6POINT0
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_5POINT1
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT },  { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_5POINT1_BACK
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_4POINT1
    { { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 2, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_6POINT0_FRONT
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_5POINT0
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_5POINT0_BACK
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_SCE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_4POINT0
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_3POINT1
    { { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_QUAD
    { { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_CPE, 1, AAC_CHANNEL_SIDE, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_2_2
    { { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_LFE, 0, AAC_CHANNEL_LFE, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_2POINT1
    { { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_SCE, 0, AAC_CHANNEL_BACK, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_2_1
    { { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, },//AV_CH_LAYOUT_SURROUND
    { { TYPE_CPE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, }, //AV_CH_LAYOUT_STEREO
    { { TYPE_SCE, 0, AAC_CHANNEL_FRONT, NORMAL_HEIGHT }, }, //AV_CH_LAYOUT_MONO
};

/* list of channel layouts supported by the pce encoder /decoder table */
static const uint64_t pce_channel_layout_list[PCE_LAYOUT_NBR] = {
    0,
    AV_CH_LAYOUT_HEXADECAGONAL,
    AV_CH_LAYOUT_OCTAGONAL | AV_CH_TOP_CENTER | AV_CH_TOP_FRONT_LEFT |
    AV_CH_TOP_FRONT_RIGHT | AV_CH_TOP_FRONT_CENTER | AV_CH_TOP_BACK_CENTER |
    AV_CH_TOP_BACK_LEFT | AV_CH_TOP_BACK_RIGHT,
    AV_CH_LAYOUT_OCTAGONAL | AV_CH_TOP_CENTER | AV_CH_TOP_FRONT_LEFT |
    AV_CH_TOP_FRONT_RIGHT | AV_CH_TOP_FRONT_CENTER | AV_CH_TOP_BACK_LEFT |
    AV_CH_TOP_BACK_RIGHT,
    AV_CH_LAYOUT_OCTAGONAL | AV_CH_TOP_CENTER | AV_CH_TOP_FRONT_LEFT |
    AV_CH_TOP_FRONT_RIGHT | AV_CH_TOP_FRONT_CENTER | AV_CH_TOP_BACK_CENTER,
    AV_CH_LAYOUT_OCTAGONAL | AV_CH_TOP_CENTER | AV_CH_TOP_FRONT_LEFT |
    AV_CH_TOP_FRONT_RIGHT | AV_CH_TOP_FRONT_CENTER,
    AV_CH_LAYOUT_OCTAGONAL | AV_CH_TOP_CENTER | AV_CH_TOP_FRONT_LEFT | AV_CH_TOP_FRONT_RIGHT,
    AV_CH_LAYOUT_6POINT0_FRONT | AV_CH_BACK_CENTER | AV_CH_BACK_LEFT |
    AV_CH_BACK_RIGHT | AV_CH_TOP_CENTER,
    AV_CH_LAYOUT_OCTAGONAL | AV_CH_TOP_CENTER,
    AV_CH_LAYOUT_OCTAGONAL,
    AV_CH_LAYOUT_7POINT1,
    AV_CH_LAYOUT_7POINT1_WIDE,
    AV_CH_LAYOUT_7POINT1_WIDE_BACK,
    AV_CH_LAYOUT_7POINT1_TOP,
    AV_CH_LAYOUT_6POINT1,
    AV_CH_LAYOUT_6POINT1_BACK,
    AV_CH_LAYOUT_7POINT0,
    AV_CH_LAYOUT_7POINT0_FRONT,
    AV_CH_LAYOUT_HEXAGONAL,
    AV_CH_LAYOUT_6POINT1_FRONT,
    AV_CH_LAYOUT_6POINT0,
    AV_CH_LAYOUT_5POINT1,
    AV_CH_LAYOUT_5POINT1_BACK,
    AV_CH_LAYOUT_4POINT1,
    AV_CH_LAYOUT_6POINT0_FRONT,
    AV_CH_LAYOUT_5POINT0,
    AV_CH_LAYOUT_5POINT0_BACK,
    AV_CH_LAYOUT_4POINT0,
    AV_CH_LAYOUT_3POINT1,
    AV_CH_LAYOUT_QUAD,
    AV_CH_LAYOUT_2_2,
    AV_CH_LAYOUT_2POINT1,
    AV_CH_LAYOUT_2_1,
    AV_CH_LAYOUT_SURROUND,
    AV_CH_LAYOUT_STEREO,
    AV_CH_LAYOUT_MONO,
};
/* Table  used for PCE to remap channels for layouts with LFE (mostly), fixing ordering issues with LFE.
 */
static const uint8_t aac_chan_maps[PCE_LAYOUT_NBR][AAC_MAX_CHANNELS] = {
    {0},
    {0, 1},
    {0, 1, 2},
    {0, 1, 2, 3},
    {2, 0, 1, 4, 3},//AV_CH_LAYOUT_4POINT1
    {2, 0, 1, 3, 4},//AV_CH_LAYOUT_5POINT0, AV_CH_LAYOUT_5POINT0_BACK
    {2, 0, 1, 4, 5, 3},//AV_CH_LAYOUT_5POINT1, AV_CH_LAYOUT_5POINT1_BACK
    {2, 0, 1, 4, 5, 6, 3},//AV_CH_LAYOUT_6POINT1, AV_CH_LAYOUT_6POINT1_BACK, AV_CH_LAYOUT_6POINT1_FRONT
    {2, 0, 1, 6, 7, 4, 5, 3},//AV_CH_LAYOUT_7POINT1
    {2, 6, 7, 0, 1, 4, 5, 3},//AV_CH_LAYOUT_7POINT1_WIDE, AV_CH_LAYOUT_7POINT1_WIDE_BACK
    {2, 0, 1, 4, 5, 6, 7, 3},//AV_CH_LAYOUT_7POINT1_TOP, when decoded from PCE
};

static const uint8_t normal_chan_maps[AAC_MAX_DEFAULT_LAYOUTS][AAC_MAX_CHANNELS] = {
    {0,},
    {0, 1,},
    {0, 1, 2,},
    {0, 1, 2, 3,},
    {0, 1, 2, 3, 4,},
    {0, 1, 2, 3, 4, 5,},
    {0, 1, 2, 3, 4, 5, 6,},
    {0, 1, 2, 3, 4, 5, 6, 7,},
};

#endif /* AVCODEC_AACDECTAB_H */
