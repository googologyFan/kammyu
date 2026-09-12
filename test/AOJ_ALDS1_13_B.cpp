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
vi fact(10, 1);
int encode(const vi &v)
{
  vi cnt(9, 0);
  int ret = 0;
  rep(i, 9)
  {
    ret += (v[i] - cnt[v[i]]) * fact[8 - i];
    for (int j = v[i] + 1; j < 9; j++)
      cnt[j]++;
  }
  return ret;
}
void solve()
{
  rep(i, 9) fact[i + 1] = fact[i] * (i + 1);
  kammyu::BFS bfs(fact[9]);

  {
    vi v(9);
    rep(i, 9) v[i] = i;
    do
    {
      int zero;
      rep(i, 9) if (v[i] == 0) zero = i;

      int code = encode(v);
      if (zero > 2)
      {
        swap(v[zero], v[zero - 3]);
        bfs.add_dir(code, encode(v));
        swap(v[zero], v[zero - 3]);
      }
      if (zero < 6)
      {
        swap(v[zero], v[zero + 3]);
        bfs.add_dir(code, encode(v));
        swap(v[zero], v[zero + 3]);
      }
      if (zero % 3 != 0)
      {
        swap(v[zero], v[zero - 1]);
        bfs.add_dir(code, encode(v));
        swap(v[zero], v[zero - 1]);
      }
      if (zero % 3 != 2)
      {
        swap(v[zero], v[zero + 1]);
        bfs.add_dir(code, encode(v));
        swap(v[zero], v[zero + 1]);
      }
    } while (next_permutation(all(v)));
  }

  bfs.run(encode(vi({1, 2, 3, 4, 5, 6, 7, 8, 0})));

  vi v(9);
  inp_arr(v);
  cout << bfs.get_dist(encode(v)) << endl;

  return;
}