#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;
  vector<long long> dp(n + 1, 0);
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    dp[i] = (dp[i - 2] + dp[i - 1]) % 1234567;
  }
  answer = dp[n] % 1234567;
  return answer;
}