#include "../include/spinor.hpp"

Spinor::Spinor()
{
    _up   = Complex();
    _down = Complex();
}

Spinor::~Spinor()
{
    
}

Spinor::Spinor(Complex _up_, Complex _down_)
{
    _up   = _up_  ;
    _down = _down_;
}

void Spinor::scale(float _factor_)
{
    _up  .scale(_factor_);
    _down.scale(_factor_);
}

Spinor Spinor::operator+() const
{
    return *this;
}

Spinor Spinor::operator-() const
{
    Complex up   = -_up  ;
    Complex down = -_down;

    return Spinor(up, down);
}

Spinor Spinor::operator+(const Spinor _other_)
{
    Complex up   = _up   + _other_.up  ();
    Complex down = _down + _other_.down();

    return Spinor(up, down);
}

Spinor Spinor::operator-(const Spinor _other_)
{
    Complex up   = _up   - _other_.up  ();
    Complex down = _down - _other_.down();

    return Spinor(up, down);
}

Spinor Spinor::operator*(const Spinor _other_)
{
    Complex up   = _up   * _other_.up  ();
    Complex down = _down * _other_.down();

    return Spinor(up, down);
}

Spinor Spinor::operator/(const Spinor _other_)
{
    Complex up   = _up   / _other_.up  ();
    Complex down = _down / _other_.down();

    return Spinor(up, down);
}

Complex Spinor::up() const
{
    return _up;
}

Complex Spinor::down() const
{
    return _down;
}

float Spinor::prob() const
{
    return _up.conjSq() + _down.conjSq();
}