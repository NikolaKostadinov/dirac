#pragma once

#include <vector>
#include <stdexcept>
#include "vertex.h"

#define DIMENTION_ERROR std::logic_error("DIMENTION_ERROR")

class Basis
{
    public:

        Basis();
        ~Basis();

        int dimentions();

    private:

        bool _is1D;
        bool _is2D;
        bool _is3D;
        std::vector<Vertex<float>> _coord;
};