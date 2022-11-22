#pragma once

class Vector2
{
    public:

        Vector2();
        virtual ~Vector2();

        Vector2(float _x_, float _y_);

        void     scale (float _factor_);
        void     shrink(float _factor_);

        Vector2  operator+ (const Vector2 _other_);
        Vector2  operator- (const Vector2 _other_);
        Vector2  operator* (const Vector2 _other_);
        Vector2  operator/ (const Vector2 _other_);
        Vector2& operator+=(const Vector2 _other_);
        Vector2& operator-=(const Vector2 _other_);
        Vector2& operator*=(const Vector2 _other_);
        Vector2& operator/=(const Vector2 _other_);
        bool     operator==(const Vector2 _other_);

        float    x         (                     ) const;
        float    y         (                     ) const;
        float    length    (                     ) const;
        float    dir       (                     ) const;
        float    sq        (                     ) const;

        float    inner     (const Vector2 _other_) const;
        float    outer     (const Vector2 _other_) const;

    protected:

        float _x;
        float _y;
};

float inner(const Vector2 _left_, const Vector2 _right_);
float outer(const Vector2 _left_, const Vector2 _right_);