#ifndef KAMMYU_TREE_TRIE
#define KAMMYU_TREE_TRIE

#include <cstddef>
#include <iterator>
#include <unordered_map>
#include <vector>

namespace kammyu
{
  namespace trie
  {
    struct Trie
    {
    private:
      std::vector<Trie*> children;
      Trie* parent;
      int value;
      int n;
      int depth;
      int child_cnt;
      int through_cnt;

    public:
      Trie(int _n) : n(_n), children(_n, nullptr), parent(nullptr), depth(0), child_cnt(0), through_cnt(0) {}
      Trie(Trie* parent, int value, int _n) : n(_n), children(_n, nullptr), parent(parent), value(value), depth(parent->depth + 1), child_cnt(0), through_cnt(0) {}

      Trie* get_child(int v)
      {
        if (children[v] == nullptr)
        {
          children[v] = new Trie(this, v, n);
          child_cnt++;
        }
        if (parent == nullptr)
          through_cnt++;
        children[v]->through_cnt++;
        return children[v];
      }
      Trie* get_child(const std::vector<int>::const_iterator& l, const std::vector<int>::const_iterator& r)
      {
        if (l == r)
          return this;
        return get_child(*l)->get_child(l + 1, r);
      }
      Trie* get_child(const std::vector<int>& vec) { return get_child(vec.begin(), vec.end()); }

      std::vector<int> get_path()
      {
        std::vector<int> path;
        Trie* curr = this;
        while (curr->parent != nullptr)
        {
          path.push_back(curr->value);
          curr = curr->parent;
        }
        std::reverse(path.begin(), path.end());
        return path;
      }

      Trie* get_parent() { return parent; }

      int get_value() { return value; }
      int get_depth() { return depth; }
      int get_child_count() { return child_cnt; }
      int get_through_count() { return through_cnt; }
    };

    template <typename T>
    struct MapTrie
    {
    private:
      std::unordered_map<T, MapTrie*> children;
      MapTrie* parent;
      T value;
      int depth;

    public:
      MapTrie() : parent(nullptr), depth(0) {}
      MapTrie(MapTrie* parent, const T& value) : parent(parent), value(value), depth(parent->depth + 1) {}

      MapTrie* get_child(const T& key)
      {
        if (children.find(key) == children.end())
          children[key] = new MapTrie(this, key);
        return children[key];
      }
      MapTrie* get_child(const std::vector<T>::const_iterator& l, const std::vector<T>::const_iterator& r)
      {
        if (l == r)
          return this;
        return get_child(*l)->get_child(l + 1, r);
      }
      MapTrie* get_child(const std::vector<T>& vec) { return get_child(vec.begin(), vec.end()); }

      std::vector<T> get_path()
      {
        std::vector<T> path;
        MapTrie* curr = this;
        while (curr->parent != nullptr)
        {
          path.push_back(curr->value);
          curr = curr->parent;
        }
        std::reverse(path.begin(), path.end());
        return path;
      }

      MapTrie* get_parent() { return parent; }

      int get_depth() { return depth; }
      int get_child_count() { return children.size(); }
    };
  }; // namespace trie
}; // namespace kammyu

#endif