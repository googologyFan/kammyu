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

#include "kammyu/bfs.h"
void solve()
{
  int H, W, N;
  cin >> H >> W >> N;
  vs S(H);
  inp_arr(S);
  P start;
  rep(i, H) rep(j, W) if (S[i][j] == 'S') start = P(i, j);
  P target[10];
  target[0] = start;
  int target_max = 0;
  rep(i, H) rep(j, W) if (0 < S[i][j] - '0' && S[i][j] - '0' <= 9)
  {
    target[S[i][j] - '0'] = P(i, j);
    chmax(target_max, S[i][j] - '0');
  }

  vvb board(H, vb(W, false));
  rep(i, H) rep(j, W) if (S[i][j] == 'X') board[i][j] = true;
  // debug::vv(board);
  int ans = 0;
  rep(i, target_max)
  {
    kammyu::board_bfs bfs(H, W, board);
    bfs.run(target[i]);
    ans += bfs.get_dist(target[i + 1]);
  }
  cout << ans << endl;

  return;
}