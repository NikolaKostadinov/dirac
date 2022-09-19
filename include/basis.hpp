#pragma once

#include <vector>
#include <stdexcept>
#include "vertex.h"

#define DIMENTION_ERROR std::logic_error("DIMENTION_ERROR")

template <typename T = float>
class Basis
{
    public:

        Basis<T>();
        ~Basis();

        Basis(T base_x[]);
        Basis(T base_x[], T base_y[]);
        Basis(T base_x[], T base_y[], T base_z[]);

        int dimentions();

    private:

        bool _is1D;
        bool _is2D;
        bool _is3D;
        std::vector<Vertex<T>> _coord;
};