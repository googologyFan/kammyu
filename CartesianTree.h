#ifndef KAMMYU_CARTESIAN_TREE
#define KAMMYU_CARTESIAN_TREE

#include <stack>
#include <vector>

namespace kammyu
{
  namespace cartesian_tree
  {
    template <typename T, typename Comp = std::less<T>>
    struct CartesianTree
    {
    private:
      int root_;
      std::vector<int> parent, l, r;
      Comp comp;

    public:
      CartesianTree(const std::vector<T>& vec) : root_(0), parent(vec.size(), -1), l(vec.size(), -1), r(vec.size(), -1), comp()
      {
        int n = vec.size();
        std::stack<T> st;
        st.push(0);
        for (int i = 1; i < n; i++)
        {
          if (comp(vec[st.top()], vec[i]))
          {
            r[st.top()] = i;
            parent[i] = st.top();
            st.push(i);
          }
          else
          {
            T prv;
            while (!st.empty() && !comp(vec[st.top()], vec[i]))
              prv = st.top(), st.pop();
            if (st.empty())
              root_ = i;
            else
            {
              r[st.top()] = i;
              parent[i] = st.top();
            }
            l[i] = prv;
            parent[prv] = i;
            st.push(i);
          }
        }
      }

      T root() { return root_; }
      T par(int i) { return parent[i]; }
      T left(int i) { return l[i]; }
      T right(int i) { return r[i]; }
    };
  }; // namespace cartesian_tree
}; // namespace kammyu

#endif // KAMMYU_CARTESIAN_TREE