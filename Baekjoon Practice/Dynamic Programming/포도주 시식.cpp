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

  vector<int> wine(10001);
  vector<int> dp(10001);

  for (int i = 1; i <= n; ++i) {
    cin >> wine[i];
  }

  dp[1] = wine[1];
  dp[2] = wine[1] + wine[2];
  for (int i = 3; i <= n; ++i) {
    // i번째 마시지 않는 경우
    dp[i] = max(
        {dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i], dp[i - 1]});
  }

  cout << dp[n] << '\n';
  return 0;
}