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

#include "kammyu/aho_corasic.h"

bool f = false;
void find(int label)
{
  f = true;
}
void solve()
{
  string S;
  int N;
  cin >> S >> N;
  vs T(N);
  cin >> T;

  kammyu::aho_corasic::AhoCorasic ac;
  for (string& t : T)
    ac.insert(str2vi(t));
  ac.build();

  auto front = ac.get_root();

  int ans = 0;
  for (char c : S)
  {
    f = false;
    front = ac.next(front, c - 'a', find);
    if (f)
    {
      ans++;
      front = ac.get_root();
    }
  }

  cout << ans << endl;

  return;
}