#pragma once

#include "engine_params.h"

float expn(float _x_)
{
    float x;
    long  i;
    long  e;
    long  m;
    float y;

    x = _x_;

    x   = 1.44269504089f * x + 126.9569643f;
    i   = * (long  *) &x;
    e   = i & 0x7f800000;
    m   = i & 0x807fffff;
    e >>= 23;
    e  += 23;
    e <<= 23;
    i   = e + m;
    y   = * (float *) &i;

    return y;
}

float normDist(float _x_, float _ex_, float _dev_)
{
    float p;
    float y;

    p  = _x_ - _ex_;
    p /= _dev_     ;
    p *= 0.5f * p  ;
    y  = expn(p)    ;

    return y;
}

float invSqrt(float _x_)
{
    float x2;
    long   i;
    float  y;

    x2 = 0.5f * _x_;
    y  =        _x_;

    i = * ( long  * ) &y;               // evil floating point bit level hacking
    i = MAGIC - (i >> 1);               // what the fuck ?
    y = * ( float * ) &i;
    y = y * (1.5f - (x2 * y * y));      // newton iterations
    y = y * (1.5f - (x2 * y * y));
    y = y * (1.5f - (x2 * y * y));

    return y;
}