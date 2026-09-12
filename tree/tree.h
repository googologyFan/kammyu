#ifndef KAMMYU_TREE_TREE
#define KAMMYU_TREE_TREE

#include <istream>

#include "kammyu/utils.h"

namespace kammyu
{
  namespace tree
  {
    struct Tree
    {
    private:
      int n;
      utils::vvi edges;

    public:
      Tree(int _n) : n(_n), edges(_n) {}
      Tree(int _n, const utils::vvi& edges) : n(_n), edges(edges) {}
      Tree(int _n, const utils::vi& parent) : n(_n), edges(n)
      {
        rep(i, n) if (parent[i] != -1)
        {
          edges[parent[i]].push_back(i);
          edges[i].push_back(parent[i]);
        }
      }

      friend std::istream& operator>>(std::istream& is, Tree& tree)
      {
        rep(i, tree.n - 1)
        {
          int u, v;
          is >> u >> v;
          tree.edges[u].push_back(v);
          tree.edges[v].push_back(u);
        }
        return is;
      }

      void add_dir(int from, int to) { edges[from].push_back(to); }
      void add_undir(int u, int v)
      {
        edges[u].push_back(v);
        edges[v].push_back(u);
      }

      int size() const { return n; }
      const utils::vvi& get_all_edges() const { return edges; }
      const utils::vi& get_edges(int v) const { return edges[v]; }
    };
  }; // namespace tree
}; // namespace kammyu

#endif // KAMMYU_TREE_TREE