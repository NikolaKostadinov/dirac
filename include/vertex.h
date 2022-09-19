#pragma once

template <typename T>
struct Vertex
{
    T x;
    T y;
    T z;

    Vertex()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vertex(T input_x, T input_y, T input_z)
    {
        x = input_x;
        y = input_y;
        z = input_z;
    }
};
