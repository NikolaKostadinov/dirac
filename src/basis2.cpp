#include "../include/basis2.hpp"

Basis2::Basis2()
{
    _nx = 0U;
    _nx = 0U;
    _toOriginX = new Vertex2<float>;
    _toOriginY = new Vertex2<float>;
}

Basis2::~Basis2()
{
    delete[] _toOriginX;
    delete[] _toOriginY;
}

Basis2::Basis2(Vertex2<float>* _toOriginX_, Vertex2<float>* _toOriginY_, unsigned int _nx_, unsigned int _ny_)
{
    _nx = _nx_;
    _ny = _ny_;
    _toOriginX = _toOriginX_;
    _toOriginY = _toOriginY_;
}

unsigned int Basis2::xSize()
{
    return _nx;
}

unsigned int Basis2::ySize()
{
    return _nx;
}