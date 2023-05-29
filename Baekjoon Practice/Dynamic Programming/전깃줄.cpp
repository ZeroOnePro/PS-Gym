#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int dp[501];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  vector<pair<int, int>> tower;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int tower1, tower2;
    cin >> tower1 >> tower2;
    tower.push_back(make_pair(tower1, tower2));
  }
  /* 교차한다는 것은 두 개의 타워의 번호가 순차적으로 진행되지 않는다는 것
   * 하나의 탑을 기준으로 정렬하고 그 옆의 탑의 번호의 LIS를 구하고,
   * 전체 개수에서 LIS 길이를 빼면 제거할 전깃줄나온다.
   * 순서가 있는 수열이 꼬여있음 => 순차적이지 않음..
   * 두 수열의 순서를 가진 문제는 LIS생각해봐도 좋을듯
   */
  sort(tower.begin(), tower.end());
  int max = 1;
  for (int i = 0; i < n; ++i) {
    dp[i] = 1;
    for (int j = 0; j < i; ++j) {
      if (tower[j].second < tower[i].second && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1; // 0 ~ i 까지중에서 dp[i]값이 계속 변화하므로 갱신
      }
    }
    if (max < dp[i]) {
      max = dp[i];
    }
  }
  cout << n - max << '\n';
  return 0;
}