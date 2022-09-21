#include <bits/stdc++.h>

using namespace std;

// dp[n][0]은 n호출 시 0출력 개수
// dp[n][1]은 n호출 시 1출력 개수
int dp[41][2];

void fibo(void) {
  dp[0][1] = dp[1][0] = 0;
  dp[0][0] = dp[1][1] = 1;
  for (int i = 2; i <= 40; ++i) {
    for (int j = 0; j < 2; ++j) {
      dp[i][j] = dp[i - 1][j] + dp[i - 2][j];
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  fibo();
  while (tc--) {
    int n;
    cin >> n;
    cout << dp[n][0] << ' ' << dp[n][1] << '\n';
  }
  return 0;
}