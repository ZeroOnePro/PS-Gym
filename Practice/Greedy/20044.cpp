#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  int s[10'005];
  cin >> n;
  for (int i = 0; i < 2 * n; ++i) cin >> s[i];
  sort(s, s + 2 * n);
  int mn = 20'0001;
  for (int i = 0; i < n; ++i) {
    int sum = s[i] + s[2 * n - 1 - i];
    if (mn > sum) mn = sum;
  }
  cout << mn;
  return 0;
}