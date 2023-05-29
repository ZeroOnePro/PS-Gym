#include <algorithm>
#include <iostream>
#include <vector>

#define midget_num 9

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<int> height(midget_num);
  int sum = 0;
  for (int i = 0; i < midget_num; ++i) {
    cin >> height[i];
    sum += height[i];
  }
  // 오름 차순 출력
  sort(height.begin(), height.end());
  for (int i = 0; i < midget_num - 1; ++i) {
    for (int j = i + 1; j < midget_num; ++j) {
      if (sum - height[i] - height[j] == 100) {
        for (int k = 0; k < midget_num; ++k) {
          if (k == i || k == j)
            continue;
          else {
            cout << height[k] << '\n';
          }
        }
        return 0;
      }
    }
  }
  return 0;
}