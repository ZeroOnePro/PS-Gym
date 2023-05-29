#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;

    // bottom - up
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= n; ++i) {
      dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }

    cout << dp[n] << '\n';
  }

  return 0;
}