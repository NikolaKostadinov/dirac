#include "../include/spinor2.hpp"

Spinor2::Spinor2()
{
    _up   = Complex();
    _down = Complex();
}

Spinor2::~Spinor2()
{
    
}

Spinor2::Spinor2(Complex _up_, Complex _down_)
{
    _up   = _up_  ;
    _down = _down_;
}

void Spinor2::scale(float _factor_)
{
    _up  .scale(_factor_);
    _down.scale(_factor_);
}

Spinor2 Spinor2::operator+()
{
    return *this;
}

Spinor2 Spinor2::operator-()
{
    Complex up   = -_up  ;
    Complex down = -_down;

    return Spinor2(up, down);
}

Spinor2 Spinor2::operator+(Spinor2 _other_)
{
    Complex up   = _up   + _other_.up  ();
    Complex down = _down + _other_.down();

    return Spinor2(up, down);
}

Spinor2 Spinor2::operator-(Spinor2 _other_)
{
    Complex up   = _up   - _other_.up  ();
    Complex down = _down - _other_.down();

    return Spinor2(up, down);
}

Spinor2 Spinor2::operator*(Spinor2 _other_)
{
    Complex up   = _up   * _other_.up  ();
    Complex down = _down * _other_.down();

    return Spinor2(up, down);
}

Spinor2 Spinor2::operator/(Spinor2 _other_)
{
    Complex up   = _up   / _other_.up  ();
    Complex down = _down / _other_.down();

    return Spinor2(up, down);
}

Complex Spinor2::up()
{
    return _up;
}

Complex Spinor2::down()
{
    return _down;
}

float Spinor2::prob()
{
    return _up.conjSq() + _down.conjSq();
}