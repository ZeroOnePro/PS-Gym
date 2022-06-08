#include <bits/stdc++.h>

using namespace std;

int n, m;
bool is_used[10];
int seq[10];

void make_seq(int cur) {
  if (cur == m) {
    for (int i = 0; i < m; ++i) cout << seq[i] << ' ';
    cout << '\n';
    return;
  }
  for (int elem = 1; elem <= n; ++elem) {
    if (is_used[elem]) continue;
    is_used[elem] = true;
    seq[cur] = elem;
    make_seq(cur + 1);
    is_used[elem] = false;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  make_seq(0);
  return 0;
}