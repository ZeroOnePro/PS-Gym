#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> dp(n + 1, 0);
  vector<int> food(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    cin >> food[i];
  }
  dp[0] = food[0];
  dp[1] = food[1];
  for (int i = 2; i < n; ++i) {
    dp[i] = max(dp[i - 1], dp[i - 2] + food[i]);
  }
  cout << dp[n - 1] << '\n';
  return 0;
}