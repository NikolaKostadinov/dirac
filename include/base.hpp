#pragma once

#include "exceptions.h"

class Base
{
    public:

        Base();
        virtual ~Base();

        Base(
            float _start_,
            float _end_,
            unsigned int _size_
        );

        unsigned int size();
        float start();
        float end();
        float dx();
        float length();

    private:

        unsigned int _size;
        float _start;
        float _end;
};