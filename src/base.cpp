#include "../include/base.hpp"

Base::Base()
{
    _size  = 0u;
    _start = 0u;
    _end   = 0u;
}

Base::~Base()
{

}

Base::Base(float _start_, uint32_t _size_, float _end_)
{
    if (isForbidden(_size_)) throw FORBIDDEN_SIZE;
    if (_size_  == 0u  )     throw INF_DX        ;
    if (_start_ < _end_)
    {
        _size  = _size_ ;
        _start = _start_;
        _end   = _end_  ;
    }
    else if (_start_ > _end_)
    {
        _size  = _size_ ;
        _start = _end_  ;
        _end   = _start_;
    }
    else throw INF_DX;
}

Base::Base(float _start_, float _end_, uint32_t _size_) : Base(_start_,_size_,_end_)
{

}

float Base::operator()(uint32_t _index_) const
{
    return coord(_index_);
}

uint32_t Base::size() const
{
    return _size;
}

float Base::start() const
{
    return _start;
}

float Base::end() const
{
    return _end;
}

float Base::length() const
{
    return _end - _start;
}

float Base::delta() const
{
    return (_end - _start) / (float) (_size - 1u);
}

float Base::delta2() const
{
    float  dx = delta();
    return dx * dx;
}

float Base::coord(uint32_t _index_) const
{
    if   (isIn(_index_, true)) return _start + _index_ * delta();
    else                       throw  OUT_OF_BOUNDS             ;
}

bool Base::isIn(uint32_t _index_, bool _includes_bounds_) const
{
    if   (_includes_bounds_) return _index_ < _size                   ;
    else                     return _index_ < _size-1u && _index_ > 0u;
}

bool Base::isOut(uint32_t _index_, bool _includes_bounds_) const
{
    return !isIn(_index_, _includes_bounds_);
}

bool Base::isForbidden(uint32_t _index_) const
{
    return _index_ >= FORBIDDEN_INDEX;
}

bool Base::isStartCloser(uint32_t _index_) const
{
    uint32_t distToEnd = _size - _index_;

    if (isIn(_index_, true)) return _index_ > distToEnd;
    else                     return _index_ < distToEnd;
}

bool Base::isEndCloser(uint32_t _index_) const
{
    return !isStartCloser(_index_);
}