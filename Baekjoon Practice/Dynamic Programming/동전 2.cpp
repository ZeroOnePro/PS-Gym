#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> coins(n, 0);      // nÁ¾·ù È­Æó
  vector<int> dp(10001, 10001); // dp
  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
    dp[coins[i]] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = coins[i]; j <= k; ++j) {
      // dp[j - coins[i]] == 10001, j원을 만드는 방법 중 i번째 coin이
      // 미사용됨(업데이트가 안됨) 2 3 5 coin 3(j) - 2(coins[0]) = dp[1] =
      // 10001; 3은 2로 만들수 없다. 4(j) - 2(coins[0]) = dp[2] = 1; 4는 2로
      // 만들수 있다.
      dp[j - coins[i]] != 10001 ? dp[j] = dp[j]
                                : dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
    }
  }
  dp[k] == 10001 ? cout << -1 << '\n' : cout << dp[k] << '\n';
  return 0;
}
