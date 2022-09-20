#include "../include/path.hpp"

template <typename T>
Path<T>::Path()
{
    _vertices = VERTEX_ARRAY();
}

template <typename T>
Path<T>::~Path()
{
    // goodbye line
}

template <typename T>
Path<T>::Path(VERTEX_ARRAY vertices)
{
    _vertices = vertices;
}

template <typename T>
bool Path<T>::isCurved()
{
    // math stuff
    return false;
}

template <typename T>
int Path<T>::size()
{
    return _vertices.size();
}

/*template <typename T>
T Path<T>::operator[](int index)
{
    return _vertices[index];
}*/

template class Path<float>;
template class Path<int>;
template class Path<long>;
template class Path<double>;