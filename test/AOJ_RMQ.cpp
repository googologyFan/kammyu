#ifndef KAMMYU_PERSISTENT_SEGTREE
#define KAMMYU_PERSISTENT_SEGTREE

#include <vector>
#include <assert.h>

// using T = int;
// T op(int a, int b) { return std::min(a, b); }
// T e() { return 0; }

namespace kammyu
{

  template <typename T, T (*op)(T, T), T (*e)()>
  struct persistent_segtree
  {
  private:
    using vT = std::vector<T>;

    struct Node
    {
    private:
      T val = e();
      Node *l = nullptr, *r = nullptr;
      int size;
      Node(T v) : val(v), size(1) {}
      Node(Node *left, Node *right, int size) : l(left), r(right), size(size)
      {
        val = op(left->val, right->val);
      }

    public:
      Node() {}
      Node(vT::iterator a, vT::iterator b, int _siz) : size(_siz)
      {
        if (size == 1)
          val = *a;
        else
        {
          typename vT::iterator mid = a + (b - a) / 2;
          l = new Node(a, mid, size >> 1);
          r = new Node(mid, b, size >> 1);
          val = op(l->val, r->val);
        }
      }

      T get() const { return val; }
      T get(int ind) const
      {
        if (size == 1)
          return val;
        return (ind & (size >> 1) ? r : l)->get(ind);
      }
      Node *set(int ind, T x) const
      {
        if (size == 1)
          return new Node(x);
        if (ind & (size >> 1))
          return new Node(l, r->set(ind, x), size);
        return new Node(l->set(ind, x), r, size);
      }

      T prod(int left, int right) const
      {
        if (left == right)
          return e();
        if (right - left == size)
          return val;
        if (right < size >> 1)
          return l->prod(left, right);
        if (left >= size >> 1)
          return r->prod(left - (size >> 1), right - (size >> 1));
        return op(l->prod(left, size >> 1), r->prod(0, right - (size >> 1)));
      }
      T all_prod() const { return val; }
    };
    // struct Node

    std::vector<Node *> versions;
    int iter = 0;
    int depth = 0, siz = 1, _n;

    void copy(int ver, Node *node)
    {
      iter++;
      versions[iter] = node;
    }

  public:
    Node *get_version(int i) { return versions[i]; }

    persistent_segtree(int Q, vT &v) : _n(v.size()), versions(Q)
    {
      while (v.size() > siz)
        siz <<= 1, depth++;
      vT vec(siz, e());
      for (int i = 0; i < _n; i++)
        vec[i] = v[i];

      versions[0] = new Node(vec.begin(), vec.end(), siz);
    }

    int set(int i, T x) { return set(iter, i, x); }
    int set(int ver, int i, T x)
    {
      assert(0 <= ver && ver <= iter);
      assert(0 <= i && i < _n);

      copy(ver, versions[iter]->set(i, x));
      return iter;
    }

    T get(int i) { return get(iter, i); }
    T get(int ver, int i)
    {
      assert(0 <= ver && ver <= iter);
      assert(0 <= i && i < _n);
      return versions[ver]->get(i);
    }

    T prod(int l, int r) { return prod(iter, l, r); }
    T prod(int ver, int l, int r)
    {
      assert(0 <= ver && ver <= iter);
      assert(0 <= l && l <= r && r <= _n);
      return versions[ver]->prod(l, r);
    }

    T all_prod() { return all_prod(iter); }
    T all_prod(int ver)
    {
      assert(0 <= ver && ver <= iter);
      return versions[ver]->all_prod();
    }
  };

};

#endif // KAMMYU_PERSISTENT_SEGTREE

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using piii = pair<int, pii>;
using si = set<int>;
using vi = vector<int>;
using vpii = vector<pii>;
using vvi = vector<vector<int>>;
using vvpii = vector<vector<pii>>;

using vb = vector<bool>;
using vvb = vector<vb>;

using pli = pair<ll, int>;
using plii = pair<pli, int>;
using vpli = vector<pli>;
using vvpli = vector<vector<pli>>;

using pll = pair<ll, ll>;
using plll = pair<pll, ll>;
using vl = vector<ll>;
using vpll = vector<pll>;
using vvl = vector<vector<ll>>;
using vvpll = vector<vector<pll>>;

using vsi = vector<set<int>>;

using vs = vector<string>;

template <typename T>
using vv = vector<vector<T>>;

#define pqueue priority_queue

#define inf 2147483647
// #define _inf -2147483648
// #define INF (ll)(9223372036854775807)
// #define _INF (ll)(-9223372036854775808)

#define Smod 998244353
#define Bmod 1000000007

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sign(f) (f == 0 ? 0 : (f > 0) * 2 - 1)
#define __lcm(a, b) ((a) / __gcd(a, b) * (b))
#define chmax(m, val) m = max(m, val)
#define chmin(m, val) m = min(m, val)

template <typename T>
void inp_arr(vector<T> &v)
{
  for (T &i : v)
    cin >> i;
}
template <typename T1, typename T2>
void inp_arr(vector<T1> &v1, vector<T2> &v2) { rep(i, v1.size()) cin >> v1[i] >> v2[i]; }
template <typename T1, typename T2, typename T3>
void inp_arr(vector<T1> &v1, vector<T2> &v2, vector<T3> &v3) { rep(i, v1.size()) cin >> v1[i] >> v2[i] >> v3[i]; }
template <typename T1, typename T2, typename T3, typename T4>
void inp_arr(vector<T1> &v1, vector<T2> &v2, vector<T3> &v3, vector<T4> &v4) { rep(i, v1.size()) cin >> v1[i] >> v2[i] >> v3[i] >> v4[i]; }
template <typename T>
void inp_arr(vv<T> &v)
{
  for (vector<T> &i : v)
    for (T &j : i)
      cin >> j;
}

template <typename T>
void sort(vector<T> &v) { sort(all(v)); }

struct P
{
  P() { P(0, 0); }
  P(int _i, int _j) : i(_i), j(_j) {}
  int i, j;
  bool operator==(const P &p) const { return i == p.i && j == p.j; }
  bool operator!=(const P &p) const { return !(*this == p); }
  bool operator<(const P &other) const { return tie(i, j) < tie(other.i, other.j); }
  P operator+(const P &other) const { return P(i + other.i, j + other.j); }
  P operator-(const P &other) const { return P(i - other.i, j - other.j); }
  P operator*(const int &other) const { return P(i * other, j * other); }
  P operator*(const double &other) const { return P(i * other, j * other); }
  P operator/(const double &scaler) const { return P(i / scaler, j / scaler); }
  P operator+=(const P &p) { return *this = *this + p; }
  P operator-=(const P &p) { return *this = *this - p; }
  friend ostream &operator<<(ostream &os, const P &p) { return os << "(" << p.i << ", " << p.j << ")"; }
  friend istream &operator>>(istream &is, P &p) { return is >> p.i >> p.j; }
  bool out_of_bounds(int size) const { return i < 0 || j < 0 || i >= size || j >= size; }
  bool out_of_bounds(int H, int W) const { return i < 0 || j < 0 || i >= H || j >= W; }
};

using piP = pair<int, P>;
using vP = vector<P>;
using vpiP = vector<piP>;
using vvP = vector<vector<P>>;
using vvpiP = vector<vector<piP>>;

const vP around({P(0, 1), P(1, 0), P(0, -1), P(-1, 0)});

void yes(bool o = false)
{
  if (o)
    cout << "Yes";
  else
    cout << "Yes" << endl;
}
void no(bool o = false)
{
  if (o)
    cout << "No";
  else
    cout << "No" << endl;
}
void yn(bool b, bool o = false)
{
  if (b)
    yes(o);
  else
    no(o);
}

// 永続セグ木
using T = int;
T op(int a, int b) { return min(a, b); }
T e() { return inf; }
using ps_segtree = kammyu::persistent_segtree<T, op, e>;
int main()
{
  int N, Q;
  cin >> N >> Q;
  vi A(N, inf);
  ps_segtree ps_seg(Q, A);
  while (Q--)
  {
    int q, x, y;
    cin >> q >> x >> y;
    if (!q)
      ps_seg.set(x, y);
    else
      cout << ps_seg.prod(x, y + 1) << endl;
  }

  return 0;
}
