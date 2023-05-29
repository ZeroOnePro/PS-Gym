#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> dp(31);
  dp[0] = 1;
  for (int i = 2; i <= n; i += 2) {
    dp[i] = 3 * dp[i - 2];
    for (int j = i - 4; j >= 0; j -= 2) {
      dp[i] += dp[j] * 2;
    }
  }
  cout << dp[n] << '\n';
  return 0;
}