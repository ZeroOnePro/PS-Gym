#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<vector<ll>> score(100001, vector<ll>(3));
    vector<vector<ll>> dp(100001, vector<ll>(3));
    for (int i = 1; i <= 2; ++i) {
      for (int j = 1; j <= n; ++j) {
        cin >> score[j][i];
      }
    }

    for (int i = 1; i <= n; ++i) {
      dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + score[i][1];
      dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + score[i][2];
    }
    // max에 인자가 여러개 들어가면 { }로 묶는다.
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
  }
  return 0;
}