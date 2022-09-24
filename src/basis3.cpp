#include "../include/basis3.hpp"

Basis3::Basis3()
{
    _nx = 0;
    _ny = 0;
    _nz = 0;
    _toXOrigin = new Vertex3<float>;
    _toYOrigin = new Vertex3<float>;
    _toZOrigin = new Vertex3<float>;
}

Basis3::~Basis3()
{
    delete[] _toXOrigin;
    delete[] _toYOrigin;
    delete[] _toZOrigin;
}

Basis3::Basis3(Vertex3<float>* _toXOrigin_, Vertex3<float>* _toYOrigin_, Vertex3<float>* _toZOrigin_, unsigned int _nx_, unsigned int _ny_, unsigned int _nz_)
{
    _nx = _nx_;
    _ny = _ny_;
    _nz = _nz_;
    _toXOrigin = _toXOrigin_;
    _toYOrigin = _toYOrigin_;
    _toZOrigin = _toZOrigin_;
}

unsigned int Basis3::xSize()
{
    return _nx;
}

unsigned int Basis3::ySize()
{
    return _ny;
}

unsigned int Basis3::zSize()
{
    return _nz;
}

Vertex3<float> Basis3::xOrigin()
{
    return *_toXOrigin;
}

Vertex3<float> Basis3::yOrigin()
{
    return *_toYOrigin;
}

Vertex3<float> Basis3::zOrigin()
{
    return *_toZOrigin;
}

Vertex3<float> Basis3::xEnd()
{
    if (_nx == 0U) return *_toXOrigin;
    else return *(_toXOrigin + _nx - 1);
}

Vertex3<float> Basis3::yEnd()
{
    if (_ny == 0U) return *_toYOrigin;
    else return *(_toYOrigin + _ny - 1);
}

Vertex3<float> Basis3::zEnd()
{
    if (_nz == 0U) return *_toZOrigin;
    else return *(_toZOrigin + _nz - 1);
}

Vertex3<float> Basis3::xAxisAt(unsigned int _index_)
{
    if (_index_ <= _nx)
        return *(_toXOrigin + _index_);
    else
        throw BASIS3_INDEX_TOO_LARGE;
}

Vertex3<float> Basis3::yAxisAt(unsigned int _index_)
{
    if (_index_ <= _ny)
        return *(_toYOrigin + _index_);
    else
        throw BASIS3_INDEX_TOO_LARGE;
}

Vertex3<float> Basis3::zAxisAt(unsigned int _index_)
{
    if (_index_ <= _nz)
        return *(_toZOrigin + _index_);
    else
        throw BASIS3_INDEX_TOO_LARGE;
}

Vertex3<float>* Basis3::toXOrigin()
{
    return _toXOrigin;
}

Vertex3<float>* Basis3::toYOrigin()
{
    return _toYOrigin;
}

Vertex3<float>* Basis3::toZOrigin()
{
    return _toZOrigin;
}

Vertex3<float>* Basis3::toXEnd()
{
    if (_nx == 0U) return _toXOrigin;
    else return _toXOrigin + _nx - 1;
}

Vertex3<float>* Basis3::toYEnd()
{
    if (_ny == 0U) return _toYOrigin;
    else return _toYOrigin + _ny - 1;
}

Vertex3<float>* Basis3::toZEnd()
{
    if (_nz == 0U) return _toZOrigin;
    else return _toZOrigin + _nz - 1;
}

Vertex3<float>* Basis3::toXAxisAt(unsigned int _index_)
{
    if (_index_ <= _nx)
        return _toXOrigin + _index_;
    else
        throw BASIS3_INDEX_TOO_LARGE;
}

Vertex3<float>* Basis3::toYAxisAt(unsigned int _index_)
{
    if (_index_ <= _ny)
        return _toYOrigin + _index_;
    else
        throw BASIS3_INDEX_TOO_LARGE;
}

Vertex3<float>* Basis3::toZAxisAt(unsigned int _index_)
{
    if (_index_ <= _nz)
        return _toZOrigin + _index_;
    else
        throw BASIS3_INDEX_TOO_LARGE;
}