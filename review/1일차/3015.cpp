#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  long long answer = 0;
  stack<pair<int, int>> s;
  cin >> n;
  while (n--) {
    int height, cnt = 1;
    cin >> height;
    while (!s.empty() && s.top().first <= height) {
      if (s.top().first == height)
        cnt += s.top().second;  // 같은게 들어오면 이전에 있던 쌍의 수로 초기화
                                // 5 4 3 2 1 5
      answer += s.top().second;
      s.pop();
    }
    if (!s.empty() && s.top().first > height) answer++;  // 4 1 2 에서 4와 2 쌍
    s.push({height, cnt});
  }
  cout << answer << '\n';
  return 0;
}