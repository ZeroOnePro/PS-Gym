#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi2;

const int range = 500'005;

int n, k;
int dist[2][range];  // 0이 짝, 1이 홀

void bfs() {
  queue<pi2> q;
  for (int i = 0; i < 2; ++i) fill(dist[i], dist[i] + range, -1);
  q.push({n, 0});
  dist[0][n] = 0;
  while (!q.empty()) {
    auto [cur, t] = q.front();
    q.pop();
    for (int nxt : {cur - 1, cur + 1, cur * 2}) {
      if (nxt < 0 || nxt > range - 5) continue;
      if (dist[1 - (t % 2)][nxt] >= 0) continue;
      dist[1 - (t % 2)][nxt] = t + 1;
      q.push({nxt, t + 1});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  bfs();
  int cur = k, t = 0, toggle = 0, ans = -1;
  while (cur <= range - 5) {
    if (dist[toggle][cur] >= 0 && dist[toggle][cur] <= t) {
      ans = t;
      break;
    }
    t += 1;
    cur += t;
    toggle = 1 - toggle;
  }
  cout << ans;
  return 0;
}