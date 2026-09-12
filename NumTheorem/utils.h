#ifndef KAMMYU_NUMTHEOREM_UTILS
#define KAMMYU_NUMTHEOREM_UTILS

namespace kammyu::NumTheorem
{

  namespace __utils
  {

    using ll = long long;
    ll gcd(ll a, ll b)
    {
      while (b != 0)
      {
        ll t = b;
        b = a % b;
        a = t;
      }
      return a;
    }
    ll lcm(ll a, ll b)
    {
      return a / gcd(a, b) * b;
    }
    bool is_palindrome(ll n, ll base = 10)
    {
      char buf[64], *p = buf, *q = buf;
      while (n > 0)
      {
        *p++ = n % base;
        n /= base;
      }
      p--;
      while (q < p)
      {
        if (*q != *p)
          return false;
        p--, q++;
      }
      return true;
    }

    void sieve_of_Erat(int* p)
    {
      const int e7 = 10'000'000;
      bool prime[e7 + 1];
      for (int i = 0; i < e7 + 1; i++)
        prime[i] = true;

      for (int i = 0; i < e7 + 1; i++)
      {
        if (i <= 1)
          prime[i] = false;
        else if (prime[i])
        {
          *p++ = i;
          for (int j = 2 * i; j <= e7; j += i)
            prime[j] = false;
        }
      }
    }

  } // namespace __utils

  using __utils::gcd;

  using __utils::lcm;

  using __utils::is_palindrome;

  using __utils::sieve_of_Erat;

} // namespace kammyu::NumTheorem

#endif // KAMMYU_NUMTHEOREM_UTILS
