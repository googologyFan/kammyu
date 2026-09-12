#ifndef KAMMYU_OUTPUT
#define KAMMYU_OUTPUT

#include <iostream>
#include <ostream>
#include <vector>

namespace kammyu
{
  namespace output
  {
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& v)
    {
      for (const std::vector<T>& x : v)
        os << x << "\n";
      return os;
    }
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
    {
      for (const T& x : v)
        os << x << " ";
      return os;
    }

    void yes(bool o = false)
    {
      if (o)
        std::cout << "Yes";
      else
        std::cout << "Yes" << std::endl;
    }
    void no(bool o = false)
    {
      if (o)
        std::cout << "No";
      else
        std::cout << "No" << std::endl;
    }
    void yn(bool b, bool o = false)
    {
      if (b)
        yes(o);
      else
        no(o);
    }
  }; // namespace output
}; // namespace kammyu

#endif // KAMMYU_OUTPUT
