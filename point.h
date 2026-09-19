#ifndef KAMMYU_POINT
#define KAMMYU_POINT

#include <iostream>
#include <tuple>
#include <vector>

namespace kammyu
{
  namespace point
  {
    struct P
    {
    private:
      using ll = long long;

    public:
      P() { P(0, 0); }
      P(ll _i, ll _j) : i(_i), j(_j) {}
      ll i, j;
      bool operator==(const P& p) const { return i == p.i && j == p.j; }
      bool operator!=(const P& p) const { return !(*this == p); }
      bool operator<(const P& other) const { return std::tie(i, j) < std::tie(other.i, other.j); }
      bool operator>(const P& other) const { return std::tie(i, j) > std::tie(other.i, other.j); }
      P operator+(const P& other) const { return P(i + other.i, j + other.j); }
      P operator-(const P& other) const { return P(i - other.i, j - other.j); }
      P operator*(const int& other) const { return P(i * other, j * other); }
      P operator*(const ll& other) const { return P(i * other, j * other); }
      P operator*(const P& other) const { return P(i * other.i, j * other.j); }
      P operator*(const double& other) const { return P(i * other, j * other); }
      P operator/(const ll& scaler) const { return P(i / scaler, j / scaler); }
      P operator/(const double& scaler) const { return P(i / scaler, j / scaler); }
      P operator+=(const P& p) { return *this = *this + p; }
      P operator-=(const P& p) { return *this = *this - p; }
      P operator*=(const ll& p) { return *this = *this * p; }
      friend std::ostream& operator<<(std::ostream& os, const P& p) { return os << p.i << " " << p.j; }
      friend std::istream& operator>>(std::istream& is, P& p) { return is >> p.i >> p.j; }
      bool out_of_bounds(ll size) const { return i < 0 || j < 0 || i >= size || j >= size; }
      bool out_of_bounds(ll H, ll W) const { return i < 0 || j < 0 || i >= H || j >= W; }
      P& operator--()
      {
        --i, --j;
        return *this;
      }
      P operator--(int)
      {
        P p = *this;
        --(*this);
        return p;
      }
      void swap()
      {
        std::swap(i, j);
      }
      ll distEucSq() const { return i * i + j * j; }
      ll distManh() const { return abs(i) + abs(j); }
    };

    using piP = std::pair<int, P>;
    using pPP = std::pair<P, P>;
    using vP = std::vector<P>;
    using vpiP = std::vector<piP>;
    using vpPP = std::vector<pPP>;
    using vvP = std::vector<std::vector<P>>;
    using vvpiP = std::vector<std::vector<piP>>;
    const vP around4({P(0, 1), P(1, 0), P(0, -1), P(-1, 0)});
    const vP around8({P(0, 1), P(1, 1), P(1, 0), P(1, -1), P(0, -1), P(-1, -1), P(-1, 0), P(-1, 1)});
  }; // namespace point
}; // namespace kammyu

#endif // KAMMYU_POINT
