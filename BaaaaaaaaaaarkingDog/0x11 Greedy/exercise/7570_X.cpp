#include <bits/stdc++.h>

using namespace std;

const int range = 1'000'005;

int pos[range];
int line[range];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, clis = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> line[i];
    pos[line[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    int cur = line[i];
    int nxt = cur + 1;
    int len = 1;
    while (pos[cur] < pos[nxt]) {
      cur = nxt;
      nxt++;
      len++;
    }
    clis = max(clis, len);
  }
  cout << n - clis;
  return 0;
}