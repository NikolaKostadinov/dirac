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
    // need length
}

Vector2 Vector2::operator+()
{
    return *this;
}

Vector2 Vector2::operator-()
{
    return Vector2(-_x, -_y);
}

Vector2 Vector2::operator+(const Vector2 _other_)
{
    float x = _x + _other_._x;
    float y = _y + _other_._y;

    return Vector2(x, y);
}

Vector2 Vector2::operator-(const Vector2 _other_)
{
    float x = _x - _other_._x;
    float y = _y - _other_._y;

    return Vector2(x, y);
}

Vector2 Vector2::operator*(const Vector2 _other_)
{
    float x = _x * _other_._x;
    float y = _y * _other_._y;

    return Vector2(x, y);
}

Vector2 Vector2::operator/(const Vector2 _other_)
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

bool Vector2::operator==(const Vector2 _other_)
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

float Vector2::inner(const Vector2 _other_) const
{
    return _x * _other_._x + _y * _other_._y;
}

float Vector2::outer(const Vector2 _other_) const
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

float inner(const Vector2 _left_, const Vector2 _right_)
{
    return _left_.x() * _right_.x() + _left_.y() * _right_.y();
}

float outer(const Vector2 _left_, const Vector2 _right_)
{
    return _left_.x() * _right_.y() - _left_.y() * _right_.x();
}