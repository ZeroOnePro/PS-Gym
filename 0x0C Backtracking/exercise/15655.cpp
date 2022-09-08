#include <bits/stdc++.h>

using namespace std;

const int range = 10;

int n, m;
bool is_used[range];
int in[range];
int seq[range];

void print() {
  for (int i = 0; i < m; ++i) cout << in[seq[i]] << ' ';
  cout << '\n';
}

void make_seq(int cur) {
  if (cur == m) {
    print();
    return;
  }
  int st = cur == 0 ? 0 : seq[cur - 1] + 1;
  for (int i = st; i < n; ++i) {
    if (is_used[i]) continue;
    is_used[i] = true;
    seq[cur] = i;
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