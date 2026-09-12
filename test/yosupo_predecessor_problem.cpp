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

#include "kammyu/AVL.h"
void solve()
{
  int N, Q;
  string T;
  cin >> N >> Q >> T;

  kammyu::AVL::tree<int> tree;
  rep(i, N) if (T[i] == '1') tree.insert(i);

  while (Q--)
  {
    int q, k;
    cin >> q >> k;
    if (q == 0)
    {
      tree.insert(k);
    }
    else if (q == 1)
    {
      tree.erase(k);
    }
    else if (q == 2)
    {
      cout << (tree.lower_bound(k) == k) << "\n";
    }
    else if (q == 3)
    {
      int lb = tree.lower_bound(k);
      if (lb < k)
        cout << -1 << "\n";
      else
        cout << lb << "\n";
    }
    else if (q == 4)
    {
      int floor = tree.floor(k);
      if (k < floor)
        cout << -1 << "\n";
      else
        cout << floor << "\n";
    }
  }

  return;
}