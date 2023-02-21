#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int r = 1e9;
const int range = 1 << 10;

int dp[105][10][range];  // i의 길이를 갖는 끝이 j로 끝나는 k로 구성된 계단수

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i < 10; ++i) dp[1][i][(1 << i)] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (int k = 1; k < range; ++k) {
        if (j == 0)
          dp[i][j][k | (1 << 0)] += dp[i - 1][1][k] % r;
        else if (j == 9)
          dp[i][j][k | (1 << 9)] += dp[i - 1][8][k] % r;
        else {
          dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k] % r;
          dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k] % r;
        }
      }
    }
  }
  ll sum = 0;
  for (int i = 0; i < 10; ++i) sum += dp[n][i][range - 1] % r;
  cout << sum % r;
  return 0;
}