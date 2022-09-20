#pragma once

#include <vector>
#include <stdexcept>
#include "path.hpp"

#define DIMENTION_ERROR std::logic_error("DIMENTION_ERROR")

template <typename T>
class Basis
{
    public:

        Basis();
        ~Basis();

        Basis(Path<T> base_x);
        Basis(Path<T> base_x, Path<T> base_y);
        Basis(Path<T> base_x, Path<T> base_y, Path<T> base_z);

        int dimentions();

    private:

        bool _is1D;
        bool _is2D;
        bool _is3D;

        Path<T> _x;
        Path<T> _y;
        Path<T> _z;
};