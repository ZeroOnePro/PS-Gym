#include <bits/stdc++.h>

using namespace std;

const int range = 2'505;

int dp[range][range];

int solution(string s) {
  int answer = 1;
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 1;
    if (i >= 1 && s[i - 1] == s[i]) dp[i - 1][i] = 2;
  }

  for (int w = 2; w <= n - 1; ++w)
    for (int st = 0; st < n - w; ++st) {
      int en = st + w;
      if (s[st] == s[en] && dp[st + 1][en - 1] == en - st - 1)
        dp[st][en] = en - st + 1;
      answer = max(answer, dp[st][en]);
    }

  return answer;
}