#include "../include/wavefunc1.hpp"

WaveFunc1::WaveFunc1()
{
    _size = 0U;
    _toBase = new Base;
    _originAddress = new Complex;
}

WaveFunc1::~WaveFunc1()
{
    delete _toBase;
    delete[] _originAddress;
}

WaveFunc1::WaveFunc1(Base _base_)
{
    _size = _base_.size();
    _toBase = &_base_;
}

WaveFunc1::WaveFunc1(Base* _toBase_)
{
    _size = _toBase_->size();
    _toBase = _toBase_;
}

void WaveFunc1::normalize(float _norm_)
{
    float prob = totalProb();
    float factor = sqrt(_norm_ / prob);

    for (unsigned int i = 0U; i < _size; i++)
        (*address(i)).scale(factor);
}

Complex WaveFunc1::probAmp(unsigned int _index_)
{
    return value(_index_);
}

float WaveFunc1::prob(unsigned int _index_)
{
    return value(_index_).conjSq();
}

float WaveFunc1::totalProb()
{
    float prob = 0;
    for (unsigned int i = 0U; i < _size; i++)
        prob += value(i).conjSq();
    
    return prob;
}

std::string WaveFunc1::string()
{
    std::string result = "[ ";
    if (_size <= MAX_STR)
    {
        for (unsigned int i = 0U; i < _size - 1; i++)
        {
            result += value(i).string();
            result += ", ";
        }
        result += value(_size - 1).string();
    }
    else
    {
        for (unsigned int i = 0U; i < MAX_STR - 2; i++)
        {
            result += value(i).string();
            result += ", ";
        }
        result += value(MAX_STR - 2).string();
        result += ", ... ";
        result += value(_size - 1).string();
    }
    
    result += " ]";
    return result;
}