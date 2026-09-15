#ifndef KAMMYU_MODINT
#define KAMMYU_MODINT

#include "kammyu/input.h"
#include "kammyu/output.h"

#include <atcoder/modint>

using mint = atcoder::modint998244353;
using vm = std::vector<mint>;
using vvm = std::vector<vm>;
using vvvm = std::vector<vvm>;
using vvvvm = std::vector<vvvm>;

namespace kammyu
{
  namespace input
  {
    template <int m>
    std::istream& operator>>(std::istream& is, atcoder::static_modint<m>& a)
    {
      long long x;
      is >> x;
      a = x;
      return is;
    }
    template <int m>
    std::istream& operator>>(std::istream& is, std::vector<atcoder::static_modint<m>>& v)
    {
      for (auto& x : v)
        is >> x;
      return is;
    }
    template <int m>
    std::istream& operator>>(std::istream& is, std::vector<std::vector<atcoder::static_modint<m>>>& v)
    {
      for (auto& x : v)
        is >> x;
      return is;
    }
  } // namespace input
  namespace output
  {
    template <int m>
    std::ostream& operator<<(std::ostream& os, const atcoder::static_modint<m>& a)
    {
      os << a.val();
      return os;
    }
    template <int m>
    std::ostream& operator<<(std::ostream& os, const std::vector<atcoder::static_modint<m>>& v)
    {
      for (const auto& x : v)
        os << x << ' ';
      return os;
    }
    template <int m>
    std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<atcoder::static_modint<m>>>& v)
    {
      for (const auto& x : v)
        os << x << '\n';
      return os;
    }
  } // namespace output
} // namespace kammyu

#endif
