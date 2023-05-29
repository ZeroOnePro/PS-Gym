#include <bits/stdc++.h>

using namespace std;

const int range = 100'005;

int dp[range][5];

int solution(vector<vector<int> > land) {
  int answer = 0;
  int n = land.size();
  for (int i = 0; i < 4; ++i) dp[0][i] = land[0][i];
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 4; ++j) {
      int prev_row_mx = 0;
      for (int k = 0; k < 4; ++k) {
        if (j == k) continue;
        prev_row_mx = max(dp[i - 1][k], prev_row_mx);
      }
      dp[i][j] = prev_row_mx + land[i][j];
    }
  }
  answer = *max_element(dp[n - 1], dp[n - 1] + 4);
  return answer;
}