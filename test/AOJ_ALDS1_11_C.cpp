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
// using namespace kammyu::modulos;

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

// Graph-BFS
#include "kammyu/bfs.h"
void solve()
{
  int N;
  cin >> N;
  kammyu::BFS bfs(N);

  rep(i, N)
  {
    int u, k;
    cin >> u >> k;
    rep(j, k)
    {
      int v;
      cin >> v;
      bfs.add_dir(u - 1, v - 1);
    }
  }

  bfs.run(0);

  rep(i, N) cout << i + 1 << " " << bfs.get_dist(i) << endl;

  return;
}