#include <bits/stdc++.h>

#include "kammyu/constants.h"
#include "kammyu/input.h"
#include "kammyu/output.h"
#include "kammyu/point.h"
#include "kammyu/utils.h"

using namespace kammyu::utils;
using namespace kammyu::input;
using namespace kammyu::output;
using namespace kammyu::point;

void MAIN();
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  MAIN();

  return 0;
}

using namespace std;
void solve();
void precalc();
void MAIN()
{
  precalc();
  int T = 1;
  // cin >> T;
  while (T--)
    solve();

  return;
}

// using namespace kammyu::infinities;
// using namespace kammyu::modulos;
void precalc()
{
  return;
}

#include "kammyu/tree/edgecalc.h"

int min_op(int a, int b)
{
  return min(a, b);
}
int min_e()
{
  return 1e9;
}
int sum_op(int a, int b)
{
  return a + b;
}
int sum_e()
{
  return 0;
}

void solve()
{
  int N;
  cin >> N;

  kammyu::tree::Tree tree(N);
  cin >> tree;

  kammyu::tree::EdgeCalc<int, min_op, min_e> min_EC(vector<int>(N, 0), tree);
  rep(i, N) min_EC.set_value(i, i);
  kammyu::tree::EdgeCalc<int, sum_op, sum_e> sum_EC(vector<int>(N, 1), tree);

  min_EC.run();
  sum_EC.run();

  int ans = 0;

  return;
}