#include "../include/field2.hpp"

template <class T>
Field2<T>::Field2()
{
    _xSize         = 0u        ;
    _ySize         = 0u        ;
    _toBasis       = new Basis2;
    _originAddress = new T     ;
}

template <class T>
Field2<T>::~Field2()
{
    delete _toBasis;

    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            delete address(i, j);
}

template <class T>
Field2<T>::Field2(Basis2* _toBasis_)
{
    _xSize         = _toBasis_->xSize();
    _ySize         = _toBasis_->ySize();
    _toBasis       = _toBasis_         ;
    _originAddress = new T             ;
}

template <class T>
Field2<T>::Field2(Basis2 _basis_)
{
    _xSize         =  _basis_.xSize();
    _ySize         =  _basis_.ySize();
    _toBasis       = &_basis_        ;
    _originAddress =  new T          ;
}

template <class T>
void Field2<T>::setValues(T* _address_)
{
    _originAddress = _address_;
}

template <class T>
uint32_t Field2<T>::size()
{
    return _toBasis->size();
}

template <class T>
uint32_t Field2<T>::xSize()
{
    return _toBasis->xSize();
}

template <class T>
uint32_t Field2<T>::ySize()
{
    return _toBasis->ySize();
}

template <class T>
Basis2* Field2<T>::toBasis()
{
    return _toBasis;
}

template <class T>
Basis2 Field2<T>::basis()
{
    return *_toBasis;
}

template <class T>
T* Field2<T>::address(uint32_t _index_, uint32_t _jndex_)
{
    if (_index_ >= 0u && _index_ < _xSize)
    {
        if (_jndex_ >= 0u && _jndex_ < _ySize)
        {
            uint32_t backArea      = _jndex_ * xSize() ;
            return  _originAddress + _index_ + backArea;
        }
        else throw OUT_OF_Y_BOUNDS;
    }
    else throw OUT_OF_X_BOUNDS;
}

template <class T>
T Field2<T>::value(uint32_t _index_, uint32_t _jndex_)
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