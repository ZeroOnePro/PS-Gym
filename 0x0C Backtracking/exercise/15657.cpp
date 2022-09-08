#include <bits/stdc++.h>

using namespace std;

const int range = 10;

int n, m;
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
  int st = cur == 0 ? 0 : seq[cur - 1];
  for (int i = st; i < n; ++i) {
    seq[cur] = i;
    make_seq(cur + 1);
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