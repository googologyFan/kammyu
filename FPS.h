#ifndef FPS_HPP
#define FPS_HPP

#define FPS_VERSION 2

#include "kammyu/internal.h"
#include <assert.h>
#include <vector>

namespace kammyu
{

  namespace __kammyu_fps
  {

    const int MOD = 998244353;
    struct mint
    {
    private:
      long long value;

    public:
      mint() : value(0) {}
      mint(long long _value) : value((_value % MOD + MOD) % MOD) {}
      mint operator+(const mint& other) const { return mint(value + other.value); }
      mint& operator+=(const mint& other) { return *this = *this + other; }
      mint operator-(const mint& other) const { return *this + (-other); }
      mint operator-() const { return mint(MOD - value); }
      mint& operator-=(const mint& other) { return *this = *this - other; }
      mint operator*(const mint& other) const { return mint(value * other.value); }
      mint& operator*=(const mint& other) { return *this = *this * other; }
      mint operator/(const mint& other) const { return *this * other.inv(); }
      mint pow(long long p) const
      {
        mint res(1), cur(value);
        while (p)
        {
          if (p & 1)
            res *= cur;
          cur *= cur;
          p >>= 1;
        }
        return res;
      }
      mint inv() const { return pow(MOD - 2); }

      long long val() const { return value; }
    };
    std::vector<mint> omega, iomega;
    std::vector<mint> modinv = {0, 1};

    struct FPS
    {
    private:
      int Size;

      std::vector<mint> container;

      void calc_modinv(int n) const
      {
        if (modinv.size() > n)
          return;
        int old_size = modinv.size();
        modinv.resize(n + 1);
        for (int i = old_size; i <= n; i++)
          modinv[i] = -mint(MOD / i) * modinv[MOD % i];
      }

#if FPS_VERSION == 1
      void FFT(const std::vector<mint>::iterator& left,
               const std::vector<mint>::iterator& right, int size,
               const std::vector<mint>& omega) const
      { // [left, right)
        if (size == 0)
          return;

        int half = 1 << (size - 1);
        const std::vector<mint>::iterator mid = left + half;

        FFT(left, mid, size - 1, omega);
        FFT(mid, right, size - 1, omega);

        mint k = 1;
        for (int i = 0; i < half; i++)
        {
          mint B = k * *(mid + i);
          *(mid + i) = *(left + i) - B;
          *(left + i) += B;
          k *= omega[size];
        }
      }

#elif FPS_VERSION == 2
      void FFT(std::vector<mint>& A, int size,
               const std::vector<mint>& omega) const
      {
        int n = 1 << size;

        for (int i = 1; i <= size; i++)
        {
          int half = 1 << (i - 1);
          mint z = 1;
          for (int k = 0; k < half; k++)
          {
            for (int j = 0; j < n; j += 1 << i)
            {
              mint b = z * A[j + half + k];
              A[j + half + k] = A[j + k] - b;
              A[j + k] += b;
            }
            z *= omega[i];
          }
        }
      }

#endif

      // need A.size() = 2^n
      void FFT(FPS& A) const
      {
        int size = 0;
        while ((1 << size) < A.size())
          size++;
        assert((1 << size) == A.size());

        std::vector<mint>& res = A.container;
        for (int i = 0; i < 1 << size; i++)
        {
          int j = internal::bit_reverse32(i) >> (32 - size);
          if (i < j)
            std::swap(res[i], res[j]);
        }
#if FPS_VERSION == 1
        FFT(res.begin(), res.end(), size, omega);
#elif FPS_VERSION == 2
        FFT(res, size, omega);
#endif
      }
      void IFFT(FPS& A) const
      {
        int size = 0;
        while ((1 << size) < A.size())
          size++;
        assert((1 << size) == A.size());

        std::vector<mint>& res = A.container;
        for (int i = 0; i < 1 << size; i++)
        {
          int j = internal::bit_reverse32(i) >> (32 - size);
          if (i < j)
            std::swap(res[i], res[j]);
        }
#if FPS_VERSION == 1
        FFT(res.begin(), res.end(), size, iomega);
#elif FPS_VERSION == 2
        FFT(res, size, iomega);
#endif
        A *= mint(1 << size).inv();
      }

    public:
      FPS() : FPS(0) {}
      FPS(int _size) : FPS(std::vector<mint>(_size, 0)) {}
      FPS(const std::vector<int>& v)
          : Size((int)v.size()), container((int)v.size())
      {
        for (int i = 0; i < size(); i++)
          container[i] = mint(v[i]);
      }
      FPS(const std::vector<long long>& v)
          : Size((int)v.size()), container((int)v.size())
      {
        for (int i = 0; i < size(); i++)
          container[i] = mint(v[i]);
      }
      FPS(const std::vector<mint>& v) : Size((int)v.size()), container(v) {}

      FPS operator*(const int& other) const
      {
        FPS res(*this);
        for (int i = 0; i < size(); i++)
          res[i] *= other;
        return res;
      }
      FPS operator*(const mint& other) const { return *this * (int)other.val(); }

      FPS operator+(const FPS& other) const
      {
        if (size() < other.size())
          return other + *this;

        FPS res(size());
        for (int i = 0; i < size(); i++)
          res[i] = container[i] + (i < other.size() ? other.container[i] : 0);
        return res;
      }
      FPS operator-(const FPS& other) const { return *this + (-other); }
      FPS operator*(const FPS& other) const
      {
        FPS A = *this;
        FPS B = other;

        int n = A.size() + B.size() - 1;
        int size = 1;
        while (size < n)
          size <<= 1;
        A.resize(size);
        B.resize(size);

        FFT(A);
        FFT(B);
        for (int i = 0; i < size; i++)
          A[i] *= B[i];
        IFFT(A);

        return A.slice(n);
      }
      FPS operator-() const { return FPS(*this) * -1; }

      FPS& operator+=(const FPS& other) { return *this = *this + other; }
      FPS& operator-=(const FPS& other) { return *this = *this - other; }
      FPS& operator*=(const FPS& other) { return *this = *this * other; }
      FPS& operator*=(const mint& other) { return *this = *this * other; }
      FPS& operator*=(const int& other) { return *this = *this * other; }

      int size() const { return Size; }
      void resize(int sz)
      {
        Size = sz;
        container.resize(sz, 0);
      }
      FPS slice(int l, int r) const
      {
        FPS res(r - l);
        for (int i = l; i < r && i < size(); i++)
          res[i - l] = container[i];
        return res;
      }
      FPS slice(int sz) const { return slice(0, sz); }
      mint get(int i) const { return container[i]; }
      mint operator[](int i) const { return container[i]; }
      mint& operator[](int i) { return container[i]; }

      static FPS constant(const mint& n) { return FPS(std::vector<mint>(1, n)); }
      static FPS constant(int n) { return constant(mint(n)); }

      // f * (x^n + a) (mod x^m)
      FPS prodmod1(int n, mint a, int m = -1) const
      {
        if (m == -1)
          m = size();
        FPS res = slice(m);
        for (int i = size() - 1; i >= 0; i--)
        {
          res[i] *= a;
          if (i + n < m)
            res[i + n] += res[i];
        }
        return res;
      }
      // x^n + aで割った余り
      FPS divmod1(int n, mint a) const
      {
        FPS res = *this;
        for (int i = size() - 1; i >= n; i--)
          res[i - n] -= res[i] * a;
        return res.slice(n);
      }
      // f / (x^n + a) (mod x^m)
      FPS divmod2(int n, mint a, int m = -1) const
      {
        if (m == -1)
          m = size();
        mint b = a.inv();
        FPS res = slice(m);
        for (int i = 0; i < size(); i++)
        {
          res[i] *= b;
          if (i + n < m)
            res[i + n] -= res[i];
        }
        return res;
      }

      FPS inv(int n = -1) const
      {
        if (n == -1)
          n = size();
        int N = 1;
        mint inv0 = container[0].inv();
        FPS res(constant(inv0));
        while (N < n)
        {
          N <<= 1;
          res = (res * (constant(2) - res * slice(N))).slice(N);
        }

        res.resize(n);
        return res;
      }

      FPS integ() const
      {
        FPS res(size() + 1);
        res[0] = 0;
        calc_modinv(size());
        for (int i = 0; i < size(); i++)
          res[i + 1] = container[i] * modinv[i + 1];
        return res;
      }
      FPS deriv() const
      {
        if (size() == 0)
          return FPS(0);
        FPS res(size() - 1);
        for (int i = 1; i < size(); i++)
          res[i - 1] = container[i] * i;
        return res;
      }

      FPS log(int n = -1) const
      {
        assert(container[0].val() == 1);
        if (n == -1)
          n = size();
        return (deriv() * inv(n)).integ().slice(n);
      }

      FPS exp(int n = -1) const
      {
        if (n == -1)
          n = size();
        int m = 1;
        FPS f(constant(1)), g(constant(1));
        FPS d = deriv();
        calc_modinv(n);
        while (m < n)
        {
          g = (g * (constant(2) - f * g)).slice(m);
          const FPS& q = d.slice(m - 1);
          const FPS& r = (f * q).divmod1(m, -1);
          FPS S = f.deriv() - r;
          S.resize(S.size() + 1);
          for (int i = S.size() - 1; i > 0; i--)
            S[i] = S[i - 1];
          S[0] = 0;
          const FPS& s = S.divmod1(m, -1);
          const FPS& t = (g * s).slice(m);
          FPS u = this->slice(m, 2 * m);
          for (int i = 0; i < t.size(); i++)
            u[i] -= t[i] * modinv[i + m];
          const FPS& v = (f * u).slice(m);
          f.resize(2 * m);
          for (int i = 0; i < m; i++)
            f[i + m] = v[i];
          m <<= 1;
        }

        f.resize(n);
        return f;
      }

      FPS pow(int m, int n = -1) const
      {
        if (n == -1)
          n = size();
        if (m == 0)
          return constant(1).slice(n);
        if (m == 1)
          return slice(n);

        int l = 0;
        while (l < size() && container[l].val() == 0)
          l++;
        if (l == size() || (long long)l * m >= n)
          return FPS(n);
        mint c = container[l];
        int r = n - l * (m - 1);
        FPS A = slice(l, r);
        A *= c.inv();
        A = (A.log() * m).exp();
        FPS res(n);
        for (int i = 0; i < A.size(); i++)
          res[i + l * m] = A[i] * c.pow(m);

        return res;
      }
    };
    template <typename T = mint>
    std::vector<T> get_container(const FPS& f)
    {
      std::vector<T> res(f.size());
      for (int i = 0; i < f.size(); i++)
        res[i] = f[i].val();
      return res;
    }

    struct Precalc
    {
      Precalc()
      {
        int root_size = 0;
        while (((MOD - 1) & (1 << root_size)) == 0)
          root_size++;
        omega = std::vector<mint>(root_size + 1);
        iomega = std::vector<mint>(root_size + 1);
        mint cur = mint(3).pow(119), inv_cur = cur.inv();
        for (int k = root_size; k >= 0; k--)
        {
          omega[k] = cur;
          iomega[k] = inv_cur;
          cur *= cur;
          inv_cur *= inv_cur;
        }
      }
    };
    inline Precalc precalc;

    namespace functions
    {
      FPS multiply(const FPS& A, const FPS& B)
      {
        return A * B;
      }
    } // namespace functions
  } // namespace __kammyu_fps

  using __kammyu_fps::FPS;
  using __kammyu_fps::get_container;

} // namespace kammyu

#endif // FPS_HPP
