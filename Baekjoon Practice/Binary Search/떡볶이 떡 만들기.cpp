#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> ricecake(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> ricecake[i];
  }
  int start = 0, end = *max_element(ricecake.begin(), ricecake.end());
  int ans = 0;
  while (start <= end) {
    int total_len = 0;
    int mid = (start + end) / 2;
    for (int i = 0; i < n; ++i) {
      if (ricecake[i] > mid) {
        total_len += ricecake[i] - mid;
      }
    }
    // 모자라는 경우
    if (total_len < m) {
      end = mid - 1;
    }
    // 남는 경우
    else {
      ans = mid; // 최대한 덜 잘랐을 때가 정답
      start = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}