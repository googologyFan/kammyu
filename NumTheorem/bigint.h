#ifndef KAMMYU_NUMTHEOREM_BIGINT
#define KAMMYU_NUMTHEOREM_BIGINT

#include <string>
#include <vector>

namespace kammyu::NumTheorem
{

  namespace __bigint
  {

    using ll = long long;
    const int e9 = 1'000'000'000;

    struct BigInt
    {
    private:
      std::vector<ll> digits;
      bool neg;

    public:
      BigInt() : neg(false), digits(1, 0) {}
      BigInt(ll n) : neg(n < 0), digits()
      {
        if (neg)
          n = -n;
        while (n)
        {
          digits.push_back(n % e9);
          n /= e9;
        }
        if (digits.empty())
          digits.push_back(0);
      }
      BigInt(std::string n) : neg(n[0] == '-'), digits()
      {
        auto it = n.end() - 1;
        while (it >= n.begin() + neg)
        {
          auto start = std::max(n.begin() + neg, it - 8);
          digits.push_back(std::stoll(std::string(start, it + 1)));
          it = start - 1;
        }
        if (digits.empty())
          digits.push_back(0);
      }
      BigInt(int siz, bool neg) : neg(neg), digits(siz, 0) {}

      std::string get() const
      {
        std::string res = neg ? "-" : "";
        for (int i = digits.size() - 1; i >= 0; i--)
        {
          if (i != digits.size() - 1)
            res += std::string(9 - std::to_string(digits[i]).size(), '0');
          res += std::to_string(digits[i]);
        }
        return res;
      }

      BigInt abs() const
      {
        BigInt res(*this);
        res.neg = false;
        return res;
      }

      BigInt operator-() const
      {
        BigInt res(*this);
        res.neg = !neg;
        return res;
      }

      BigInt operator+(const BigInt& rhs) const
      {
        if (neg != rhs.neg)
          return *this - (-rhs);
        if (abs() < rhs.abs())
          return rhs + *this;

        BigInt res(*this);
        bool carry = false;
        size_t n = digits.size();
        for (size_t i = 0; i < n; ++i)
        {
          res.digits[i] += carry + (i < rhs.digits.size() ? rhs.digits[i] : 0);
          carry = res.digits[i] >= e9;
          if (carry)
            res.digits[i] -= e9;
        }
        if (carry)
          res.digits.push_back(1);
        return res;
      }
      BigInt operator-(const BigInt& rhs) const
      {
        if (neg != rhs.neg)
          return *this + (-rhs);
        if (abs() < rhs.abs())
          return -(rhs - *this);

        BigInt res(*this);
        bool carry = false;
        for (size_t i = 0; i < digits.size(); ++i)
        {
          res.digits[i] -= carry + (i < rhs.digits.size() ? rhs.digits[i] : 0);
          carry = res.digits[i] < 0;
          if (carry)
            res.digits[i] += e9;
        }
        while (res.digits.size() > 1 && res.digits.back() == 0)
          res.digits.pop_back();
        return res;
      }

      BigInt operator*(const BigInt& rhs) const
      {
        BigInt res(digits.size() + rhs.digits.size(), neg ^ rhs.neg);
        for (size_t i = 0; i < digits.size(); ++i)
          for (size_t j = 0; j < rhs.digits.size(); ++j)
          {
            res.digits[i + j] += digits[i] * rhs.digits[j];
            res.digits[i + j + 1] += res.digits[i + j] / e9;
            res.digits[i + j] %= e9;
          }
        while (res.digits.size() > 1 && res.digits.back() == 0)
          res.digits.pop_back();
        return res;
      }

      BigInt pow(ll n) const
      {
        BigInt res(1);
        BigInt base(*this);
        while (n)
        {
          if (n & 1)
            res = res * base;
          base = base * base;
          n >>= 1;
        }
        return res;
      }

      bool operator<(const BigInt& rhs) const
      {
        if (neg != rhs.neg)
          return neg;

        if (digits.size() != rhs.digits.size())
          return neg ^ (digits.size() < rhs.digits.size());

        for (size_t i = digits.size(); i-- > 0;)
          if (digits[i] != rhs.digits[i])
            return neg ^ (digits[i] < rhs.digits[i]);
        return false;
      }

      BigInt& operator+=(const BigInt& rhs) { return *this = *this + rhs; }
      BigInt& operator-=(const BigInt& rhs) { return *this = *this - rhs; }
      BigInt& operator*=(const BigInt& rhs) { return *this = *this * rhs; }
    };

  } // namespace __bigint

  using __bigint::BigInt;

} // namespace kammyu::NumTheorem

#endif // KAMMYU_NUMTHEOREM_BigInt
