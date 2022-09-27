#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc = 1;
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    int graph[n + 5][5];
    int dp[n + 5][5];
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= 3; ++j) cin >> graph[i][j];
    dp[2][1] = graph[1][2] + graph[2][1];
    dp[2][2] =
        min({dp[2][1], graph[1][2], graph[1][2] + graph[1][3]}) + graph[2][2];
    dp[2][3] =
        min({dp[2][2], graph[1][2], graph[1][2] + graph[1][3]}) + graph[2][3];
    for (int i = 3; i <= n; ++i) {
      dp[i][1] = min(dp[i - 1][1], dp[i - 1][2]) + graph[i][1];
      dp[i][2] = min({dp[i - 1][1], dp[i - 1][2], dp[i - 1][3], dp[i][1]}) +
                 graph[i][2];
      dp[i][3] = min({dp[i - 1][2], dp[i - 1][3], dp[i][2]}) + graph[i][3];
    }
    cout << tc << ". " << dp[n][2] << '\n';
    tc += 1;
  }
  return 0;
}