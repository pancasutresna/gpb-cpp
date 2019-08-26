//
// Created by panca on 26/08/2019.
//

#ifndef BLOCKCHAIN_SRC_ATTRIBUTES_H_
#define BLOCKCHAIN_SRC_ATTRIBUTES_H_

#if defined(__has_cpp_attribute)
#  if __has_cpp_attribute(nodiscard)
#    define NODISCARD [[nodiscard]]
#  endif
#endif
#ifndef NODISCARD
#  if defined(_MSC_VER) && _MSC_VER >= 1700
#    define NODISCARD _Check_return_
#  else
#    define NODISCARD __attribute__((warn_unused_result))
#  endif
#endif

#endif //BLOCKCHAIN_SRC_ATTRIBUTES_H_
