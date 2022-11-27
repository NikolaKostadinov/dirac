#include "../include/field3.hpp"

template <class T>
Field3<T>::Field3()
{
    _toBasis       = new Basis3;
    _originAddress = new T     ;
}

template <class T>
Field3<T>::~Field3()
{
    uint32_t  rempXSize = xSize();
    uint32_t  rempYSize = ySize();
    uint32_t  rempZSize = zSize();
    delete   _toBasis;

    for (uint32_t i = 0u; i < rempXSize; i++)
        for (uint32_t j = 0u; j < rempYSize; j++)
            for (uint32_t k = 0u; k < rempZSize; k++)
                delete address(i, j, k);
}

template <class T>
Field3<T>::Field3(Basis3* _toBasis_)
{
    _toBasis       = _toBasis_;
    _originAddress = new T    ;
}

template <class T>
Field3<T>::Field3(Basis3 _basis_)
{
    _toBasis       = &_basis_;
    _originAddress =  new T  ;
}

template <class T>
void Field3<T>::setValues(T* _address_)
{
    _originAddress = _address_;
}

template <class T>
uint32_t Field3<T>::size() const
{
    return _toBasis->size();
}

template <class T>
uint32_t Field3<T>::xSize() const
{
    return _toBasis->xSize();
}

template <class T>
uint32_t Field3<T>::ySize() const
{
    return _toBasis->ySize();
}

template <class T>
uint32_t Field3<T>::zSize() const
{
    return _toBasis->zSize();
}

template <class T>
Basis3* Field3<T>::toBasis() const
{
    return _toBasis;
}

template <class T>
Basis3 Field3<T>::basis() const
{
    return *_toBasis;
}

template <class T>
T* Field3<T>::address(uint32_t _index_, uint32_t _jndex_, uint32_t _kindex_) const
{
    uint32_t  rempXSize = xSize();
    uint32_t  rempYSize = ySize();
    uint32_t  rempZSize = zSize();

    if (_index_ >= 0u && _index_ < rempXSize)
    {
        if (_jndex_ >= 0u && _jndex_ < rempYSize)
        {
            if (_kindex_ >= 0u && _kindex_ < rempZSize)
            {
                uint32_t backVolume     = _kindex_ * rempXSize * rempYSize ;
                uint32_t backArea       = _jndex_  * rempXSize             ;
                return   _originAddress + _index_  + backArea  + backVolume;
            }
            else throw OUT_OF_Z_BOUNDS;
        }
        else throw OUT_OF_Y_BOUNDS;
    }
    else throw OUT_OF_X_BOUNDS;
}

template <class T>
T Field3<T>::value(uint32_t _index_, uint32_t _jndex_, uint32_t _kindex_) const
{
    return *address(_index_, _jndex_, _kindex_);
}

template class Field3            <  signed       char   > ;
template class Field3            <unsigned       char   > ;
template class Field3            <  signed short int    > ;
template class Field3            <unsigned short int    > ;
template class Field3            <  signed       int    > ;
template class Field3            <unsigned       int    > ;
template class Field3            <  signed long  int    > ;
template class Field3            <unsigned long  int    > ;
template class Field3            <               float  > ;
template class Field3            <               double > ;
template class Field3            <         long  double > ;
template class Field3            <               Complex> ;
template class Field3            <               Vector2> ;
template class Field3            <               Vector3> ;
template class Field3<std::vector<  signed       char   >>;
template class Field3<std::vector<unsigned       char   >>;
template class Field3<std::vector<  signed       int    >>;
template class Field3<std::vector<unsigned       int    >>;
template class Field3<std::vector<  signed long  int    >>;
template class Field3<std::vector<unsigned long  int    >>;
template class Field3<std::vector<               float  >>;
template class Field3<std::vector<               double >>;
template class Field3<std::vector<         long  double >>;
template class Field3<std::vector<               Complex>>;