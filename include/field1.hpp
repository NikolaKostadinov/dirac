#pragma once

#include "base.hpp"
#include "complex.hpp"
#include "exceptions.h"

template <class T>
class Field1
{
    public:

        Field1();
        virtual ~Field1();

        Field1(Base  _basis_  );
        Field1(Base* _toBasis_);

        void setValues(T* _address_);
        void setValue (T  _value_  , unsigned int _index_);

        unsigned int size();
        Base* toBase();
        Base  base  ();
        T* address(unsigned int _index_ = 0U);
        T  value  (unsigned int _index_     );

    protected:

        unsigned int _size;
        Base* _toBase;
        T* _originAddress;
};