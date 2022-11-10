#include <bits/stdc++.h>

using namespace std;

#define vertex first
#define level second

typedef long long ll;

int n;
ll ans;
map<int, int> bst;

// void insert(int p, int c, int l) {
//   auto [parent, left, right] = bst[p];
//   if (p > c) {
//     if (left == n) {
//       bst[p] = {parent, c, right};
//       bst[c] = {p, n, n};
//       level[l + 1] += 1;
//       return;
//     } else
//       insert(left, c, l + 1);
//   } else {
//     if (right == n) {
//       bst[p] = {parent, left, c};
//       bst[c] = {p, n, n};
//       level[l + 1] += 1;
//       return;
//     } else
//       insert(right, c, l + 1);
//   }
// }

void insert(int x) {
  auto lb = bst.lower_bound(x);
  if (lb != bst.begin()) {
    if (prev(lb)->level < lb->level)
      bst[x] = lb->level + 1;
    else
      bst[x] = prev(lb)->level + 1;
  } else
    bst[x] = lb->level + 1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  vector<int> p(n);
  for (auto& pt : p) cin >> pt;
  bst[p[0]] = 1;
  for (int i = 1; i <= n - 1; ++i) insert(p[i]);
  for (auto [k, v] : bst) ans += v;
  cout << ans;
  return 0;
}