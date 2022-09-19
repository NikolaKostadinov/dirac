#pragma once

#include <vector>
#include "vertex.h"

#define VERTEX_ARRAY std::vector<Vertex<T>>

template <typename T>
class Line
{
    public:

        Line();
        ~Line();

        Line(VERTEX_ARRAY vertices);

        bool isCurved();
        int size();
        //float length();

        /*T operator[](int index);*/

    private:

        std::vector<Vertex<T>> _vertices;
};