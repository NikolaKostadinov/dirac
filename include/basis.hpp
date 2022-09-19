#pragma once

#include <vector>
#include <stdexcept>
#include "vertex.h"
#include "line.hpp"

#define DIMENTION_ERROR std::logic_error("DIMENTION_ERROR")

template <typename T>
class Basis
{
    public:

        Basis<T>();
        ~Basis();

        Basis(Line<T> base_x);
        Basis(Line<T> base_x, Line<T> base_y);
        Basis(Line<T> base_x, Line<T> base_y, Line<T> base_z);

        int dimentions();

    private:

        bool _is1D;
        bool _is2D;
        bool _is3D;

        Line<T> _x;
        Line<T> _y;
        Line<T> _z;
};