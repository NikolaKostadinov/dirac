#include "../include/basis2.hpp"

Basis2::Basis2()
{
    _nx = 0U;
    _nx = 0U;
    _toXOrigin = new Vertex2<float>;
    _toYOrigin = new Vertex2<float>;
}

Basis2::~Basis2()
{
    delete[] _toXOrigin;
    delete[] _toYOrigin;
}

Basis2::Basis2(Vertex2<float>* _toOriginX_, Vertex2<float>* _toOriginY_, unsigned int _nx_, unsigned int _ny_)
{
    _nx = _nx_;
    _ny = _ny_;
    _toXOrigin = _toOriginX_;
    _toYOrigin = _toOriginY_;
}

unsigned int Basis2::xSize()
{
    return _nx;
}

unsigned int Basis2::ySize()
{
    return _nx;
}

Vertex2<float> Basis2::xOrigin()
{
    return *_toXOrigin;
}

Vertex2<float> Basis2::yOrigin()
{
    return *_toYOrigin;
}

Vertex2<float> Basis2::xEnd()
{
    if (_nx == 0U) return *_toXOrigin;
    else return *(_toXOrigin + _nx - 1);
}

Vertex2<float> Basis2::yEnd()
{
    if (_ny == 0U) return *_toYOrigin;
    else return *(_toYOrigin + _ny - 1);
}

Vertex2<float> Basis2::xAxisAt(unsigned int _index_)
{
    if (_index_ <= _nx)
        return *(_toXOrigin + _index_);
    else
        throw BASIS2_INDEX_TOO_LARGE;
}

Vertex2<float> Basis2::yAxisAt(unsigned int _index_)
{
    if (_index_ <= _ny)
        return *(_toYOrigin + _index_);
    else
        throw BASIS2_INDEX_TOO_LARGE;
}

Vertex2<float>* Basis2::toXOrigin()
{
    return _toXOrigin;
}

Vertex2<float>* Basis2::toYOrigin()
{
    return _toYOrigin;
}

Vertex2<float>* Basis2::toXEnd()
{
    if (_nx == 0U) return _toXOrigin;
    else return _toXOrigin + _nx - 1;
}

Vertex2<float>* Basis2::toYEnd()
{
    if (_ny == 0U) return _toYOrigin;
    else return _toYOrigin + _ny - 1;
}

Vertex2<float>* Basis2::toXAxisAt(unsigned int _index_)
{
    if (_index_ <= _nx)
        return _toXOrigin + _index_;
    else
        throw BASIS2_INDEX_TOO_LARGE;
}

Vertex2<float>* Basis2::toYAxisAt(unsigned int _index_)
{
    if (_index_ <= _ny)
        return _toYOrigin + _index_;
    else
        throw BASIS2_INDEX_TOO_LARGE;
}