#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    // 막대 높이, 높이의 최초 등장 위치
    stack<pair<long long, long long>> s;
    long long height, part, width = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> height;
      int start = i;
      while (!s.empty() && s.top().first >= height) {
        part = s.top().first * (i - s.top().second);
        width = max(part, width);
        start = s.top().second;
        s.pop();
      }
      s.push({height, start});
    }
    // 잔여물 처리
    while (!s.empty()) {
      part = s.top().first * (n + 1 - s.top().second);
      width = max(part, width);
      s.pop();
    }
    cout << width << '\n';
  }
  return 0;
}