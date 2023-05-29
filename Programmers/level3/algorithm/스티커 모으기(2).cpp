#include <bits/stdc++.h>

using namespace std;

// dp[i][j] = i번 스티커까지 최대값이고 j는 1번 스티커 골랐는지 아닌지
// dp[i] = max(dp[i-1], dp[i-2] + sticker[i])
// 마지막 스티커때문에 1번스티커 골랐는지 아닌지 기억해야함

int dp[100'005][2];

int solution(vector<int> sticker) {
  int answer = 0;
  int n = sticker.size();
  dp[1][0] = sticker[1];
  dp[1][1] = dp[0][1] = sticker[0];
  for (int i = 2; i < n; ++i) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + sticker[i]);
    if (i != n - 1) dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + sticker[i]);
  }
  answer = n != 1 ? max(dp[n - 1][0], dp[n - 2][1]) : sticker[0];
  return answer;
}