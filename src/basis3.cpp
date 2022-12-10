#include "../include/basis3.hpp"

Basis3::Basis3()
{
    _toZ = new Base();
}

Basis3::~Basis3()
{
    
}

Basis3::Basis3(Base _xBase_, Base _yBase_, Base _zBase_) : Basis2(_xBase_, _yBase_)
{
    _toZ = &_zBase_;
}

Basis3::Basis3(Base* _toXBase_, Base* _toYBase_, Base* _toZBase_) : Basis2(_toXBase_, _toYBase_)
{
    _toZ = _toZBase_;
}

Vector3 Basis3::operator()(uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_) const
{
    return coord(_index_,_jndex_,_kndex_);
}

uint32_t Basis3::size() const
{
    return _toX->size() * _toY->size() * _toZ->size();
}

uint32_t Basis3::zSize() const
{
    return _toZ->size();
}

float Basis3::zStart() const
{
    return _toZ->start();
}

float Basis3::zEnd() const
{
    return _toZ->end();
}

float Basis3::zDelta() const
{
    return _toZ->delta();
}

float Basis3::zDelta2() const
{
    return _toZ->delta2();
}

float Basis3::zLength() const
{
    return _toZ->length();
}

float Basis3::zCoord(uint32_t _kndex_) const
{
    return _toZ->coord(_kndex_);
}

Vector3 Basis3::coord(uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_) const
{
    return Vector3(xCoord(_index_),
                   yCoord(_jndex_),
                   zCoord(_kndex_));
}
