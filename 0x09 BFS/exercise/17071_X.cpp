#include <bits/stdc++.h>

using namespace std;

const int range = 500000;

int n, k;

// 1차원 홀, 짝 / 2차원 좌표 / 저장 값 좌표에 도달한 최소 시간
int dist[2][range + 1];

bool OOB(int x) { return x < 0 || x > range; }

void bfs() {
  // (좌표, 최초 방문 시간)
  queue<pair<int, int>> q;
  q.push({n, 0});
  dist[0][n] = 0;
  while (!q.empty()) {
    auto [cur, t] = q.front();
    q.pop();
    for (int nxt : {cur - 1, cur + 1, cur * 2}) {
      if (OOB(nxt)) continue;
      if (dist[1 - (t % 2)][nxt] != -1) continue;
      dist[1 - (t % 2)][nxt] = t + 1;
      q.push({nxt, t + 1});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 0; i < 2; ++i) fill(dist[i], dist[i] + range + 1, -1);
  bfs();
  int t = 0, eoo = 0, ans = -1;
  while (k <= range) {
    if (dist[eoo][k] != -1 and dist[eoo][k] <= t) {
      ans = t;
      break;
    }
    eoo = 1 - eoo;
    t += 1;
    k += t;
  }
  cout << ans;
  return 0;
}