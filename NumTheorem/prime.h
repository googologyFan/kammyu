#ifndef KAMMYU_NUMTHEOREM_PF
#define KAMMYU_NUMTHEOREM_PF

#include <assert.h>
#include <map>
#include <vector>

namespace kammyu::NumTheorem
{

  namespace __prime
  {
    bool is_prime(unsigned long long val);

    using ll = long long;

    struct PF
    {
    private:
      std::map<ll, int> factors;

    public:
      PF() = default;
      PF(ll n)
      {
        for (ll p = 2; p * p <= n; ++p)
        {
          while (n % p == 0)
          {
            factors[p]++;
            n /= p;
          }
        }
        if (n > 1)
          factors[n]++;
      }
      PF(ll p, int e)
      {
        factors[p] = e;
      }

      ll get() const
      {
        ll res = 1;
        for (const auto& [p, e] : factors)
          for (int i = 0; i < e; ++i)
            res *= p;
        return res;
      }
      const std::map<ll, int>& get_raw() const { return factors; }

      PF& operator*=(const PF& rhs)
      {
        for (const auto& [p, e] : rhs.factors)
          factors[p] += e;
        return *this;
      }
      PF operator*(const PF& rhs) const
      {
        PF res(*this);
        for (const auto& [p, e] : rhs.factors)
          res.factors[p] += e;
        return res;
      }
      PF& div_prime(ll p, bool assertion = true)
      {
        if (assertion)
          assert(is_prime(p));
        factors[p]++;
        return *this;
      }
      PF& prod_prime(ll p, bool assertion = true)
      {
        if (assertion)
          assert(is_prime(p));
        factors[p]++;
        return *this;
      }

      PF& operator/=(const PF& rhs)
      {
        for (const auto& [p, e] : rhs.factors)
          factors[p] -= e;
        return *this;
      }
      PF operator/(const PF& rhs) const
      {
        PF res(*this);
        for (const auto& [p, e] : rhs.factors)
          res.factors[p] -= e;
        return res;
      }

      PF& gcd(const PF& rhs)
      {
        for (const auto& [p, e] : rhs.factors)
          factors[p] = std::min(factors[p], e);
        return *this;
      }
      PF& lcm(const PF& rhs)
      {
        for (const auto& [p, e] : rhs.factors)
          factors[p] = std::max(factors[p], e);
        return *this;
      }

      int count_divisors() const
      {
        int res = 1;
        for (const auto& [p, e] : factors)
          res *= (e + 1);
        return res;
      }

      std::vector<ll> get_divisors() const
      {
        std::vector<ll> res = {1};
        for (const auto& [p, e] : factors)
        {
          int siz = res.size();
          ll cur = 1;
          for (int i = 0; i < e; ++i)
          {
            cur *= p;
            for (int j = 0; j < siz; ++j)
              res.push_back(res[j] * cur);
          }
        }
        return res;
      }
    };

    PF gcd(const PF& a, const PF& b)
    {
      PF res(a);
      return res.gcd(b);
    }
    PF lcm(const PF& a, const PF& b)
    {
      PF res(a);
      return res.lcm(b);
    }

    using ull = unsigned long long;
    __uint128_t pow_mod128(__uint128_t b, ull e, ull m)
    {
      if (m == 0)
        return 0;
      __uint128_t res = 1;
      b %= m;
      while (e)
      {
        if (e & 1)
          res = res * b % m;
        b = b * b % m;
        e >>= 1;
      }
      return res;
    }
    // Miller-Rabin
    bool miller_rabin(ull a, ull N)
    {
      if (a >= N)
        return true;

      ull d = N >> 1;
      ull m1 = d << 1;
      while ((d & 1) == 0)
      {
        if (pow_mod128(a, d, N) == m1)
          return true;
        d >>= 1;
      }

      ull _ = pow_mod128(a, d, N);
      return _ == 1 || _ == m1;
    }
    bool is_prime(ull val)
    {
      if (val <= 2)
        return val == 2;
      if ((val & 1) == 0)
        return false;

      if (val < 4759123141ull)
        return miller_rabin(2, val) &&
               miller_rabin(7, val) &&
               miller_rabin(61, val);

      return miller_rabin(2, val) &&
             miller_rabin(325, val) &&
             miller_rabin(9375, val) &&
             miller_rabin(28178, val) &&
             miller_rabin(450775, val) &&
             miller_rabin(9780504, val) &&
             miller_rabin(1795265022, val);
    }

  } // namespace __prime

  using __prime::PF;

  using __prime::gcd;

  using __prime::lcm;

  using __prime::is_prime;

} // namespace kammyu::NumTheorem

#endif // KAMMYU_NUMTHEOREM_PF
