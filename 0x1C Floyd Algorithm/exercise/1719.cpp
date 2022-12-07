#include <bits/stdc++.h>

using namespace std;

const int range = 205;
const int INF = 0x3f3f3f3f;

int n, m;

int dist[range][range];
int nxt[range][range];

void floyd() {
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) {
        if (k == i || k == j || i == j) continue;
        int new_dist = dist[i][k] + dist[k][j];
        if (dist[i][j] > new_dist) {
          dist[i][j] = new_dist;
          nxt[i][j] = nxt[i][k];
        }
      }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    fill(dist[i] + 1, dist[i] + n + 1, INF);
    dist[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int u, v, cost;
    cin >> u >> v >> cost;
    dist[u][v] = cost;
    dist[v][u] = cost;
    nxt[u][v] = v;
    nxt[v][u] = u;
  }
  floyd();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j)
        cout << "- ";
      else
        cout << nxt[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}