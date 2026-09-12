#ifndef KAMMYU_PRECALC_FACTORIAL
#define KAMMYU_PRECALC_FACTORIAL

#include <cassert>

namespace kammyu
{
  namespace precalc
  {
    constexpr int FACT_MAX = 1000000;
    struct fact
    {
    private:
      int mod;
      long long fact_container[FACT_MAX + 1];
      long long inv_container[FACT_MAX + 1];

      int modinv(long long x)
      {
        long long res = 1, pow = mod - 2;
        while (pow)
        {
          if (pow & 1)
            res = (res * x) % mod;
          x = (x * x) % mod;
          pow >>= 1;
        }
        return res;
      }

    public:
      fact(int _mod) : mod(_mod) { build(); }
      void build()
      {
        fact_container[0] = 1;
        for (int i = 1; i <= FACT_MAX; i++)
          fact_container[i] = (fact_container[i - 1] * i) % mod;

        inv_container[FACT_MAX] = modinv(fact_container[FACT_MAX]);
        for (int i = FACT_MAX - 1; i >= 0; i--)
          inv_container[i] = (inv_container[i + 1] * (i + 1)) % mod;
      }
      long long operator[](int i) const
      {
        assert(-FACT_MAX <= i && i <= FACT_MAX);
        return (i < 0 ? inv_container[-i] : fact_container[i]);
      }
    };
  }; // namespace precalc
}; // namespace kammyu

#endif // KAMMYU_PRECALC_FACTORIAL
