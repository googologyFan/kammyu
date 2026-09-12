#ifndef KAMMYU_TREE_EDGECALC
#define KAMMYU_TREE_EDGECALC

#include <assert.h>
#include <stack>

#include "kammyu/tree/tree.h"

namespace kammyu
{
  using namespace kammyu::utils;
  namespace tree
  {
    // using T = int;
    // T op(T a, T b)
    // {
    //   return a + b;
    // }
    // T e()
    // {
    //   return 0;
    // }
    template <typename T, T (*op)(T, T), T (*e)()>
    struct EdgeCalc
    {
    private:
      struct edge
      {
        int from, to;
        T val;
        bool calced = false;
        edge(int f, int t) : from(f), to(t), val(e()) {}
        edge(int f, int t, T v) : from(f), to(t), val(v) {}
        bool operator<(const edge& other) const { return std::tie(from, to) < std::tie(other.from, other.to); }
      };

      int n;
      vv<edge> edges;
      std::vector<T> container;

      T dfs(int now, edge* parent = nullptr)
      {
        T res = container[now];
        for (edge& ed : edges[now])
          if (parent == nullptr || ed.to != parent->from)
          {
            if (!ed.calced)
            {
              ed.calced = true;
              ed.val = dfs(ed.to, &ed);
            }
            res = op(res, ed.val);
          }
        return res;
      }

    public:
      EdgeCalc(std::vector<T> val, const Tree& tree) { EdgeCalc(tree.size(), val, tree.get_all_edges()); }
      EdgeCalc(int _n, std::vector<T> val, const vvi& _edges) : n(_n), container(val)
      {
        edges.resize(n);
        for (int i = 0; i < n; i++)
          for (int to : _edges[i])
            edges[i].emplace_back(i, to);
      }

      void run()
      {
        for (int i = 0; i < n; i++)
          dfs(i);
      }

      const vv<edge>& get_all_edges() { return edges; }
      const std::vector<edge>& get_edges(int v) { return edges[v]; }
      const T& get_value(int v) { return container[v]; }
      void set_value(int v, T val) { container[v] = val; }

      const T& get(int from, int to)
      {
        auto it = std::lower_bound(edges[from].begin(), edges[from].end(), edge(from, to));
        assert(it == edges[from].end());
        assert(it->to != to);
        return it->val;
      }
    };
  }; // namespace tree
}; // namespace kammyu

#endif // KAMMYU_TREE_EDGECALC