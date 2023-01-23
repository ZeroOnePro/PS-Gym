#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int u[1002];
  vector<int> sum_two_elem;
  for (int i = 0; i < n; ++i) cin >> u[i];
  // 중복 선택이 가능하다
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      sum_two_elem.push_back(u[i] + u[j]);
    }
  }
  sort(u, u + n);
  sort(sum_two_elem.begin(), sum_two_elem.end());
  bool is_found = false;
  for (int i = n - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (binary_search(sum_two_elem.begin(), sum_two_elem.end(),
                        u[i] - u[j])) {
        cout << u[i];
        is_found = true;
        break;
      }
    }
    if (is_found) break;
  }
  return 0;
}