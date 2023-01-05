#pragma once

#include "engine_params.h"
#include "engine_exceptions.h"
#include "base.hpp"
#include "complex.hpp"
#include "vector2.hpp"
#include "vector3.hpp"

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
        void     setBase  (Base     _base_);
        void     setBase  (Base*  _toBase_);

        uint32_t size  ()                                                    const;
        Base*    toBase()                                                    const;
        Base     base  ()                                                    const;

        T*       address(uint32_t _index_ = 0u)                              const;
        T        value  (uint32_t _index_, bool _isNull_ = DEFAULT_IS_NULL)  const;

    protected:

        Base*    _toBase       ;
        T*       _originAddress;
};