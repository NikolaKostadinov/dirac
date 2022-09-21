#pragma once

template <typename T>
struct Vertex1
{
    T x;

    Vertex1(T input_x = 0)
    {
        x = input_x;
    }
};

template <typename T>
struct Vertex2
{
    T x;
    T y;

    Vertex2(T input_x = 0, T input_y = 0)
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

    Vertex3(T input_x = 0, T input_y = 0, T input_z = 0)
    {
        x = input_x;
        y = input_y;
        z = input_z;
    }
};