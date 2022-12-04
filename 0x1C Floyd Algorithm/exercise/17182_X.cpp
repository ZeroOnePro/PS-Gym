#include <bits/stdc++.h>

using namespace std;

const int range = 15;

int n, k;
int dist[range][range];
bool vis[range];

void floyd() {
  for (int m = 0; m < n; ++m)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (i == j || k == i || k == j) continue;
        dist[i][j] = min(dist[i][j], dist[i][m] + dist[m][j]);
      }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> dist[i][j];
  floyd();
  // 시작 행성은 제외, 이미 탐색된 것
  int ans = 0;
  vis[k] = true;
  while (true) {
    int min_dist = INT_MAX;
    int nearest = -1;
    for (int i = 0; i < n; ++i) {
      if (i == k) continue;
      if (vis[i]) continue;
      if (min_dist > dist[k][i]) {
        min_dist = dist[k][i];
        nearest = i;
      }
    }
    k = nearest;
    vis[k] = true;
    ans += min_dist;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
      if (vis[i]) cnt += 1;
    if (cnt == n) break;
  }
  cout << ans;
  return 0;
}