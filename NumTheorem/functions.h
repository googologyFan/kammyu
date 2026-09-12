#ifndef KAMMYU_NUMTHEOREM_FUNCTIONS
#define KAMMYU_NUMTHEOREM_FUNCTIONS

#include "kammyu/NumTheorem/prime.h"
#include <unordered_map>
#include <vector>

namespace kammyu::NumTheorem
{

  namespace __functions
  {

    using ll = long long;

    ll lpow(ll b, ll e)
    {
      ll res = 1;
      while (e)
      {
        if (e & 1)
          res *= b;
        b *= b;
        e >>= 1;
      }
      return res;
    }
    ll pow_mod(ll b, ll e, ll m)
    {
      ll res = 1;
      while (e)
      {
        if (e & 1)
          res = res * b % m;
        b = b * b % m;
        e >>= 1;
      }
      return res;
    }

    std::unordered_map<ll, ll> totient_memo;
    ll phi_euler(ll n)
    {
      if (totient_memo.contains(n))
        return totient_memo[n];

      PF pf(n);
      ll res = n;
      for (auto [p, _] : pf.get_raw())
        res = res / p * (p - 1);
      totient_memo[n] = res;
      return totient_memo[n] = res;
    }

    std::unordered_map<ll, PF> carmichael_memo;
    PF inner_carmichael(ll p, int e)
    {
      ll pe = lpow(p, e);
      if (carmichael_memo.contains(pe))
        return PF(carmichael_memo[pe]);

      if (p == 2)
      {
        if (e <= 2)
          return PF(2, e);
        return PF(2, e - 2);
      }
      return carmichael_memo[pe] = PF(p - 1) * PF(p, e - 1);
    }

    PF lambda_carmichael(ll n)
    {
      if (carmichael_memo.contains(n))
        return carmichael_memo[n];

      PF res(1);
      for (auto [p, e] : PF(n).get_raw())
        res.lcm(inner_carmichael(p, e));
      return carmichael_memo[n] = res;
    }

  } // namespace __functions

  using __functions::lpow;

  using __functions::pow_mod;

  using __functions::phi_euler;

  using __functions::lambda_carmichael;

} // namespace kammyu::NumTheorem

#endif // KAMMYU_NUMTHEOREM_FUNCTIONS
