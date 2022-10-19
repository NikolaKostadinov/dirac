#include "../include/field1.hpp"

template <class T>
Field1<T>::Field1()
{
    _size          = 0u      ;
    _toBase        = new Base;
    _originAddress = new T   ;
}

template <class T>
Field1<T>::~Field1()
{
    delete _toBase;

    for (uint32_t i = 0u; i < _size; i++)
        delete address(i);
}

template <class T>
Field1<T>::Field1(Base _base_)
{
    _size          =  _base_.size();
    _toBase        = &_base_       ;
    _originAddress =  new T        ;
}

template <class T>
Field1<T>::Field1(Base* _toBase_)
{
    _size          = _toBase_->size();
    _toBase        = _toBase_        ;
    _originAddress = new T           ;
}

template <class T>
void Field1<T>::setValues(T* _address_)
{
    _originAddress = _address_;
}

template <class T>
void Field1<T>::setValue(T _value_, uint32_t _index_)
{
    *address(_index_) = _value_;
}

template <class T>
uint32_t Field1<T>::size()
{
    return _size;
}

template <class T>
Base* Field1<T>::toBase()
{
    return _toBase;
}

template <class T>
Base Field1<T>::base()
{
    return *_toBase;
}

template <class T>
T* Field1<T>::address(uint32_t _index_)
{
    if (_index_ >= 0u && _index_ < _size)
        return _originAddress + _index_;
    else
        throw OUT_OF_BOUNDS;
}

template <class T>
T Field1<T>::value(uint32_t _index_)
{
    return *address(_index_);
}

template class Field1            <  signed       char   > ;
template class Field1            <unsigned       char   > ;
template class Field1            <  signed short int    > ;
template class Field1            <unsigned short int    > ;
template class Field1            <  signed       int    > ;
template class Field1            <unsigned       int    > ;
template class Field1            <  signed long  int    > ;
template class Field1            <unsigned long  int    > ;
template class Field1            <               float  > ;
template class Field1            <               double > ;
template class Field1            <         long  double > ;
template class Field1            <               Complex> ;
template class Field1<std::vector<  signed       char   >>;
template class Field1<std::vector<unsigned       char   >>;
template class Field1<std::vector<  signed       int    >>;
template class Field1<std::vector<unsigned       int    >>;
template class Field1<std::vector<  signed long  int    >>;
template class Field1<std::vector<unsigned long  int    >>;
template class Field1<std::vector<               float  >>;
template class Field1<std::vector<               double >>;
template class Field1<std::vector<         long  double >>;
template class Field1<std::vector<               Complex>>;