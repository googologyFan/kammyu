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

// BFS-Path
#include "kammyu/bfs.h"
void solve()
{
  int N, M;
  cin >> N >> M;
  kammyu::BFS bfs(N);

  rep(i, M)
  {
    int A, B;
    cin >> A >> B;
    bfs.add_undir(A - 1, B - 1);
  }

  bfs.run(0);

  rep(i, N) if (bfs.get_dist(i) == -1)
  {
    no();
    return;
  }

  yes();
  rep(i, N - 1) cout << bfs.get_prev(i + 1) + 1 << endl;

  return;
}