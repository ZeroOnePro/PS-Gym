#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
// TSP는 일반적으로 브루트 포스로 시간내에 해결못한다.
// 이미 알듯이 NP-COMPELTE 문제 가뜩이나 이문제는 HARD OPTIMIZATION 이므로
// N<=10인 경우는 가능 10! = 3628800
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> w(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> w[i][j];
    }
  }
  vector<int> visited(n);
  for (int i = 0; i < n; ++i) {
    visited[i] = i;
  }
  int ans = INT_MAX;
  do {
    bool safe = true;
    int sum = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (!w[visited[i]][visited[i + 1]]) {
        safe = false;
      } else {
        sum += w[visited[i]][visited[i + 1]];
      }
    }
    if (safe && w[visited[n - 1]][visited[0]]) {
      sum += w[visited[n - 1]][visited[0]];
      if (ans > sum) {
        ans = sum;
      }
    }
  } while (next_permutation(visited.begin() + 1, visited.end()));
  cout << ans << '\n';
  return 0;
}