#pragma once

class Vector3
{
    public:

        Vector3();
        virtual ~Vector3();

        Vector3(float _x_, float _y_, float _z_);

        void     scale (float _factor_);
        void     shrink(float _factor_);

        Vector3  operator+ (const Vector3 _other_);
        Vector3  operator- (const Vector3 _other_);
        Vector3  operator* (const Vector3 _other_);
        Vector3  operator/ (const Vector3 _other_);
        Vector3& operator+=(const Vector3 _other_);
        Vector3& operator-=(const Vector3 _other_);
        Vector3& operator*=(const Vector3 _other_);
        Vector3& operator/=(const Vector3 _other_);
        bool     operator==(const Vector3 _other_);

        float    x         (                     ) const;
        float    y         (                     ) const;
        float    z         (                     ) const;
        float    length    (                     ) const;
        float    sq        (                     ) const;

        float    inner     (const Vector3 _other_) const;
        Vector3  outer     (const Vector3 _other_) const;

    protected:

        float _x;
        float _y;
        float _z;
};

float inner(const Vector3 _left_, const Vector3 _right_);
float outer(const Vector3 _left_, const Vector3 _right_);