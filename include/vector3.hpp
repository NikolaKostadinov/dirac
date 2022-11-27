#pragma once

#include "engine_params.h"

#include <cmath>
#include <string>
#include <sstream>

class Vector3
{
    public:

        Vector3();
        virtual ~Vector3();

        Vector3(float _x_, float _y_, float _z_);

        void     scale     (float _factor_                    );
        void     shrink    (float _factor_                    );
        void     normalize (float _norm_ = DEFAULT_VECTOR_NORM);

        Vector3  operator+ (                     ) const;
        Vector3  operator- (                     ) const;
        Vector3  operator+ (const Vector3 _other_) const;
        Vector3  operator- (const Vector3 _other_) const;
        Vector3  operator* (const Vector3 _other_) const;
        Vector3  operator/ (const Vector3 _other_) const;
        Vector3& operator+=(const Vector3 _other_)      ;
        Vector3& operator-=(const Vector3 _other_)      ;
        Vector3& operator*=(const Vector3 _other_)      ;
        Vector3& operator/=(const Vector3 _other_)      ;
        bool     operator==(const Vector3 _other_) const;
        bool     operator> (const Vector3 _other_) const;
        bool     operator< (const Vector3 _other_) const;
        bool     operator>=(const Vector3 _other_) const;
        bool     operator<=(const Vector3 _other_) const;

        float    x         (                     ) const;
        float    y         (                     ) const;
        float    z         (                     ) const;
        float    length    (                     ) const;
        float    sq        (                     ) const;

        float    dot       (const Vector3 _other_) const;
        Vector3  cross     (const Vector3 _other_) const;
        void     crossWith (const Vector3 _other_)      ;

        std::string string();

    protected:

        float _x;
        float _y;
        float _z;
};

float   dot  (const Vector3 _left_, const Vector3 _right_);
Vector3 cross(const Vector3 _left_, const Vector3 _right_);