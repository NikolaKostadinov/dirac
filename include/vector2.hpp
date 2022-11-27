#pragma once

#include "engine_params.h"

#include <cmath>
#include <string>
#include <sstream>

class Vector2
{
    public:

        Vector2();
        virtual ~Vector2();

        Vector2(float _x_, float _y_);

        void     scale     (float _factor_                    );
        void     shrink    (float _factor_                    );
        void     normalize (float _norm_ = DEFAULT_VECTOR_NORM);

        Vector2  operator+ (                     ) const;
        Vector2  operator- (                     ) const;
        Vector2  operator+ (const Vector2 _other_) const;
        Vector2  operator- (const Vector2 _other_) const;
        Vector2  operator* (const Vector2 _other_) const;
        Vector2  operator/ (const Vector2 _other_) const;
        Vector2& operator+=(const Vector2 _other_)      ;
        Vector2& operator-=(const Vector2 _other_)      ;
        Vector2& operator*=(const Vector2 _other_)      ;
        Vector2& operator/=(const Vector2 _other_)      ;
        bool     operator==(const Vector2 _other_) const;
        bool     operator> (const Vector2 _other_) const;
        bool     operator< (const Vector2 _other_) const;
        bool     operator>=(const Vector2 _other_) const;
        bool     operator<=(const Vector2 _other_) const;

        float    x         (                     ) const;
        float    y         (                     ) const;
        float    length    (                     ) const;
        float    dir       (                     ) const;
        float    sq        (                     ) const;

        float    dot       (const Vector2 _other_) const;
        float    cross     (const Vector2 _other_) const;

        std::string string();

    protected:

        float _x;
        float _y;
};

float dot  (const Vector2 _left_, const Vector2 _right_);
float cross(const Vector2 _left_, const Vector2 _right_);