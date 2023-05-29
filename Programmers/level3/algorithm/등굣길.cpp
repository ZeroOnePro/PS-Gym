#include <bits/stdc++.h>

using namespace std;

const int range = 105;
const int d = 1'000'000'007;

int dp[range][range];

int solution(int m, int n, vector<vector<int>> puddles) {
  int answer = 0;
  for (int i = 1; i <= n; ++i) fill(dp[i], dp[i] + m + 1, -1);
  for (vector<int> puddle : puddles) dp[puddle[1]][puddle[0]] = 0;
  dp[1][1] = 1;
  for (int i = 2; i <= n; ++i)
    if (dp[i][1] != 0) dp[i][1] = dp[i - 1][1];
  for (int i = 2; i <= m; ++i)
    if (dp[1][i] != 0) dp[1][i] = dp[1][i - 1];
  for (int i = 2; i <= n; ++i)
    for (int j = 2; j <= m; ++j)
      if (dp[i][j] == -1) dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % d;
  answer = dp[n][m] % d;
  return answer;
}