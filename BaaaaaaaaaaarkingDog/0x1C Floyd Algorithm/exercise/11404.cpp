#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int v, e;
  // INT_MAX쓰면 알고리즘 하다가 INT_MAX + INT_MAX해서 오버플로 날 수도 있음
  // 아무리 거리가 커도 99 * 10^6임
  const int INF = 0x3f3f3f3f;
  cin >> v >> e;
  vector<vector<int>> dist(v + 1, vector<int>(v + 1, INF));
  while (e--) {
    int a, b, cost;
    cin >> a >> b >> cost;

    // 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
    dist[a][b] = min(dist[a][b], cost);
  }

  // for (int i = 1; i <= v; ++i) dist[i][i] = 0;

  for (int k = 1; k <= v; ++k) {
    for (int i = 1; i <= v; ++i) {
      for (int j = 1; j <= v; ++j) {
        if (i == j or k == i or k == j) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  for (int i = 1; i <= v; ++i) {
    for (int j = 1; j <= v; ++j) {
      cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' ';
    }
    cout << '\n';
  }
  return 0;
}