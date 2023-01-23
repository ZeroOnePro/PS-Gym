#include <bits/stdc++.h>

using namespace std;

const int range = 405;
const int INF = 0x3f3f3f3f;

int v, e, mn_cycle = INF;
int dist[range][range];

void floyd() {
  for (int k = 0; k < v; ++k)
    for (int i = 0; i < v; ++i)
      for (int j = 0; j < v; ++j) {
        if (k == i || k == j) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> v >> e;
  for (int i = 0; i < v; ++i) fill(dist[i], dist[i] + v, INF);
  for (int i = 0; i < e; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    from--;
    to--;
    dist[from][to] = cost;
  }
  floyd();
  for (int i = 0; i < v; ++i) mn_cycle = min(dist[i][i], mn_cycle);
  cout << (mn_cycle == INF ? -1 : mn_cycle);
  return 0;
}