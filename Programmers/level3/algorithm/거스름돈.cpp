#include <bits/stdc++.h>

using namespace std;

const int r = 1'000'000'007;

int dp[100'005];

int solution(int n, vector<int> money) {
  int answer = 0;
  int len = money.size();
  dp[0] = 1;
  for (int i = 0; i < len; ++i)
    for (int j = money[i]; j <= n; ++j) dp[j] += dp[j - money[i]] % r;
  answer = dp[n];
  return answer;
}