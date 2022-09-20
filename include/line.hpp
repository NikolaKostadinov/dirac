#pragma once

#include "vertex.h"

template <typename T>
class Line
{
    public:

        Vertex<T>* start;
        Vertex<T>* end;

        Line();
        ~Line();

        Line(Vertex<T>* input_start, Vertex<T>* input_end);

        float lenght();
        float dir();
};