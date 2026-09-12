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