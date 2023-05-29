#include <iostream>
#include <string>
#include <vector>
using namespace std;
int dp[5001];
int temp[5001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string code;
  cin >> code;
  for (int i = 1; i <= (int)code.size(); ++i) {
    temp[i] = code[i - 1] - '0';
  }
  dp[0] = 1;
  for (int i = 1; i <= (int)code.size(); ++i) {
    if (temp[i] > 0) {
      dp[i] += dp[i - 1] % 1000000;
    }
    int isAlpha = (temp[i - 1]) * 10 + temp[i];
    if (i > 1 && 10 <= isAlpha && isAlpha <= 26) {
      dp[i] += dp[i - 2] % 1000000;
    }
  }
  cout << dp[(int)code.size()] % 1000000 << '\n';
  return 0;
}