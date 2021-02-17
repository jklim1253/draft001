#ifndef __COMMON_HPP__
#define __COMMON_HPP__

#include "error_code.hpp"

namespace jklim
{

// Init, Release is functor
template<class Init, class Release>
struct AtLast
{
  AtLast(Init const& i, Release const& r)
    : _init(i)
    , _release(r)
  {
    _init();
  }
  ~AtLast()
  {
    _release();
  }
private:
  Init _init;
  Release _release;
};

} // namespace

#endif // __COMMON_HPP__