#pragma once

#include <vector>
#include "vertex.h"

#define VERTEX_ARRAY std::vector<Vertex<T>>

template <typename T>
class Path
{
    public:

        Path();
        ~Path();

        Path(VERTEX_ARRAY vertices);

        bool isCurved();
        int size();
        //float length();

        /*T operator[](int index);*/

    private:

        VERTEX_ARRAY _vertices;
};