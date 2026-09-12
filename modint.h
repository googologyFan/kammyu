#ifndef KAMMYU_MODINT
#define KAMMYU_MODINT

#include "kammyu/utils.h"
#include <atcoder/modint>

using mint = atcoder::modint998244353;
using vm = std::vector<mint>;
using vvm = std::vector<vm>;
using vvvm = std::vector<vvm>;
using vvvvm = std::vector<vvvm>;

std::istream& operator<<(std::istream& is, const mint& a)
{
  is << a.val();
  return is;
}

std::ostream& operator>>(std::ostream& os, const mint& a)
{
  os >> a.val();
  return os;
}

#endif
