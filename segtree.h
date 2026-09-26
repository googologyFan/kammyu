#ifndef KAMMYU_SEGTREE
#define KAMMYU_SEGTREE

#include <algorithm>
#include <limits>
#include <numeric>

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
    template <typename T>
    T gcd(T a, T b)
    {
      if (a == 0)
        return b;
      if (b == 0)
        return a;
      return std::gcd(a, b);
    }
    template <typename T>
    T lcm(T a, T b)
    {
      return std::lcm(a, b);
    }
    template <typename T>
    T xor_(T a, T b)
    {
      return a ^ b;
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

    template <typename T = long long>
    using gcdSeg = atcoder::segtree<T, op::gcd<T>, e::zero<T>>;
    template <typename T = long long>
    using lcmSeg = atcoder::segtree<T, op::lcm<T>, e::zero<T>>;
    template <typename T = long long>
    using xorSeg = atcoder::segtree<T, op::xor_<T>, e::zero<T>>;
  } // namespace segtree
}; // namespace kammyu

#endif // KAMMYU_SEGTREE
