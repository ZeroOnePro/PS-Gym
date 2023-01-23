#include <bits/stdc++.h>

using namespace std;

// top()은 현재 신호를 받는 탑
// 스텝 별로, 스택에 쌓는 건 top()이 커버할 수 있는 원소들, top()보다 작은 것들
// 번호하고 높이가 탑의 정보이고, 이 둘은 쌍으로 관리돼야함

#define height first
#define number second

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  stack<pair<int, int>> s;
  s.push({1e8 + 1, 0});
  for (int i = 1; i <= n; ++i) {
    int tower;
    cin >> tower;
    while (s.top().height < tower) s.pop();
    cout << s.top().number << ' ';
    s.push({tower, i});
  }
  return 0;
}