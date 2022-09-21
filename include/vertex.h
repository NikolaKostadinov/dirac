#pragma once

template <typename T>
struct Vertex1
{
    T x;

    Vertex1(T input_x)
    {
        x = input_x;
    }
};

template <typename T>
struct Vertex2
{
    T x;
    T y;

    Vertex2(T input_x, T input_y)
    {
        x = input_x;
        y = input_y;
    }
};

template <typename T>
struct Vertex3
{
    T x;
    T y;
    T z;

    Vertex3(T input_x, T input_y, T input_z)
    {
        x = input_x;
        y = input_y;
        z = input_z;
    }
};