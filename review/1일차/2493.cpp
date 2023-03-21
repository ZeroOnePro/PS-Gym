#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<int, int> pi2;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  stack<pi2> s, ans;
  cin >> n;
  s.push({1e8 + 5,
          0});  // 관념적인 탑, 입력 중 받을 탑이 없는 탑들의 신호를 받는 역할
  for (int i = 1; i <= n; ++i) {
    int t;
    cin >> t;
    while (!s.empty() && s.top().x <= t) s.pop();
    cout << s.top().y << ' ';
    s.push({t, i});
  }
  return 0;
}