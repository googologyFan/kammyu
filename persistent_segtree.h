#ifndef KAMMYU_PERSISTENT_SEGTREE
#define KAMMYU_PERSISTENT_SEGTREE

#include <assert.h>
#include <vector>


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
      Node(Node* left, Node* right, int size) : l(left), r(right), size(size)
      {
        val = op(left->val, right->val);
      }

    public:
      Node() {}
      Node(typename vT::iterator a, typename vT::iterator b, int _siz) : size(_siz)
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
      Node* set(int ind, T x) const
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

      Node* roll_back(int left, int right, Node* back_to) const
      {
        if (left == right)
          return (Node*)this;
        if (right - left == size)
          return back_to;
        if (right < size >> 1)
          return new Node(l->roll_back(left, right, back_to->l), r, size);
        if (left >= size >> 1)
          return new Node(l, r->roll_back(left - (size >> 1), right - (size >> 1), back_to->r), size);
        return new Node(l->roll_back(left, size >> 1, back_to->l), r->roll_back(0, right - (size >> 1), back_to->r), size);
      }
    };
    // struct Node

    std::vector<Node*> versions;
    int iter = 0;
    int depth = 0, siz = 1, _n;

    void copy(Node* node)
    {
      iter++;
      versions[iter] = node;
    }

  public:
    Node* get_version(int i) { return versions[i]; }

    persistent_segtree(int Q, const vT& v) : _n(v.size()), versions(Q)
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

      copy(versions[ver]->set(i, x));
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

    int roll_back(int ver, int l, int r) { return roll_back(ver, iter, l, r); }
    int roll_back(int from_ver, int at_ver, int l, int r)
    {
      assert(0 <= from_ver && from_ver <= iter);
      assert(0 <= at_ver && at_ver <= iter);
      assert(0 <= l && l <= r && r <= _n);
      copy(versions[at_ver]->roll_back(l, r, versions[from_ver]));
      return iter;
    }
  };

}; // namespace kammyu

#endif // KAMMYU_PERSISTENT_SEGTREE
