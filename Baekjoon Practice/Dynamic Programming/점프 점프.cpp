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
  vector<int> dp(n, -1);
  vector<int> seq(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> seq[i];
  }
  // dp[i] = i번째 칸일 때, 현재까지 한 점프회수
  dp[0] = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (dp[i] == -1)
      continue;
    for (int j = 1; j <= seq[i]; ++j) {
      if (i + j >= n)
        break;
      if (dp[i + j] == -1 ||
          dp[i + j] > dp[i] + 1) { // 처음이거나 갱신이 필요할 때 사용하는 조건
        dp[i + j] = dp[i] + 1;
      }
    }
  }
  cout << dp[n - 1] << '\n';
  return 0;
}