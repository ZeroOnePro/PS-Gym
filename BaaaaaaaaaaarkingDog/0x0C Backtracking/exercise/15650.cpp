#include <bits/stdc++.h>

using namespace std;

int n, m;
bool is_used[10];
int seq[10];

void print() {
  for (int i = 0; i < m; ++i) cout << seq[i] << ' ';
  cout << '\n';
}

void make_seq(int cur) {
  if (cur == m) {
    print();
    return;
  }
  for (int i = 1; i <= n; ++i) {
    if (is_used[i]) continue;
    is_used[i] = true;
    seq[cur] = i;
    if (cur == 0 || cur > 0 && seq[cur - 1] < seq[cur]) make_seq(cur + 1);
    is_used[i] = false;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) seq[i - 1] = i;
  make_seq(0);
  return 0;
}