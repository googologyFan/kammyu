#ifndef KAMMYU_CONSTANTS
#define KAMMYU_CONSTANTS

#include <limits>

namespace kammyu
{
  namespace infinities
  {
    constexpr int inf = std::numeric_limits<int>::max();
    constexpr int _inf = std::numeric_limits<int>::min();
    constexpr long long INF = std::numeric_limits<long long>::max();
    constexpr long long _INF = std::numeric_limits<long long>::min();
  }; // namespace infinities
  namespace modulos
  {
    constexpr int Smod = 998244353;
    constexpr int Bmod = 1000000007;
  }; // namespace modulos
}; // namespace kammyu

#endif // KAMMYU_CONSTANTS
