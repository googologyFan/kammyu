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

// 文字列トライ木
#include "kammyu/tree/trie.h"
using namespace kammyu::trie;
void precalc()
{
  return;
}
void solve()
{
  int N;
  cin >> N;
  vs S(N);
  inp_arr(S);

  Trie root(26);

  ll ans = 0;
  rep(i, N)
  {
    Trie* trie = &root;
    for (char c : S[i])
    {
      trie = trie->get_child(c - 'a');
      // cerr << trie->get_depth() - 1 << " " << c << ": " << trie->get_parent()->get_through_count() << "-" << trie->get_through_count() << '\n';
      ans += (trie->get_parent()->get_through_count() - trie->get_through_count()) * (trie->get_depth() - 1);
    }
    ans += (trie->get_through_count() - 1) * trie->get_depth();
    // cerr << endl;
  }
  cout << ans << endl;

  return;
}
