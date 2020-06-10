#ifndef sga_rect_h_
#define sga_rect_h_

#include "sga_point.h"


typedef struct sga_rect
{
    sga_point start;
    int w;
    int h;
} sga_rect;

typedef struct sga_frect
{
    sga_point_f start;
    float w;
    float h;
} sga_rect_f;

#endif