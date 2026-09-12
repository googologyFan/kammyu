#ifndef KAMMYU_UTILS
#define KAMMYU_UTILS

#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, s, e) for (int i = (s); i < (e); ++i)
#define reep(i, n) for (int i = 0; i <= (n); ++i)
#define reepp(i, s, e) for (int i = (s); i <= (e); ++i)
#define rrep(i, n) for (int i = (n - 1); i >= 0; --i)
#define rrepp(i, s, e) for (int i = (e - 1); i >= s; --i)
#define sign(f) (f == 0 ? 0 : ((f) > 0) * 2 - 1)

#define pqueue priority_queue

namespace kammyu
{

  namespace utils
  {
    template <typename T1, typename T2>
    bool chmax(T1& m, const T2& val)
    {
      if (m < val)
      {
        m = val;
        return true;
      }
      return false;
    }
    template <typename T1, typename T2>
    bool chmin(T1& m, const T2& val)
    {
      if (m > val)
      {
        m = val;
        return true;
      }
      return false;
    }

    using ll = long long;
    using pii = std::pair<int, int>;
    using piii = std::pair<int, pii>;
    using si = std::set<int>;
    using vi = std::vector<int>;
    using vpii = std::vector<pii>;
    using vpiii = std::vector<piii>;
    using vvi = std::vector<std::vector<int>>;
    using vvpii = std::vector<std::vector<pii>>;
    using vvvi = std::vector<vvi>;
    using vvvvi = std::vector<vvvi>;

    using vb = std::vector<bool>;
    using vvb = std::vector<vb>;
    using pli = std::pair<ll, int>;
    using plii = std::pair<pli, int>;
    using vpli = std::vector<pli>;
    using vvpli = std::vector<std::vector<pli>>;

    using pll = std::pair<ll, ll>;
    using plll = std::pair<pll, ll>;
    using vl = std::vector<ll>;
    using vpll = std::vector<pll>;
    using vvl = std::vector<std::vector<ll>>;
    using vvpll = std::vector<std::vector<pll>>;
    using vvvl = std::vector<vvl>;
    using vvvvl = std::vector<vvvl>;

    using vsi = std::vector<std::set<int>>;

    using vs = std::vector<std::string>;
    template <typename T>
    using vv = std::vector<std::vector<T>>;

    template <typename T>
    using min_pqueue = std::priority_queue<T, std::vector<T>, std::greater<T>>;
    template <typename T>
    using max_pqueue = std::priority_queue<T>;

    template <typename T1, typename T2>
    std::pair<T1, T2> operator+(const std::pair<T1, T2>& a, const std::pair<T1, T2>& b)
    {
      return std::make_pair(a.first + b.first, a.second + b.second);
    }
    template <typename T1, typename T2>
    std::pair<T1, T2> operator-(const std::pair<T1, T2>& a, const std::pair<T1, T2>& b)
    {
      return std::make_pair(a.first - b.first, a.second - b.second);
    }

    template <typename T>
    void sort(std::vector<T>& v)
    {
      std::sort(all(v));
    }

    vi str2vi(const std::string& s, char first_char = 'a')
    {
      vi res(s.size());
      rep(i, s.size()) res[i] = s[i] - first_char;
      return res;
    }

    template <typename T>
    T sum(const std::vector<T>& vec)
    {
      T res = T();
      for (const T& val : vec)
        res = res + val;
      return res;
    }
    template <typename T>
    T min(const std::vector<T>& vec, T init)
    {
      T res = init;
      for (const T& val : vec)
        if (val < res)
          res = val;
      return res;
    }
    template <typename T>
    T max(const std::vector<T>& vec, T init)
    {
      T res = init;
      for (const T& val : vec)
        if (val > res)
          res = val;
      return res;
    }

  }; // namespace utils
}; // namespace kammyu

#endif // KAMMYU_UTILS
