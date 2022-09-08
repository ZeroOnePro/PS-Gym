#include <bits/stdc++.h>

using namespace std;

int n, m;
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
    seq[cur] = i;
    make_seq(cur + 1);
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