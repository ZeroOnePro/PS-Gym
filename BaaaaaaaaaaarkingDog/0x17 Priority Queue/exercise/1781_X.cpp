#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int range = 200'005;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  priority_queue<int> pq;
  vector<vector<int>> d2n(range);
  int n;
  cin >> n;
  int d, c;
  while (n--) {
    cin >> d >> c;
    d2n[d].push_back(c);
  }
  ll ans = 0;
  for (int dl = range; dl > 0; --dl) {
    for (int n : d2n[dl]) pq.push(n);
    if (pq.empty()) continue;
    ans += pq.top();
    // 미래의 것들을 큐에 남겨놓고 과거에서 과거의 선택지와 비교하여 최적을 결정
    // 3
    // 1 1
    // 2 10
    // 2 20
    // 시각 1에서 1 1과 2 20이 경쟁, 이후 시각 2에서 2 10이 선택
    pq.pop();
  }
  cout << ans;
  return 0;
}