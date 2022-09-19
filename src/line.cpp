#include "../include/line.hpp"

template <typename T>
Line<T>::Line()
{
    _vertices = VERTEX_ARRAY();
}

template <typename T>
Line<T>::~Line()
{
    // goodbye line
}

template <typename T>
Line<T>::Line(VERTEX_ARRAY vertices)
{
    _vertices = vertices;
}

template <typename T>
bool Line<T>::isCurved()
{
    // math stuff
    return false;
}

/*template <typename T>
T Line<T>::operator[](int index)
{
    return _vertices[index];
}*/

template class Line<float>;
template class Line<int>;
template class Line<long>;
template class Line<double>;