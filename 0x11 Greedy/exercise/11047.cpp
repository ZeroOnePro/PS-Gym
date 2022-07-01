#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  int coin[n];
  for (int i = 0; i < n; ++i) cin >> coin[i];
  int cnt = 0;
  for (int i = n - 1; i >= 0; --i) {
    cnt += k / coin[i];
    k %= coin[i];
  }
  cout << cnt << '\n';
  return 0;
}