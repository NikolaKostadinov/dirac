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

Vector2 Basis2::operator()(uint32_t _index_, uint32_t _jndex_) const
{
    return coord(_index_,_jndex_);
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

float Basis2::xDelta() const
{
    return _toX->delta();
}

float Basis2::yDelta() const
{
    return _toY->delta();
}

float Basis2::zDelta() const
{
    return 0.0f;
}

float Basis2::xDelta2() const
{
    return _toX->delta2();
}

float Basis2::yDelta2() const
{
    return _toY->delta2();
}

float Basis2::zDelta2() const
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

float Basis2::xCoord(uint32_t _index_) const
{
    return _toX->coord(_index_);
}

float Basis2::yCoord(uint32_t _jndex_) const
{
    return _toY->coord(_jndex_);
}

float Basis2::zCoord(uint32_t _kndex_) const
{
    return 0.0f;
}

Vector2 Basis2::coord(uint32_t _index_, uint32_t _jndex_) const
{
    return Vector2(xCoord(_index_),
                   yCoord(_jndex_));
}