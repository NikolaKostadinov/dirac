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