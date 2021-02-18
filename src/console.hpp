#ifndef __CONSOLE_HPP__
#define __CONSOLE_HPP__

#include <string>
#include "common.hpp"

namespace jklim
{

class console
 : public singleton<console>
{
  friend class singleton<console>;
public:
  int push(std::string const&);
  friend console& operator << (console&, std::string const&);

private:
  console();
  ~console();

private:
  class implement;
  implement* impl;
};

extern console& con;

} // namespace jklim

#endif // __CONSOLE_HPP__