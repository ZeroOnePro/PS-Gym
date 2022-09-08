#include <bits/stdc++.h>

using namespace std;

int k;
int s[55];
int seq[6];

void print() {
  for (int i = 0; i < 6; ++i) cout << seq[i] << ' ';
  cout << '\n';
};

void make_seq(int cur, int st) {
  if (cur == 6) {
    print();
    return;
  }
  // 중복 미허용, 오름차순 유지
  for (int i = st; i < k; ++i) {
    seq[cur] = s[i];
    make_seq(cur + 1, i + 1);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (true) {
    cin >> k;
    if (k == 0) break;
    for (int i = 0; i < k; ++i) cin >> s[i];
    make_seq(0, 0);
    cout << '\n';
  }
  return 0;
}