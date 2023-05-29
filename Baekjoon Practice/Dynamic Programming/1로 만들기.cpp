#include <ctime>
#include <iostream>
#include <vector>

using namespace std;
vector<int> dp(1000001);
// top-down 방식
int make_one(int n) {

  // 1을 1로 쪼개는 연산은 없다.
  if (n == 1)
    return 0;
  // memoization
  if (dp[n] > 0)
    return dp[n];
  // *skill*
  // 제약이 덜한 경우부터 차례대로 비교해서 내려가면
  // 최소횟수의 비교가 쉽다!
  // -1
  dp[n] = make_one(n - 1) + 1;
  // / 2
  if (n % 2 == 0) {
    int tmp = make_one(n / 2) + 1;
    if (dp[n] > tmp)
      dp[n] = tmp;
  }
  // /3
  if (n % 3 == 0) {
    int tmp = make_one(n / 3) + 1;
    if (dp[n] > tmp)
      dp[n] = tmp;
  }
  return dp[n];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  double result;
  int n;
  cin >> n;

  cout << make_one(n) << '\n';

  cout << result << '\n';
  // bottom - up 방식
  int *d = new int[n];

  d[1] = 0;
  for (int i = 2; i <= n; ++i) {
    d[i] = d[i - 1] + 1;
    if (i % 2 == 0 && d[i] > d[i / 2] + 1) {
      d[i] = d[i / 2] + 1;
    }
    if (i % 3 == 0 && d[i] > d[i / 3] + 1) {
      d[i] = d[i / 3] + 1;
    }
  }
  cout << d[n] << '\n';

  return 0;
}