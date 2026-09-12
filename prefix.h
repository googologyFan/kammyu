#ifndef KAMMYU_PREFIX
#define KAMMYU_PREFIX

#include <vector>
namespace kammyu
{
  namespace _1D
  {
    // get prefix sum array
    template <typename T>
    std::vector<T> &get_pfx(const std::vector<T> &v)
    {
      std::vector<T> pfx(v.size() + 1, 0);
      for (size_t i = 0; i < v.size(); i++)
        pfx[i + 1] = pfx[i] + v[i];
      return pfx;
    }
    // get sum of [l, r)
    template <typename T>
    T &get_sum(const std::vector<T> &pfx, const int l, const int r)
    {
      return pfx[r] - pfx[l];
    }

    // get suffix sum array
    template <typename T>
    std::vector<T> &get_sfx(const std::vector<T> &v)
    {
      std::vector<T> sfx(v.size() + 1, 0);
      for (int i = (int)v.size() - 1; i >= 0; i--)
        sfx[i] = sfx[i + 1] + v[i];
      return sfx;
    }
  };

  namespace _2D
  {
    // get prefix sum array
    template <typename T>
    std::vector<std::vector<T>> get_pfx(const std::vector<std::vector<T>> &v)
    {
      std::vector<std::vector<T>> pfx(v.size() + 1, std::vector<T>(v[0].size() + 1, 0));
      for (size_t i = 0; i < v.size(); i++)
        for (size_t j = 0; j < v[0].size(); j++)
          pfx[i + 1][j + 1] = pfx[i + 1][j] + pfx[i][j + 1] - pfx[i][j] + v[i][j];
      return pfx;
    }

    // get sum of [x1, x2) * [y1, y2)
    template <typename T>
    T &get_sum(const std::vector<std::vector<T>> &pfx, const int x1, const int y1, const int x2, const int y2)
    {
      return pfx[x2][y2] - pfx[x1][y2] - pfx[x2][y1] + pfx[x1][y1];
    }
  };
};

#endif // KAMMYU_PREFIX