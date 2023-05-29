#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<vector<long long>> dp(100001, vector<long long>(4, 0));
  dp[1][1] = 1;
  dp[2][2] = 1;
  dp[3][3] = 1;
  for (int i = 1; i <= 100000; ++i) {
    if (i - 1 > 0)
      dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
    if (i - 2 > 0)
      dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
    if (i - 3 > 0)
      dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
  }

  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009 << '\n';
  }

  return 0;
}