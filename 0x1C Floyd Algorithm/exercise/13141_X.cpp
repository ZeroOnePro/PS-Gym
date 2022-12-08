#include <bits/stdc++.h>

using namespace std;

const int v_range = 205;
const int e_range = 20'005;
const int INF = 0x3f3f3f3f;

// edge 저장
int st[e_range];
int en[e_range];
int cost[e_range];

int dist[v_range][v_range];

int n, m;

void floyd() {
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        // loop가 있는 그래프이므로 dist[i][i]도 갱신 가능하다
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
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
    cin >> st[i] >> en[i] >> cost[i];
    // 임의의 정점 u, v를 연결하는 간선이 다수 개일 수 있다 => multigraph
    dist[st[i]][en[i]] = min(dist[st[i]][en[i]], cost[i]);
    dist[en[i]][st[i]] = min(dist[en[i]][st[i]], cost[i]);
  }
  floyd();
  int mn = INF;
  for (int i = 1; i <= n; ++i) {
    int mx = 0;
    for (int j = 0; j < m; ++j)
      mx = max(mx, dist[i][st[j]] + dist[i][en[j]] + cost[j]);
    mn = min(mx, mn);
  }
  // 나머지가 있으면 0.5 추가해줘야한다
  cout << (mn >> 1) << "." << mn % 2 * 5;
  return 0;
}