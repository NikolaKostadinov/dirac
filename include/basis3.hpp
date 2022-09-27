#pragma once

#include "base.hpp"
#include "basis2.hpp"
#include "exceptions.h"

class Basis3 : Basis2
{
    public:

        Basis3();
        virtual ~Basis3();

    private:

        Base* _toZ;
};