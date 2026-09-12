#ifndef KAMMYU_CHANGEABLE_PRIORITY_QUEUE
#define KAMMYU_CHANGEABLE_PRIORITY_QUEUE

#include <queue>
#include <utility>
#include <vector>

namespace kammyu
{
  template <typename T, typename Compare = std::less<T>>
  struct changeable_pqueue
  {
  private:
    std::vector<T> container;
    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, Compare> que;
    std::vector<bool> deleted;
    std::vector<int> index;
    int size, query_size, iter;

    void clean()
    {
      while (deleted[que.top().second])
        que.pop();
    }

  public:
    changeable_pqueue() { changeable_pqueue(std::vector<T>(), 0); }
    changeable_pqueue(const std::vector<T>& vec, int Q) : container(vec.size()), size(vec.size()), query_size(Q), deleted(vec.size(), false), index(vec.size()), iter(vec.size())
    {
      for (int i = 0; i < vec.size(); i++)
      {
        container[i] = vec[i];
        index[i] = i;
        que.emplace(vec[i], i);
      }
    }

    void set(int i, const T& val)
    {
      container[i] = val;
      deleted[index[i]] = true;
      index[i] = iter;
      que.emplace(val, iter);
      iter++;
    }

    void pop()
    {
      clean();
      deleted[que.top().second] = true;
      que.pop();
    }
    const T& top()
    {
      clean();
      return que.top().first;
    }
    bool empty() { return que.empty(); }
  };
}; // namespace kammyu

#endif // KAMMYU_CHANGEABLE_PRIORITY_QUEUE