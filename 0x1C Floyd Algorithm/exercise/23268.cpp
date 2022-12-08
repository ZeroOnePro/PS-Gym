#include <bits/stdc++.h>

using namespace std;

const int range = 305;
const int INF = 0x3f3f3f3f;

int n, m, t;
int huddle[range][range];

void floyd() {
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (i == j || k == i || k == j) continue;
        huddle[i][j] = min(huddle[i][j], max(huddle[i][k], huddle[k][j]));
      }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> t;
  for (int i = 0; i < n; ++i) {
    fill(huddle[i], huddle[i] + n, INF);
    huddle[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int u, v, h;
    cin >> u >> v >> h;
    u--;
    v--;
    huddle[u][v] = h;
  }
  floyd();
  while (t--) {
    int s, e, d;
    cin >> s >> e;
    s--;
    e--;
    if (huddle[s][e] == INF)
      d = -1;
    else
      d = huddle[s][e];
    cout << d << '\n';
  }
  return 0;
}