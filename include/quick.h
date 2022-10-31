#pragma once

#include "engine_params.h"

float invSqrt(float _x_)
{
    float x2;
    float  y;
    long   i;

    x2 = 0.5f * _x_;
    y  =        _x_;

    i = * ( long  * ) &y;           // evil floating point bit level hacking
    i = MAGIC - (i >> 1);           // what the fuck ?
    y = * ( float * ) &i;
    y = y * (1.5f - (x2 * y * y));  // newton iterations
    y = y * (1.5f - (x2 * y * y));
    y = y * (1.5f - (x2 * y * y));

    return y;
}