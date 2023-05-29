#include <bits/stdc++.h>

using namespace std;

const int range = 1'000'005;

int dp[range][2];  // i번 집까지 살펴봤을 때 훔칠 수 있는 최대값, 2차원은
                   // 1번집을 털었는지 아닌지 여부

int solution(vector<int> money) {
  int answer = 0;
  int n = money.size();
  dp[1][0] = money[1];
  dp[1][1] = dp[0][1] = money[0];
  for (int i = 2; i < n; ++i) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + money[i]);
    if (i != n - 1) dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + money[i]);
  }
  answer = max(dp[n - 2][1], dp[n - 1][0]);
  return answer;
}