#include <bits/stdc++.h>

using namespace std;

const int range = 2'005;

int arr[range];
int dp[range][range];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    dp[i][i] = 1;
    if (arr[i - 1] == arr[i]) dp[i - 1][i] = 1;
  }

  for (int w = 2; w <= n - 1; ++w)
    for (int st = 1; st <= n - w; ++st) {
      int en = st + w;
      if (arr[st] == arr[en] && dp[st + 1][en - 1]) dp[st][en] = 1;
    }

  cin >> m;
  while (m--) {
    int s, e;
    cin >> s >> e;
    cout << dp[s][e] << '\n';
  }
  return 0;
}