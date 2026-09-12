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
  int Q;
  cin >> Q;

  kammyu::AVL::tree<int> tree;

  int size = 0;
  while (Q--)
  {
    int q, k;
    cin >> q >> k;
    if (q == 0)
    {
      size += tree.insert(k);
      cout << size << endl;
    }
    else if (q == 1)
    {
      cout << (size && tree.lower_bound(k) == k) << "\n";
    }
    else if (q == 2)
    {
      size -= tree.erase(k);
    }
    else if (q == 3)
    {
      int r;
      cin >> r;
      int lb = tree.lower_bound(k);
      if (lb < k)
        continue;
      int prv = -1;
      while (lb <= r && prv < lb)
      {
        cout << lb << endl;
        prv = lb;
        lb = tree.lower_bound(lb + 1);
      }
    }
    // tree.debug();
    // cerr << endl;
  }

  return;
}