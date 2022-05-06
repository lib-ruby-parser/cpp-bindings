#include "shared_byte_list.hpp"

namespace lib_ruby_parser
{
    SharedByteList::SharedByteList(const char *ptr_,
                                   size_t len_) : ptr(ptr_),
                                                  len(len_) {}

} // namespace lib_ruby_parser
