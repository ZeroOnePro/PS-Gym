#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int rope[n + 5];
  for (int i = 1; i <= n; ++i) cin >> rope[i];
  sort(rope + 1, rope + n + 1, greater<int>());
  int w = 0;
  for (int i = 1; i <= n; ++i) w = max(w, rope[i] * i);
  cout << w << '\n';
  return 0;
}