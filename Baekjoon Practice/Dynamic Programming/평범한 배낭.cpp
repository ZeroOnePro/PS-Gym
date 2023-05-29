#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, W;
  cin >> n >> W;
  vector<int> weight(n + 1); // 무게 배열
  vector<int> profit(n + 1); //  가격 배열
  vector<vector<int>> dp(n + 1, vector<int>(W + 1));

  for (int i = 1; i <= n; ++i) {
    cin >> weight[i] >> profit[i];
  }

  for (int i = 1; i <= n; ++i) {
    for (int w = 0; w <= W; ++w) {
      if (weight[i] > w) {
        dp[i][w] = dp[i - 1][w];
      } else {
        dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i]] + profit[i]);
      }
    }
  }

  cout << dp[n][W] << '\n';

  return 0;
}