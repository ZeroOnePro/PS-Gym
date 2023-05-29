#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<ll> seq(100001);
  vector<ll> dp(100001);
  vector<ll> rdp(100001);
  for (int i = 1; i <= n; ++i) {
    cin >> seq[i];
  }

  for (int i = 1; i <= n; ++i) {
    dp[i] = seq[i];
    if (dp[i] < dp[i - 1] + seq[i]) {
      dp[i] = dp[i - 1] + seq[i];
    }
  }

  for (int i = n; i > 0; --i) {
    rdp[i] = seq[i];
    if (rdp[i] < rdp[i + 1] + seq[i]) {
      rdp[i] = rdp[i + 1] + seq[i];
    }
  }
  // 제거x
  ll ans = dp[1];
  for (int i = 2; i <= n; ++i) {
    if (ans < dp[i]) {
      ans = dp[i];
    }
  }
  // 제거o
  for (int i = 1; i < n; ++i) {
    if (ans < dp[i - 1] + rdp[i + 1]) {
      ans = dp[i - 1] + rdp[i + 1];
    }
  }
  cout << ans << '\n';
  return 0;
}