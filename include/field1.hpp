#pragma once

#include "engine_exceptions.h"
#include "base.hpp"
#include "complex.hpp"

#include <vector>

template <class T>
class Field1
{
    public:

        Field1();
        virtual ~Field1();

        Field1(Base  _basis_  );
        Field1(Base* _toBasis_);

        void     setValues(T* _address_);

        uint32_t size  ();
        Base*    toBase();
        Base     base  ();

        T*       address(uint32_t _index_ = 0u);
        T        value  (uint32_t _index_     );

    protected:

        uint32_t _size         ;
        Base*    _toBase       ;
        T*       _originAddress;
};