#include <bits/stdc++.h>

using namespace std;

const int range = 505;

int dp[range][range];

int solution(vector<vector<int>> triangle) {
  int answer = 0;
  int r = triangle.size();
  dp[0][0] = triangle[0][0];
  for (int i = 1; i < r; ++i)
    for (int j = 0; j < triangle[i].size(); ++j) {
      if (j == 0)
        dp[i][j] = dp[i - 1][j] + triangle[i][j];
      else if (i == j)
        dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
      else
        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
    }
  answer = *max_element(dp[r - 1], dp[r - 1] + r);
  return answer;
}