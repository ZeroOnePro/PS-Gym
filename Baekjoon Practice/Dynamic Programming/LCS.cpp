#include <algorithm>
#include <iostream>
using namespace std;
char s1[1002], s2[1002];
int dp[1001][1001], i, j;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> s1 + 1 >> s2 + 1;
  for (i = 1; s1[i]; i++) {
    for (j = 1; s2[j]; j++) {
      dp[i][j] = max(
          {dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] + (s1[i] == s2[j])});
    }
  }
  cout << dp[i - 1][j - 1] << '\n';
  return 0;
}