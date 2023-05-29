#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<int> seq(n + 1);
  vector<int> dp(n + 1);

  for (int i = 0; i < n; ++i) {
    cin >> seq[i];
  }

  for (int i = 0; i < n; ++i) {
    dp[i] = seq[i];
    if (i == 0)
      continue;

    if (dp[i] < dp[i - 1] + seq[i]) {
      dp[i] = dp[i - 1] + seq[i];
    }
  }

  int max = dp[0];

  for (int i = 0; i < n; ++i) {
    if (max < dp[i]) {
      max = dp[i];
    }
  }

  cout << max << '\n';

  return 0;
}