#include "../include/basis1.hpp"

Basis1::Basis1()
{
    _n = 0U;
    _toOrigin = new Vertex1<float>;
}

Basis1::~Basis1()
{
    delete[] _toOrigin;
}

Basis1::Basis1(Vertex1<float>* _toOrigin_, unsigned int _n_)
{
    _n = _n_;
    _toOrigin = _toOrigin_;
}

unsigned int Basis1::size()
{
    return _n;
}

Vertex1<float> Basis1::origin()
{
    return *_toOrigin;
}

Vertex1<float> Basis1::end()
{
    if (_n == 0U) return *_toOrigin;
    else return *(_toOrigin + _n - 1);
}

Vertex1<float> Basis1::vertex(unsigned int _index_)
{
    if (_index_ <= _n)
        return *(_toOrigin + _index_);
    else
        throw BASIS1_INDEX_TOO_LARGE;
}

Vertex1<float>* Basis1::toOrigin()
{
    return _toOrigin;
}

Vertex1<float>* Basis1::toEnd()
{
    if (_n == 0U) return _toOrigin;
    else return _toOrigin + _n - 1;
}

Vertex1<float>* Basis1::toVertex(unsigned int _index_)
{
    if (_index_ <= _n)
        return _toOrigin + _index_;
    else
        throw BASIS1_INDEX_TOO_LARGE;
}