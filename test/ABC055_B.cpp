#include <bits/stdc++.h>

#include "kammyu/utils.h"
using namespace kammyu::utils;

#include "kammyu/input.h"
using namespace kammyu::input;

#include "kammyu/output.h"
using namespace kammyu::output;

#include "kammyu/constants.h"

#include "kammyu/point.h"
using namespace kammyu::point;

void MAIN();
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  MAIN();

  return 0;
}

// using namespace kammyu::infinities;
using namespace kammyu::modulos;

using namespace std;
void solve();
void MAIN()
{
  int T = 1;
  // cin >> T;
  while (T--)
    solve();

  return;
}

// modded-factorial
#include "kammyu/precalc/factorial.h"
void solve()
{
  kammyu::precalc::fact fact(Bmod);
  int N;
  cin >> N;
  cout << fact[N] << endl;

  return;
}