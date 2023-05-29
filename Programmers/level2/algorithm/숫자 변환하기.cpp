#include <bits/stdc++.h>

using namespace std;

const int range = 1e6 + 5;

int dp[range];

int solution(int x, int y, int n) {
  int answer = 0;
  fill(dp, dp + range, range);
  dp[x] = 0;
  for (int i = x; i <= y; ++i)
    for (int nxt : {3 * i, 2 * i, i + n})
      if (nxt <= y) dp[nxt] = min(dp[nxt], dp[i] + 1);
  answer = dp[y] == range ? -1 : dp[y];
  return answer;
}