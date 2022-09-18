#include "../include/basis.hpp"
#include "../include/boolbase.h"

template <typename T>
Basis<T>::Basis()
{
    setFalse(_is1D, _is2D, _is3D);
}

template <typename T>
Basis<T>::~Basis()
{
    // ... soon ...
}

template <typename T>
Basis<T>::Basis(T base_x[])
{
    setX(_is1D, _is2D, _is3D);
    // ... soon ...
}

template <typename T>
Basis<T>::Basis(T base_x[], T base_y[])
{
    setY(_is1D, _is2D, _is3D);
    // ... soon ...
}

template <typename T>
Basis<T>::Basis(T base_x[], T base_y[], T base_z[])
{
    setZ(_is1D, _is2D, _is3D);
    // ... soon ...
}

template <typename T>
int Basis<T>::dimentions()
{
    if (_is3D) return 3;
    else if (_is2D) return 2;
    else if (_is1D) return 1;
    else if (!_is1D && !_is2D && !_is3D) return 0;
    else throw DIMENTION_ERROR;
}