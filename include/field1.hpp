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

        Field1(Base  _base_  );
        Field1(Base* _toBase_);

        void     setValues(T*    _address_);
        void     setBase  (Base* _toBase_ );
        void     setSize  (uint32_t _size_);

        uint32_t size  ()                       const;
        Base*    toBase()                       const;
        Base     base  ()                       const;

        T*       address(uint32_t _index_ = 0u) const;
        T        value  (uint32_t _index_     ) const;

    protected:

        uint32_t _size         ;
        Base*    _toBase       ;
        T*       _originAddress;
};