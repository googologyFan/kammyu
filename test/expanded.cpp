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
#include <vector>

namespace kammyu
{
  namespace output
  {
    namespace debug
    {
      template <typename T>
      void v(const std::vector<T> &v)
      {
        for (const T &elem : v)
          std::cerr << elem << " ";
      }
      template <typename T>
      void vv(const std::vector<std::vector<T>> &v)
      {
        for (const std::vector<T> &vec : v)
          for (int i = 0; i < vec.size(); i++)
            std::cerr << vec[i] << " \n"[i == vec.size() - 1];
      }
    }
    namespace output
    {
      template <typename T>
      void v(const std::vector<T> &v, std::string sep = " ", std::string end = "\n")
      {
        for (const T &elem : v)
          std::cout << elem << sep;
        std::cout << end;
      }
      template <typename T>
      void vv(const std::vector<std::vector<T>> &v)
      {
        for (const std::vector<T> &vec : v)
          for (int i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " \n"[i == vec.size() - 1];
      }
    };
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
  };
};

#endif // KAMMYU_OUTPUT
#ifndef KAMMYU_POINT
#define KAMMYU_POINT

#include <iostream>
#include <vector>
#include <tuple>

namespace kammyu
{
  namespace point
  {
    struct P
    {
      P() { P(0, 0); }
      P(int _i, int _j) : i(_i), j(_j) {}
      int i, j;
      bool operator==(const P &p) const { return i == p.i && j == p.j; }
      bool operator!=(const P &p) const { return !(*this == p); }
      bool operator<(const P &other) const { return std::tie(i, j) < std::tie(other.i, other.j); }
      P operator+(const P &other) const { return P(i + other.i, j + other.j); }
      P operator-(const P &other) const { return P(i - other.i, j - other.j); }
      P operator*(const int &other) const { return P(i * other, j * other); }
      P operator*(const double &other) const { return P(i * other, j * other); }
      P operator/(const double &scaler) const { return P(i / scaler, j / scaler); }
      P operator+=(const P &p) { return *this = *this + p; }
      P operator-=(const P &p) { return *this = *this - p; }
      friend std::ostream &operator<<(std::ostream &os, const P &p) { return os << p.i << " " << p.j; }
      friend std::istream &operator>>(std::istream &is, P &p) { return is >> p.i >> p.j; }
      bool out_of_bounds(int size) const { return i < 0 || j < 0 || i >= size || j >= size; }
      bool out_of_bounds(int H, int W) const { return i < 0 || j < 0 || i >= H || j >= W; }
      P &operator--()
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
    };

    using piP = std::pair<int, P>;
    using vP = std::vector<P>;
    using vpiP = std::vector<piP>;
    using vvP = std::vector<std::vector<P>>;
    using vvpiP = std::vector<std::vector<piP>>;
    const vP around4({P(0, 1), P(1, 0), P(0, -1), P(-1, 0)});
    const vP around8({P(0, 1), P(1, 1), P(1, 0), P(1, -1), P(0, -1), P(-1, -1), P(-1, 0), P(-1, 1)});
  };
};

#endif // KAMMYU_POINT
#ifndef KAMMYU_UTILS
#define KAMMYU_UTILS

#include <algorithm>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sign(f) (f == 0 ? 0 : (f > 0) * 2 - 1)
#define chmax(m, val) m = max(m, val)
#define chmin(m, val) m = min(m, val)

#define pqueue priority_queue

namespace kammyu
{

  namespace utils
  {
    using ll = long long;
    using pii = std::pair<int, int>;
    using piii = std::pair<int, pii>;
    using si = std::set<int>;
    using vi = std::vector<int>;
    using vpii = std::vector<pii>;
    using vvi = std::vector<std::vector<int>>;
    using vvpii = std::vector<std::vector<pii>>;

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

    using vsi = std::vector<std::set<int>>;

    using vs = std::vector<std::string>;
    template <typename T>
    using vv = std::vector<std::vector<T>>;

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
void precalc()
{
  return;
}

#ifndef KAMMYU_AHO_CORASIC
#define KAMMYU_AHO_CORASIC

#include <functional>
#include <queue>
#include <vector>

namespace kammyu
{
  namespace aho_corasic
  {
    constexpr int AHO_SIZE = 26;
    struct AhoCorasic
    {
    private:
      struct Node
      {
      private:
        int val = -1;

        Node* get(std::vector<int>::const_iterator left, std::vector<int>::const_iterator right)
        {
          Node* curr = this;
          while (left != right)
          {
            curr = curr->get(*left);
            left++;
          }
          return curr;
        }

      public:
        std::vector<Node*> children;
        Node* parent;
        Node* failure;
        Node* next;
        int label = -1;

        Node() : parent(nullptr), failure(nullptr), children(AHO_SIZE, nullptr) {}
        Node(Node* par, int v) : val(v), parent(par), children(AHO_SIZE, nullptr), failure(nullptr) {}

        Node* get(int c)
        {
          if (children[c] == nullptr)
            children[c] = new Node(this, c);
          return children[c];
        }
        Node* get(const std::vector<int>& s)
        {
          return get(s.begin(), s.end());
        }
        bool has_child(int c) { return children[c] != nullptr; }
      };
      Node root;
      int size = 0;

    public:
      AhoCorasic() : root() {}
      void insert(const std::vector<int>& s) { root.get(s)->label = size++; }

      void build()
      {
        std::queue<Node*> que;
        que.push(&root);
        root.failure = &root;
        root.next = &root;

        while (!que.empty())
        {
          Node* q = que.front();
          que.pop();
          for (int c = 0; c < AHO_SIZE; c++)
          {
            if (q->has_child(c))
            {
              Node* node = q->failure;
              if (q == &root)
                q->children[c]->failure = &root;
              else
              {
                while (node != &root && !node->has_child(c))
                  node = node->failure;
                q->children[c]->failure = node->has_child(c) ? node->children[c] : &root;
              }
              q->children[c]->next = q->children[c]->failure;
              if (q->children[c]->next->label == -1 && q->children[c]->next != &root)
                q->children[c]->next = q->children[c]->next->next;
              que.push(q->children[c]);
            }
          }
        }
      }

      Node* next(Node* from, int val, void (*find)(int))
      {
        while (from != &root && !from->has_child(val))
          from = from->failure;
        if (from->has_child(val))
          from = from->children[val];

        Node* temp = from;
        do
          if (temp->label != -1)
            find(temp->label);
        while ((temp = temp->next) != &root);
        return from;
      }

      Node* get_root() { return &root; }
    };
  }; // namespace aho_corasic
}; // namespace kammyu

#endif // KAMMYU_AHO_CORASIC

bool f = false;
void find(int label)
{
  f = true;
}
void solve()
{
  string S;
  int N;
  cin >> S >> N;
  vs T(N);
  cin >> T;

  kammyu::aho_corasic::AhoCorasic ac;
  for (string& t : T)
    ac.insert(str2vi(t));
  ac.build();

  auto front = ac.get_root();

  int ans = 0;
  for (char c : S)
  {
    f = false;
    front = ac.next(front, c - 'a', find);
    if (f)
    {
      ans++;
      front = ac.get_root();
    }
  }

  cout << ans << endl;

  return;
}
