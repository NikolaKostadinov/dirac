#include "../include/basis.hpp"

Basis::Basis()
{
    _is1D = false;
    _is2D = false;
    _is3D = false;
}

Basis::~Basis()
{
    // ... soon ...
}

int Basis::dimentions()
{
    if (_is3D) return 3;
    else if (_is2D) return 2;
    else if (_is1D) return 1;
    else if (!_is1D && !_is2D && !_is3D) return 0;
    else throw DIMENTION_ERROR;
}