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
  vector<int> dp(n + 1, 1);

  for (int i = 0; i < n; ++i) {
    cin >> seq[i];
  }

  int max = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (seq[j] < seq[i] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
      }
    }
    if (max < dp[i]) {
      max = dp[i];
    }
  }

  cout << max << '\n';

  return 0;
}