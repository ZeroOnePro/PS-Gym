#include <iostream>
#include <vector>

using namespace std;

/*
중복이 가능한 경우의 점화식이
d[n] = d[n-1] + d[n-2] + d[n-3]
에서 d[n-1]과 d[n-2], d[n-3]를 먼저 구한다음 d[n]을 구하지말고
1만 써서 표현할 수 있는 개수, 2만 써서 표현할 수 있는 개수, 3만 써서 표현할 수
있는 개수를 d[n]에 각각 더해주면서 구하면 중복이 없는 경우만 뽑아 넣을 수 있게
된다.

1, 2, 3 더하기 4와 똑같은 문제
*/
int coin[101];
int dp[10001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> coin[i];
  }
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (j - coin[i] >= 0)
        dp[j] += dp[j - coin[i]];
    }
  }
  cout << dp[k] << '\n';
  return 0;
}