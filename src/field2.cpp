#include "../include/field2.hpp"

template <class T>
Field2<T>::Field2()
{
    _toBasis       = new Basis2;
    _originAddress = new T     ;
}

template <class T>
Field2<T>::~Field2()
{
    uint32_t  rempXSize = xSize();
    uint32_t  rempYSize = ySize();
    delete   _toBasis;

    for (uint32_t i = 0u; i < rempXSize; i++)
        for (uint32_t j = 0u; j < rempYSize; j++)
            delete address(i, j);
}

template <class T>
Field2<T>::Field2(Basis2* _toBasis_)
{
    _toBasis       = _toBasis_;
    _originAddress = new T    ;
}

template <class T>
Field2<T>::Field2(Basis2 _basis_)
{
    _toBasis       = &_basis_;
    _originAddress =  new T  ;
}

template <class T>
void Field2<T>::setValues(T* _address_)
{
    _originAddress = _address_;
}

template <class T>
uint32_t Field2<T>::size() const
{
    return _toBasis->size();
}

template <class T>
uint32_t Field2<T>::xSize() const
{
    return _toBasis->xSize();
}

template <class T>
uint32_t Field2<T>::ySize() const
{
    return _toBasis->ySize();
}

template <class T>
Basis2* Field2<T>::toBasis() const
{
    return _toBasis;
}

template <class T>
Basis2 Field2<T>::basis() const
{
    return *_toBasis;
}

template <class T>
T* Field2<T>::address(uint32_t _index_, uint32_t _jndex_) const
{
    uint32_t  rempXSize = xSize();
    uint32_t  rempYSize = ySize();

    if (_index_ >= 0u && _index_ < rempXSize)
    {
        if (_jndex_ >= 0u && _jndex_ < rempYSize)
        {
            uint32_t backArea      = _jndex_ * rempXSize;
            return  _originAddress + _index_ + backArea ;
        }
        else throw OUT_OF_Y_BOUNDS;
    }
    else throw OUT_OF_X_BOUNDS;
}

template <class T>
T Field2<T>::value(uint32_t _index_, uint32_t _jndex_) const
{
    return *address(_index_, _jndex_);
}

template class Field2            <  signed       char   > ;
template class Field2            <unsigned       char   > ;
template class Field2            <  signed short int    > ;
template class Field2            <unsigned short int    > ;
template class Field2            <  signed       int    > ;
template class Field2            <unsigned       int    > ;
template class Field2            <  signed long  int    > ;
template class Field2            <unsigned long  int    > ;
template class Field2            <               float  > ;
template class Field2            <               double > ;
template class Field2            <         long  double > ;
template class Field2            <               Complex> ;
template class Field2            <               Vector2> ;
template class Field2            <               Vector3> ;
template class Field2<std::vector<  signed       char   >>;
template class Field2<std::vector<unsigned       char   >>;
template class Field2<std::vector<  signed       int    >>;
template class Field2<std::vector<unsigned       int    >>;
template class Field2<std::vector<  signed long  int    >>;
template class Field2<std::vector<unsigned long  int    >>;
template class Field2<std::vector<               float  >>;
template class Field2<std::vector<               double >>;
template class Field2<std::vector<         long  double >>;
template class Field2<std::vector<               Complex>>;