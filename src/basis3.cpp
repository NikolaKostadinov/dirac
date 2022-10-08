#include "../include/basis3.hpp"

Basis3::Basis3()
{

}

Basis3::~Basis3()
{
    
}

Basis3::Basis3(Base _xBase_, Base _yBase_, Base _zBase_)
{
    _toX = &_xBase_;
    _toY = &_yBase_;
    _toZ = &_zBase_;
}

Basis3::Basis3(Base* _toXBase_, Base* _toYBase_, Base* _toZBase_)
{
    _toX = _toXBase_;
    _toY = _toYBase_;
    _toZ = _toZBase_;
}

uint32_t Basis3::size()
{
    return _toX->size() * _toY->size() * _toZ->size();
}

uint32_t Basis3::zSize()
{
    return _toZ->size();
}

float Basis3::zStart()
{
    return _toZ->start();
}

float Basis3::zEnd()
{
    return _toZ->end();
}

float Basis3::dz()
{
    return _toZ->dx();
}

float Basis3::zLength()
{
    return _toZ->length();
}

float Basis3::z(uint32_t _index_)
{
    return _toZ->x(_index_);
}