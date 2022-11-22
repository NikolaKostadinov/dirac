#include "../include/basis2.hpp"

Basis2::Basis2()
{
    _toX = new Base();
    _toY = new Base();
}

Basis2::~Basis2()
{
    
}

Basis2::Basis2(Base _xBase_, Base _yBase_)
{
    _toX = &_xBase_;
    _toY = &_yBase_;
}

Basis2::Basis2(Base* _toXBase_, Base* _toYBase_)
{
    _toX = _toXBase_;
    _toY = _toYBase_;
}

uint32_t Basis2::size() const
{
    return _toX->size() * _toY->size(); 
}

uint32_t Basis2::xSize() const
{
    return _toX->size();
}

uint32_t Basis2::ySize() const
{
    return _toY->size();
}

uint32_t Basis2::zSize() const
{
    return 0u;
}

float Basis2::xStart() const
{
    return _toX->start();
}

float Basis2::yStart() const
{
    return _toY->start();
}

float Basis2::zStart() const
{
    return 0.0f;
}

float Basis2::xEnd() const
{
    return _toX->end();
}

float Basis2::yEnd() const
{
    return _toY->end();
}

float Basis2::zEnd() const
{
    return 0.0f;
}

float Basis2::dx() const
{
    return _toX->dx();
}

float Basis2::dy() const
{
    return _toY->dx();
}

float Basis2::dz() const
{
    return 0.0f;
}

float Basis2::xLength() const
{
    return _toX->length();
}

float Basis2::yLength() const
{
    return _toY->length();
}

float Basis2::zLength() const
{
    return 0.0f;
}

float Basis2::x(uint32_t _index_) const
{
    return _toX->x(_index_);
}

float Basis2::y(uint32_t _jndex_) const
{
    return _toY->x(_jndex_);
}

float Basis2::z(uint32_t _kndex_) const
{
    return 0.0f;
}