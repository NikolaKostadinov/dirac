#include "../include/spinor4.hpp"

Spinor4::Spinor4()
{
    _positive = Spinor2();
    _negative = Spinor2();
}

Spinor4::~Spinor4()
{
    
}

Spinor4::Spinor4(Spinor2 _positive_, Spinor2 _negative_)
{
    _positive = _positive_;
    _negative = _negative_;
}

void Spinor4::scale(float _factor_)
{
    _positive.scale(_factor_);
    _negative.scale(_factor_);
}

Spinor4 Spinor4::operator+()
{
    return *this;
}

Spinor4 Spinor4::operator-()
{
    Spinor2 positive = -_positive;
    Spinor2 negative = -_negative;

    return Spinor4(positive, negative);
}

Spinor4 Spinor4::operator+(Spinor4 _other_)
{
    Spinor2 positive = _positive + _other_.positive();
    Spinor2 negative = _negative + _other_.negative();

    return Spinor4(positive, negative);
}

Spinor4 Spinor4::operator-(Spinor4 _other_)
{
    Spinor2 positive = _positive - _other_.positive();
    Spinor2 negative = _negative - _other_.negative();

    return Spinor4(positive, negative);
}

Spinor4 Spinor4::operator*(Spinor4 _other_)
{
    Spinor2 positive = _positive * _other_.positive();
    Spinor2 negative = _negative * _other_.negative();

    return Spinor4(positive, negative);
}

Spinor4 Spinor4::operator/(Spinor4 _other_)
{
    Spinor2 positive = _positive / _other_.positive();
    Spinor2 negative = _negative / _other_.negative();

    return Spinor4(positive, negative);
}

Spinor2 Spinor4::positive()
{
    return _positive;
}

Spinor2 Spinor4::negative()
{
    return _negative;
}

Complex Spinor4::posUp()
{
    return _positive.up();
}

Complex Spinor4::posDown()
{
    return _positive.down();
}

Complex Spinor4::negUp()
{
    return _negative.up();
}

Complex Spinor4::negDown()
{
    return _negative.down();
}

float Spinor4::prob()
{
    return _positive.prob() + _negative.prob();
}