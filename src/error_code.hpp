#ifndef __ERROR_CODE_HPP__
#define __ERROR_CODE_HPP__

namespace jklim
{

// error code
enum ec : int
{
  // basic error codes
  no_error = 0,
  not_implemented_yet,
  invalid_arguments,

  // codes associated with file
  file_not_found,
  file_not_opened,
  file_format_is_not_supported,
};

} // namespace jklim

#endif // __ERROR_CODE_HPP__