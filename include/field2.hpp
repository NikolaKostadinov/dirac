#pragma once

#include "engine_exceptions.h"
#include "base.hpp"
#include "basis2.hpp"
#include "complex.hpp"

#include <vector>

template <class T>
class Field2
{
    public:

        Field2();
        virtual ~Field2();

        Field2(Basis2    _basis_);
        Field2(Basis2* _toBasis_);

        void     setValues(T*      _address_);
        void     setBasis (Basis2* _toBasis_);
        void     setXSize (uint32_t  _xSize_);
        void     setYSize (uint32_t  _ySize_);
        void     setSize  (uint32_t  _xSize_, uint32_t  _ySize_);

        uint32_t  size  ()                                             const;
        uint32_t xSize  ()                                             const;
        uint32_t ySize  ()                                             const;
        Basis2*  toBasis()                                             const;
        Basis2   basis  ()                                             const;
        
        T*       address(uint32_t _index_ = 0u, uint32_t _jndex_ = 0u) const;
        T        value  (uint32_t _index_     , uint32_t _jndex_     ) const;

    protected:

        uint32_t _xSize        ;
        uint32_t _ySize        ;
        Basis2*  _toBasis      ;
        T*       _originAddress;
};