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
    vector<ll> dp(1000001);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= n; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
      dp[i] %= 1000000009LL;
    }
    cout << dp[n] % 1000000009LL << '\n';
  }

  return 0;
}