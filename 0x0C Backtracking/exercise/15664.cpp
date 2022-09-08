#include <bits/stdc++.h>

using namespace std;

const int range = 10;

int n, m;
int in[range];
int seq[range];
int is_used[range];

void print() {
  for (int i = 0; i < m; ++i) cout << seq[i] << ' ';
  cout << '\n';
}

void make_seq(int cur) {
  if (cur == m) {
    print();
    return;
  }
  int dup = 0;
  for (int i = 0; i < n; ++i) {
    if (is_used[i] || dup == in[i] || (cur > 0 && seq[cur - 1] > in[i]))
      continue;
    is_used[i] = true;
    seq[cur] = in[i];
    dup = seq[cur];
    make_seq(cur + 1);
    is_used[i] = false;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> in[i];
  sort(in, in + n);
  make_seq(0);
  return 0;
}