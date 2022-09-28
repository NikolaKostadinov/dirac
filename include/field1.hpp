#pragma once

#include "base.hpp"

template <class T>
class Field1
{
    public:

        Field1();
        virtual ~Field1();

        Field1(Base _basis_);
        Field1(Base* _toBasis_);

        void setValues(T* _address_);

        unsigned int size();
        T* address(int _index_ = 0);
        T value(int _index_);

    protected:

        unsigned int _size;
        Base* _toBase;
        T* _toOriginValue;
};