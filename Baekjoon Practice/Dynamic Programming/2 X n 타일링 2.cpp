#include <iostream>
#include <vector>

using namespace std;
vector<int> dp(1001);
// top - down
int tile(int n) {
  dp[1] = 1;
  dp[2] = 3;

  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return 3;
  }

  if (dp[n] > 0)
    return dp[n];

  int tmp = tile(n - 2);
  tmp *= 2;
  tmp += tile(n - 1);
  dp[n] = tmp % 10007;

  return dp[n];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  cout << tile(n) << '\n';
  return 0;
}