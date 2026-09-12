#ifndef KAMMYU_PRECALC_COMBINATION
#define KAMMYU_PRECALC_COMBINATION

#include "kammyu/precalc/factorial.h"

namespace kammyu
{
  namespace precalc
  {
    struct nCr_fact
    {
    private:
      fact f;
      int mod;

    public:
      nCr_fact(int _mod) : f(_mod), mod(_mod) {}
      int nCr(int n, int r)
      {
        if (n < r || n < 0 || r < 0)
          return 0;
        return (f[n] * f[-r] % mod * f[-(n - r)] % mod);
      }
    };

    constexpr int COMBINATION_TABLE_MAX = 10000;
    struct nCr_plus
    {
    private:
      int mod;
      int table[COMBINATION_TABLE_MAX + 1][COMBINATION_TABLE_MAX + 1];

    public:
      nCr_plus(int _mod) : mod(_mod) { build(); }
      void build()
      {
        for (int i = 0; i <= COMBINATION_TABLE_MAX; i++)
          for (int j = 0; j <= COMBINATION_TABLE_MAX; j++)
            table[i][j] = 0;
        for (int i = 0; i <= COMBINATION_TABLE_MAX; i++)
        {
          table[i][0] = 1;
          for (int j = 1; j <= i; j++)
          {
            table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
          }
        }
      }
      int nCr(int n, int r)
      {
        if (n < 0 || r < 0)
          return 0;
        return table[n][r];
      }
    };
  };
};

#endif // KAMMYU_PRECALC_COMBINATION