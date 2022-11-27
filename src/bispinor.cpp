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

void Bispinor::shrink(float _factor_)
{
    _positive.shrink(_factor_);
    _negative.shrink(_factor_);
}

void Bispinor::normalize(float _norm_)
{
    
}

Bispinor Bispinor::operator+() const
{
    return *this;
}

Bispinor Bispinor::operator-() const
{
    return Bispinor(-_positive, -_negative);
}

Bispinor Bispinor::operator+(const Bispinor _other_) const
{
    Spinor positive = _positive + _other_.positive();
    Spinor negative = _negative + _other_.negative();

    return Bispinor(positive, negative);
}

Bispinor Bispinor::operator-(const Bispinor _other_) const
{
    Spinor positive = _positive - _other_.positive();
    Spinor negative = _negative - _other_.negative();

    return Bispinor(positive, negative);
}

Bispinor Bispinor::operator*(const Bispinor _other_) const
{
    Spinor positive = _positive * _other_.positive();
    Spinor negative = _negative * _other_.negative();

    return Bispinor(positive, negative);
}

Bispinor Bispinor::operator/(const Bispinor _other_) const
{
    Spinor positive = _positive / _other_.positive();
    Spinor negative = _negative / _other_.negative();

    return Bispinor(positive, negative);
}

Spinor Bispinor::positive() const
{
    return _positive;
}

Spinor Bispinor::negative() const
{
    return _negative;
}

Complex Bispinor::posUp() const
{
    return _positive.up();
}

Complex Bispinor::posDown() const
{
    return _positive.down();
}

Complex Bispinor::negUp() const
{
    return _negative.up();
}

Complex Bispinor::negDown() const
{
    return _negative.down();
}

float Bispinor::prob() const
{
    return _positive.prob() + _negative.prob();
}