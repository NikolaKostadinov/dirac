#include "../include/bispinor.hpp"

Bispinor::Bispinor()
{
    _positive = Spinor();
    _negative = Spinor();
}

Bispinor::~Bispinor()
{
    
}

Bispinor::Bispinor(Spinor _positive_, Spinor _negative_)
{
    _positive = _positive_;
    _negative = _negative_;
}

void Bispinor::scale(float _factor_)
{
    _positive.scale(_factor_);
    _negative.scale(_factor_);
}

Bispinor Bispinor::operator+()
{
    return *this;
}

Bispinor Bispinor::operator-()
{
    Spinor positive = -_positive;
    Spinor negative = -_negative;

    return Bispinor(positive, negative);
}

Bispinor Bispinor::operator+(Bispinor _other_)
{
    Spinor positive = _positive + _other_.positive();
    Spinor negative = _negative + _other_.negative();

    return Bispinor(positive, negative);
}

Bispinor Bispinor::operator-(Bispinor _other_)
{
    Spinor positive = _positive - _other_.positive();
    Spinor negative = _negative - _other_.negative();

    return Bispinor(positive, negative);
}

Bispinor Bispinor::operator*(Bispinor _other_)
{
    Spinor positive = _positive * _other_.positive();
    Spinor negative = _negative * _other_.negative();

    return Bispinor(positive, negative);
}

Bispinor Bispinor::operator/(Bispinor _other_)
{
    Spinor positive = _positive / _other_.positive();
    Spinor negative = _negative / _other_.negative();

    return Bispinor(positive, negative);
}

Spinor Bispinor::positive()
{
    return _positive;
}

Spinor Bispinor::negative()
{
    return _negative;
}

Complex Bispinor::posUp()
{
    return _positive.up();
}

Complex Bispinor::posDown()
{
    return _positive.down();
}

Complex Bispinor::negUp()
{
    return _negative.up();
}

Complex Bispinor::negDown()
{
    return _negative.down();
}

float Bispinor::prob()
{
    return _positive.prob() + _negative.prob();
}