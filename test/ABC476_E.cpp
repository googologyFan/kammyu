/******************************************
 * ↓↓↓↓↓↓↓↓↓↓↓↓↓ my library ↓↓↓↓↓↓↓↓↓↓↓↓↓ *
 * https://github.com/googologyFan/kammyu *
 ******************************************/

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

#include "kammyu/segtree.h"
using namespace kammyu::segtree;

void precalc()
{
  return;
}

void solve()
{
  int N, M;
  cin >> N >> M;
  vi P(N);
  cin >> P;
  utilSeg seg(P);

  while (M--)
  {
    int l, r;
    cin >> l >> r;
    l--;
    auto res = seg.prod(l, r);
    int a = res.min.pos, b = res.max.pos;
    swap(P[a], P[b]);
    seg.set(a, P[a]);
    seg.set(b, P[b]);
  }
  cout << P << endl;

  return;
}
