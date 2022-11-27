#include "../include/vector3.hpp"

Vector3::Vector3() : Vector3(0.0f, 0.0f, 0.0f)
{

}

Vector3::~Vector3()
{

}

Vector3::Vector3(float _x_, float _y_, float _z_)
{
    _x = _x_;
    _y = _y_;
    _z = _z_;
}

void Vector3::scale(float _factor_)
{
    _x *= _factor_;
    _y *= _factor_;
    _z *= _factor_;
}

void Vector3::shrink(float _factor_)
{
    _x /= _factor_;
    _y /= _factor_;
    _z /= _factor_;
}

void Vector3::normalize(float _norm_)
{
    scale(1.0f);
}

Vector3 Vector3::operator+() const
{
    return *this;
}

Vector3 Vector3::operator-() const
{
    return Vector3(-_x, -_y, -_z);
}

Vector3 Vector3::operator+(const Vector3 _other_) const
{
    float x = _x + _other_._x;
    float y = _y + _other_._y;
    float z = _z + _other_._z;

    return Vector3(x, y, z);
}

Vector3 Vector3::operator-(const Vector3 _other_) const
{
    float x = _x - _other_._x;
    float y = _y - _other_._y;
    float z = _z - _other_._z;

    return Vector3(x, y, z);
}

Vector3 Vector3::operator*(const Vector3 _other_) const
{
    float x = _x * _other_._x;
    float y = _y * _other_._y;
    float z = _z * _other_._z;

    return Vector3(x, y, z);
}

Vector3 Vector3::operator/(const Vector3 _other_) const
{
    float x = _x / _other_._x;
    float y = _y / _other_._y;
    float z = _z / _other_._z;

    return Vector3(x, y, z);
}

Vector3& Vector3::operator+=(const Vector3 _other_)
{
    _x += _other_._x;
    _y += _other_._y;
    _z += _other_._z;

    return *this;
}

Vector3& Vector3::operator-=(const Vector3 _other_)
{
    _x -= _other_._x;
    _y -= _other_._y;
    _z -= _other_._z;

    return *this;
}

Vector3& Vector3::operator*=(const Vector3 _other_)
{
    _x *= _other_._x;
    _y *= _other_._y;
    _z *= _other_._z;

    return *this;
}

Vector3& Vector3::operator/=(const Vector3 _other_)
{
    _x /= _other_._x;
    _y /= _other_._y;
    _z /= _other_._z;

    return *this;
}

bool Vector3::operator==(const Vector3 _other_) const
{
    return (_x == _other_._x) && (_y == _other_._y) && (_z == _other_._z);
}

float Vector3::x() const
{
    return _x;
}

float Vector3::y() const
{
    return _y;
}

float Vector3::z() const
{
    return _z;
}

float Vector3::length() const
{
    return sqrt( sq() );
}

float Vector3::sq() const
{
    return _x * _x + _y * _y + _z * _z;
}

float Vector3::dot(const Vector3 _other_) const
{
    return _x * _other_._x + _y * _other_._y + _z * _other_._z;
}

Vector3 Vector3::cross(const Vector3 _other_) const
{
    float x = _y * _other_._z - _z * _other_._y;
    float y = _z * _other_._x - _x * _other_._z;
    float z = _x * _other_._y - _y * _other_._x;

    return Vector3(x, y, z);
}

void Vector3::crossWith(const Vector3 _other_)
{
    *this = this->cross(_other_);
}

std::string Vector3::string()
{
    std::ostringstream stream;
    stream << "[ ";
    stream << _x  ;
    stream << ", ";
    stream << _y  ;
    stream << ", ";
    stream << _z  ;
    stream << " ]";

    return stream.str();
}

float dot(const Vector3 _left_, const Vector3 _right_)
{
    return _left_.dot(_right_);
}

Vector3 cross(const Vector3 _left_, const Vector3 _right_)
{
    return _left_.cross(_right_);
}