/******************************************
 * ↓↓↓↓↓↓↓↓↓↓↓↓↓ my library ↓↓↓↓↓↓↓↓↓↓↓↓↓ *
 * https://github.com/googologyFan/kammyu *
 ******************************************/

#include <bits/stdc++.h>

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

#ifndef KAMMYU_INPUT
#define KAMMYU_INPUT

#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

namespace kammyu
{
  namespace input
  {
    template <typename T1, typename T2>
    std::istream& operator>>(std::istream& is, std::pair<T1, T2>& p)
    {
      return is >> p.first >> p.second;
    }

    template <typename T>
    std::istream& operator>>(std::istream& is, std::vector<T>& v)
    {
      for (T& x : v)
        is >> x;
      return is;
    }

    template <typename T>
    void inp_arr(std::vector<T>& v)
    {
      for (T& i : v)
        std::cin >> i;
    }
    template <typename T1, typename T2>
    void inp_arr(std::vector<T1>& v1, std::vector<T2>& v2)
    {
      for (int i = 0; i < (int)v1.size(); i++)
        std::cin >> v1[i] >> v2[i];
    }
    template <typename T1, typename T2, typename T3>
    void inp_arr(std::vector<T1>& v1, std::vector<T2>& v2, std::vector<T3>& v3)
    {
      for (int i = 0; i < (int)v1.size(); i++)
        std::cin >> v1[i] >> v2[i] >> v3[i];
    }
    template <typename T1, typename T2, typename T3, typename T4>
    void inp_arr(std::vector<T1>& v1, std::vector<T2>& v2, std::vector<T3>& v3, std::vector<T4>& v4)
    {
      for (int i = 0; i < (int)v1.size(); i++)
        std::cin >> v1[i] >> v2[i] >> v3[i] >> v4[i];
    }
    template <typename T>
    void inp_arr(std::vector<std::vector<T>>& v)
    {
      for (std::vector<T>& i : v)
        for (T& j : i)
          std::cin >> j;
    }
  }; // namespace input
}; // namespace kammyu

#endif // KAMMYU_INPUT

#ifndef KAMMYU_OUTPUT
#define KAMMYU_OUTPUT

#include <iostream>
#include <ostream>
#include <vector>

namespace kammyu
{
  namespace output
  {
    std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& v)
    {
      for (const std::string& x : v)
        os << x << "\n";
      return os;
    }
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
    {
      for (const T& x : v)
        os << x << ' ';
      return os;
    }
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& v)
    {
      for (const std::vector<T>& x : v)
        os << x << '\n';
      return os;
    }

    void yes(bool o = false)
    {
      if (o)
        std::cout << "Yes";
      else
        std::cout << "Yes" << std::endl;
    }
    void no(bool o = false)
    {
      if (o)
        std::cout << "No";
      else
        std::cout << "No" << std::endl;
    }
    void yn(bool b, bool o = false)
    {
      if (b)
        yes(o);
      else
        no(o);
    }
  }; // namespace output
}; // namespace kammyu

#endif // KAMMYU_OUTPUT

#ifndef KAMMYU_POINT
#define KAMMYU_POINT

#include <iostream>
#include <tuple>
#include <vector>

namespace kammyu
{
  namespace point
  {
    struct P
    {
    private:
      using ll = long long;

    public:
      P() { P(0, 0); }
      P(ll _i, ll _j) : i(_i), j(_j) {}
      ll i, j;
      bool operator==(const P& p) const { return i == p.i && j == p.j; }
      bool operator!=(const P& p) const { return !(*this == p); }
      bool operator<(const P& other) const { return std::tie(i, j) < std::tie(other.i, other.j); }
      bool operator>(const P& other) const { return std::tie(i, j) > std::tie(other.i, other.j); }
      P operator+(const P& other) const { return P(i + other.i, j + other.j); }
      P operator-(const P& other) const { return P(i - other.i, j - other.j); }
      P operator*(const int& other) const { return P(i * other, j * other); }
      P operator*(const ll& other) const { return P(i * other, j * other); }
      P operator*(const P& other) const { return P(i * other.i, j * other.j); }
      P operator*(const double& other) const { return P(i * other, j * other); }
      P operator/(const ll& scaler) const { return P(i / scaler, j / scaler); }
      P operator/(const double& scaler) const { return P(i / scaler, j / scaler); }
      P operator+=(const P& p) { return *this = *this + p; }
      P operator-=(const P& p) { return *this = *this - p; }
      P operator*=(const ll& p) { return *this = *this * p; }
      friend std::ostream& operator<<(std::ostream& os, const P& p) { return os << p.i << " " << p.j; }
      friend std::istream& operator>>(std::istream& is, P& p) { return is >> p.i >> p.j; }
      bool out_of_bounds(ll size) const { return i < 0 || j < 0 || i >= size || j >= size; }
      bool out_of_bounds(ll H, ll W) const { return i < 0 || j < 0 || i >= H || j >= W; }
      P& operator--()
      {
        --i, --j;
        return *this;
      }
      P operator--(int)
      {
        P p = *this;
        --(*this);
        return p;
      }
      void swap()
      {
        std::swap(i, j);
      }
      ll distEucSq() const { return i * i + j * j; }
      ll distManh() const { return abs(i) + abs(j); }
    };

    using piP = std::pair<int, P>;
    using pPP = std::pair<P, P>;
    using vP = std::vector<P>;
    using vpiP = std::vector<piP>;
    using vpPP = std::vector<pPP>;
    using vvP = std::vector<std::vector<P>>;
    using vvpiP = std::vector<std::vector<piP>>;
    const vP around4({P(0, 1), P(1, 0), P(0, -1), P(-1, 0)});
    const vP around8({P(0, 1), P(1, 1), P(1, 0), P(1, -1), P(0, -1), P(-1, -1), P(-1, 0), P(-1, 1)});
  }; // namespace point
}; // namespace kammyu

#endif // KAMMYU_POINT

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


using namespace kammyu::utils;
using namespace kammyu::input;
using namespace kammyu::output;
using namespace kammyu::point;

void MAIN();
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  MAIN();

  return 0;
}

using namespace std;
void solve();
void precalc();
void MAIN()
{
  precalc();
  int T = 1;
  // cin >> T;
  while (T--)
    solve();

  return;
}

// using namespace kammyu::infinities;
// using namespace kammyu::modulos;

#ifndef KAMMYU_SEGTREE
#define KAMMYU_SEGTREE

#include <algorithm>
#include <limits>

#include <atcoder/segtree>

namespace kammyu
{
  namespace e
  {
    template <typename T>
    T zero()
    {
      return 0;
    }
    template <typename T>
    T one()
    {
      return 1;
    }
    template <typename T>
    T type_max()
    {
      return std::numeric_limits<T>::max();
    }
    template <typename T>
    T type_min()
    {
      return std::numeric_limits<T>::min();
    }

  } // namespace e
  namespace op
  {
    template <typename T>
    T add(T a, T b)
    {
      return a + b;
    }
    template <typename T>
    T min(T a, T b)
    {
      return std::min(a, b);
    }
    template <typename T>
    T max(T a, T b)
    {
      return std::max(a, b);
    }
  } // namespace op
  namespace comp
  {
    template <typename T>
    bool min(T a, T b)
    {
      return a > b;
    }
    template <typename T>
    bool max(T a, T b)
    {
      return a < b;
    }
  } // namespace comp
  namespace segtree
  {
    template <typename T>
    struct node
    {
      T val;
      int pos;
    };

    //* op(a, b) -> false: a, true: b
    template <typename T, bool (*_op)(T, T), T (*_e)()>
    struct nodeSeg
    {
    private:
      using node = node<T>;
      static node op(node a, node b)
      {
        if (_op(a.val, b.val))
          return b;
        return a;
      }
      static node e() { return {.val = _e(), .pos = -1}; }

      atcoder::segtree<node, op, e> seg;

    public:
      nodeSeg() = default;
      nodeSeg(int n) : seg(n) {}
      template <typename S>
      nodeSeg(const std::vector<S>& v)
      {
        std::vector<node> vec(v.size());
        for (int i = 0; i < v.size(); i++)
          vec[i] = {.val = v[i], .pos = i};
        seg = atcoder::segtree<node, op, e>(vec);
      }

      void set(int p, T x) { seg.set(p, node{.val = x, .pos = p}); }
      node get(int p) { return seg.get(p); }
      node prod(int l, int r) { return seg.prod(l, r); }
    };

    template <typename T = long long>
    using minSeg = nodeSeg<T, comp::min<T>, e::type_max<T>>;
    template <typename T = long long>
    using maxSeg = nodeSeg<T, comp::max<T>, e::type_min<T>>;

    //* max, min, sum
    template <typename T = long long>
    struct utilSeg
    {
    private:
      using node = node<T>;
      struct S
      {
        node min, max;
        T sum;
      };
      static S op(S a, S b)
      {
        if (a.min.val > b.min.val)
          a.min = b.min;
        if (a.max.val < b.max.val)
          a.max = b.max;
        a.sum += b.sum;
        return a;
      }
      static S e() { return {.min = {.val = e::type_max<T>(), .pos = 1},
                             .max = {.val = e::type_min<T>(), .pos = 1},
                             .sum = 0}; }
      atcoder::segtree<S, op, e> seg;

    public:
      utilSeg() = default;
      utilSeg(int n) : seg(n) {}
      template <typename U>
      utilSeg(const std::vector<U>& v)
      {
        std::vector<S> vec(v.size());
        for (int i = 0; i < v.size(); i++)
          vec[i] = {.min = {.val = v[i], .pos = i},
                    .max = {.val = v[i], .pos = i},
                    .sum = v[i]};
        seg = atcoder::segtree<S, op, e>(vec);
      }

      void set(int p, T x) { seg.set(p, {.min = {.val = x, .pos = p},
                                         .max = {.val = x, .pos = p},
                                         .sum = x}); }
      S get(int p) { return seg.get(p); }
      S prod(int l, int r) { return seg.prod(l, r); }
    };
  } // namespace segtree
}; // namespace kammyu

#endif // KAMMYU_SEGTREE

using namespace kammyu::segtree;

void precalc()
{
  return;
}

void solve()
{
  int N, M;
  cin >> N >> M;
  vi P(N);
  cin >> P;
  utilSeg seg(P);

  while (M--)
  {
    int l, r;
    cin >> l >> r;
    l--;
    auto res = seg.prod(l, r);
    int a = res.min.pos, b = res.max.pos;
    swap(P[a], P[b]);
    seg.set(a, P[a]);
    seg.set(b, P[b]);
  }
  cout << P << endl;

  return;
}

