#include "../include/basis2.hpp"

Basis2::Basis2()
{

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

uint32_t Basis2::size()
{
    return _toX->size() * _toY->size(); 
}

uint32_t Basis2::xSize()
{
    return _toX->size();
}

uint32_t Basis2::ySize()
{
    return _toY->size();
}

uint32_t Basis2::zSize()
{
    return 0u;
}

float Basis2::xStart()
{
    return _toX->start();
}

float Basis2::yStart()
{
    return _toY->start();
}

float Basis2::zStart()
{
    return 0.0F;
}

float Basis2::xEnd()
{
    return _toX->end();
}

float Basis2::yEnd()
{
    return _toY->end();
}

float Basis2::zEnd()
{
    return 0.0F;
}

float Basis2::dx()
{
    return _toX->dx();
}

float Basis2::dy()
{
    return _toY->dx();
}

float Basis2::dz()
{
    return 0.0F;
}

float Basis2::xLength()
{
    return _toX->length();
}

float Basis2::yLength()
{
    return _toY->length();
}

float Basis2::zLength()
{
    return 0.0F;
}

float Basis2::x(uint32_t _index_)
{
    return _toX->x(_index_);
}

float Basis2::y(uint32_t _index_)
{
    return _toY->x(_index_);
}

float Basis2::z(uint32_t _index_)
{
    return 0.0F;
}