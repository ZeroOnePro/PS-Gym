#include <bits/stdc++.h>

using namespace std;

const int range = 1'000'000 + 5;
const int divisor = 1'000'000'009;

long long dp[range];

void sum_case() {
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for (int i = 4; i <= range - 5; ++i)
    dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % divisor;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  sum_case();
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    cout << dp[n] << '\n';
  }
  return 0;
}