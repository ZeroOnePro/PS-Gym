#include <bits/stdc++.h>

using namespace std;

int dp[5'005];

int ctoi(char ch) { return ch - '0'; }

bool is_alpha(int x) { return 10 <= x && x <= 26; }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string pw;
  int mod = 1'000'000;
  cin >> pw;
  int n = pw.length();
  dp[0] = (pw[0] != '0');
  int tmp = ctoi(pw[0]) * 10 + ctoi(pw[1]);
  if (is_alpha(tmp)) {
    if (tmp % 10 == 0) dp[0] = 0;
    dp[1] = 1 + dp[0];
  } else {
    if (tmp > 26 && (tmp % 10 != 0)) dp[1] = 1;
  }
  for (int i = 2; i < n; ++i) {
    if (pw[i] != '0') dp[i] += (dp[i - 1] % mod);
    tmp = ctoi(pw[i - 1]) * 10 + ctoi(pw[i]);
    if (is_alpha(tmp)) dp[i] += (dp[i - 2] % mod);
  }
  cout << dp[n - 1] % mod;
  return 0;
}