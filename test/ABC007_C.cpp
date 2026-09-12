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

// board-BFS
#include "kammyu/bfs.h"
void solve()
{
  int H, W;
  cin >> H >> W;
  P s, g;
  cin >> s >> g;
  s--;
  g--;
  vs S(H);
  inp_arr(S);

  vvb board(H, vb(W, false));
  rep(i, H) rep(j, W) if (S[i][j] == '#') board[i][j] = true;
  kammyu::board_bfs bfs(H, W, board);
  bfs.run(s);
  cout << bfs.get_dist(g) << endl;

  return;
}