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

Spinor Spinor::operator+()
{
    return *this;
}

Spinor Spinor::operator-()
{
    Complex up   = -_up  ;
    Complex down = -_down;

    return Spinor(up, down);
}

Spinor Spinor::operator+(Spinor _other_)
{
    Complex up   = _up   + _other_.up  ();
    Complex down = _down + _other_.down();

    return Spinor(up, down);
}

Spinor Spinor::operator-(Spinor _other_)
{
    Complex up   = _up   - _other_.up  ();
    Complex down = _down - _other_.down();

    return Spinor(up, down);
}

Spinor Spinor::operator*(Spinor _other_)
{
    Complex up   = _up   * _other_.up  ();
    Complex down = _down * _other_.down();

    return Spinor(up, down);
}

Spinor Spinor::operator/(Spinor _other_)
{
    Complex up   = _up   / _other_.up  ();
    Complex down = _down / _other_.down();

    return Spinor(up, down);
}

Complex Spinor::up()
{
    return _up;
}

Complex Spinor::down()
{
    return _down;
}

float Spinor::prob()
{
    return _up.conjSq() + _down.conjSq();
}