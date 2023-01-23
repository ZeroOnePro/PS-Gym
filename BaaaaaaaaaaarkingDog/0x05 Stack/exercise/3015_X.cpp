#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  stack<pair<int, int>> s;
  long long ans = 0;
  while (n--) {
    int height, cnt = 1;
    cin >> height;
    while (!s.empty() && s.top().first <= height) {
      // 서로 같은 높이가 들어왔을 때를 고려하지 않았다..
      if (s.top().first == height) cnt += s.top().second;
      ans += s.top().second;
      s.pop();
    }
    if (!s.empty() && s.top().first > height) ans++;
    s.push({height, cnt});
  }
  cout << ans;
  return 0;
}