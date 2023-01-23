#include <bits/stdc++.h>

using namespace std;

const int range = 1e4 + 5;

int n, m;
bool is_used[range];
int in[10];
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

  for (int i = 0; i < n; ++i) {
    if (is_used[in[i]]) continue;
    seq[cur] = in[i];
    is_used[in[i]] = true;
    make_seq(cur + 1);
    is_used[in[i]] = false;
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