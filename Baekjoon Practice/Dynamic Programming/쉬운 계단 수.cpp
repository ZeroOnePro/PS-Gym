#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
  // 1자리로 만들 수 있는 계단수는 1 ~ 9
  for (int i = 1; i <= 9; ++i)
    dp[1][i] = 1;

  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j <= 9; ++j) {
      dp[i][j] = 0;
      if (j - 1 >= 0)
        dp[i][j] += dp[i - 1][j - 1];
      if (j + 1 <= 9)
        dp[i][j] += dp[i - 1][j + 1];
      dp[i][j] %= 1000000000;
    }
  }

  long long sum = 0;

  for (int i = 0; i <= 9; ++i)
    sum += dp[n][i];

  cout << sum << '\n';

  return 0;
}