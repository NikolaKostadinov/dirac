#pragma once

#include "base.hpp"
#include "basis2.hpp"
#include "complex.hpp"
#include "exceptions.h"

template <class T>
class Field2
{
    public:

        Field2();
        virtual ~Field2();

        Field2(Basis2  _basis_  );
        Field2(Basis2* _toBasis_);

        void setValues(T* _address_);

        unsigned int  size();
        unsigned int xSize();
        unsigned int ySize();
        Basis2* toBasis();
        Basis2  basis  ();
        T* address(unsigned int _index_ = 0U, unsigned int _jndex_ = 0U);
        T  value  (unsigned int _index_     , unsigned int _jndex_     );

    protected:

        unsigned int _xSize;
        unsigned int _ySize;
        Basis2* _toBasis;
        T* _originAddress;
};