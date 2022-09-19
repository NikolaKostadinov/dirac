#pragma once

#include <vector>
#include <stdexcept>
#include "vertex.h"

#define VERTEX_ARRAY std::vector<Vertex<T>>

#define DIMENTION_ERROR std::logic_error("DIMENTION_ERROR")

template <typename T = float>
class Basis
{
    public:

        Basis<T>();
        ~Basis();

        Basis(VERTEX_ARRAY base_x);
        Basis(VERTEX_ARRAY base_x, VERTEX_ARRAY base_y);
        Basis(VERTEX_ARRAY base_x, VERTEX_ARRAY base_y, VERTEX_ARRAY base_z);

        int dimentions();

    private:

        bool _is1D;
        bool _is2D;
        bool _is3D;

        VERTEX_ARRAY _x;
        VERTEX_ARRAY _y;
        VERTEX_ARRAY _z;
};