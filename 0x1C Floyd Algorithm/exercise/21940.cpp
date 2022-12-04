#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

const int range = 205;
const int INF = 0x3f3f3f3f;

int n, m, k;
int dist[range][range];
int c[range];

void floyd() {
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) {
        if (k == i || k == j || i == j) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) fill(dist[i], dist[i] + n + 1, INF);
  for (int i = 0; i < m; ++i) {
    int from, to, t;
    cin >> from >> to >> t;
    dist[from][to] = t;
  }
  cin >> k;
  for (int i = 0; i < k; ++i) cin >> c[i];
  floyd();
  for (int i = 1; i <= n; ++i) {
    int mx = 0;
    for (int j = 0; j < k; ++j) {
      if (i == c[j]) continue;
      mx = max(mx, dist[c[j]][i] + dist[i][c[j]]);
    }
    pq.push({mx, i});
  }
  int mn = pq.top().x;
  while (!pq.empty() && pq.top().x == mn) {
    cout << pq.top().y << ' ';
    pq.pop();
  }
  return 0;
}