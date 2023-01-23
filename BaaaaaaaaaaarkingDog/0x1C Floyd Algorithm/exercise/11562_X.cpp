#include <bits/stdc++.h>

using namespace std;

const int range = 255;
const int INF = 0x3f3f3f3f;

int n, m, k;
int dist[range][range];

void floyd() {
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (k == i || k == j || i == j) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    fill(dist[i], dist[i] + n, INF);
    dist[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int u, v, b;
    cin >> u >> v >> b;
    u--;
    v--;
    if (b == 1) {
      dist[u][v] = 0;
      dist[v][u] = 0;
    } else if (b == 0) {
      dist[u][v] = 0;
      dist[v][u] = 1;
    }
  }
  floyd();
  cin >> k;
  while (k--) {
    int s, e;
    cin >> s >> e;
    s--;
    e--;
    cout << dist[s][e] << '\n';
  }
  return 0;
}