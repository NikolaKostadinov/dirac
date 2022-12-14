#include "../include/vector2.hpp"

Vector2::Vector2() : Vector2(0.0f, 0.0f)
{

}

Vector2::~Vector2()
{

}

Vector2::Vector2(float _x_, float _y_)
{
    _x = _x_;
    _y = _y_;
}

void Vector2::scale(float _factor_)
{
    _x *= _factor_;
    _y *= _factor_;
}

void Vector2::shrink(float _factor_)
{
    _x /= _factor_;
    _y /= _factor_;
}

void Vector2::normalize(float _norm_)
{
    scale(_norm_ / length() );
}

Vector2 Vector2::operator+() const
{
    return *this;
}

Vector2 Vector2::operator-() const
{
    return Vector2(-_x, -_y);
}

Vector2 Vector2::operator+(const Vector2 _other_) const
{
    float x = _x + _other_._x;
    float y = _y + _other_._y;

    return Vector2(x, y);
}

Vector2 Vector2::operator-(const Vector2 _other_) const
{
    float x = _x - _other_._x;
    float y = _y - _other_._y;

    return Vector2(x, y);
}

Vector2 Vector2::operator*(const Vector2 _other_) const
{
    float x = _x * _other_._x;
    float y = _y * _other_._y;

    return Vector2(x, y);
}

Vector2 Vector2::operator/(const Vector2 _other_) const
{
    float x = _x / _other_._x;
    float y = _y / _other_._y;

    return Vector2(x, y);
}

Vector2& Vector2::operator+=(const Vector2 _other_)
{
    _x += _other_._x;
    _y += _other_._y;

    return *this;
}

Vector2& Vector2::operator-=(const Vector2 _other_)
{
    _x -= _other_._x;
    _y -= _other_._y;

    return *this;
}

Vector2& Vector2::operator*=(const Vector2 _other_)
{
    _x *= _other_._x;
    _y *= _other_._y;

    return *this;
}

Vector2& Vector2::operator/=(const Vector2 _other_)
{
    _x /= _other_._x;
    _y /= _other_._y;

    return *this;
}

bool Vector2::operator==(const Vector2 _other_) const
{
    return (_x == _other_._x) && (_y == _other_._y);
}

float Vector2::x() const
{
    return _x;
}

float Vector2::y() const
{
    return _y;
}

float Vector2::length() const
{
    return sqrt( sq() );
}

float Vector2::dir() const
{
    return atan2(_y, _x);
}

float Vector2::sq() const
{
    return _x * _x + _y * _y;
}

float Vector2::dot(const Vector2 _other_) const
{
    return _x * _other_._x + _y * _other_._y;
}

float Vector2::cross(const Vector2 _other_) const
{
    return _x * _other_._y - _y * _other_._x;
}

std::string Vector2::string()
{
    std::ostringstream stream;
    stream << "[ ";
    stream << _x  ;
    stream << ", ";
    stream << _y  ;
    stream << " ]";

    return stream.str();
}

float dot(const Vector2 _left_, const Vector2 _right_)
{
    return _left_.dot(_right_);
}

float cross(const Vector2 _left_, const Vector2 _right_)
{
    return _left_.cross(_right_);
}