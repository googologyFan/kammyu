#ifndef KAMMYU_RLE
#define KAMMYU_RLE

#include <utility>
#include <vector>

#include "kammyu/utils.h"

namespace kammyu
{
  namespace RLE
  {
    template <typename T>
    struct compressed
    {
    private:
      T value;
      int length;

    public:
      compressed(T v, int l) : value(v), length(l) {}
      T val() const { return value; }
      int len() const { return length; }
    };
    template <typename T>
    std::vector<compressed<T>> encode(const std::vector<T>& v)
    {
      std::vector<compressed<T>> res;
      if (v.empty())
        return res;

      T prv = v[0];
      int count = 0;
      for (T val : v.size())
      {
        if (val == prv)
          count++;
        else
        {
          res.emplace_back(prv, count);
          prv = val;
          count = 1;
        }
      }
      res.emplace_back(prv, count);
      return res;
    }
    template <typename T>
    std::vector<std::pair<T, int>> decode(const std::vector<compressed<T>>& v)
    {
      std::vector<T> res;
      if (v.empty())
        return res;

      for (const compressed<T>& comp : v)
        for (int i = 0; i < comp.len(); i++)
          res.push_back(comp.val());

      return res;
    }
  }; // namespace RLE
}; // namespace kammyu

#endif // KAMMYU_RLE