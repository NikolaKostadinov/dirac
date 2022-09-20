#include "../include/basis.hpp"

template <typename T>
Basis<T>::Basis()
{
    _is1D = false;
    _is2D = false;
    _is3D = false;
}

template <typename T>
Basis<T>::~Basis()
{
    // destructor logic got lost in the quantum realm
}

template <typename T>
Basis<T>::Basis(Path<T> base_x)
{
    _is1D = true;
    _is2D = false;
    _is3D = false;

    _x = base_x;
}

template <typename T>
Basis<T>::Basis(Path<T> base_x, Path<T> base_y)
{
    _is1D = false;
    _is2D = true;
    _is3D = false;

    _x = base_x;
    _y = base_y;
}

template <typename T>
Basis<T>::Basis(Path<T> base_x, Path<T> base_y, Path<T> base_z)
{
    _is1D = false;
    _is2D = false;
    _is3D = true;

    _x = base_x;
    _y = base_y;
    _z = base_z;
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

template class Basis<float>;
template class Basis<int>;
template class Basis<long>;
template class Basis<double>;