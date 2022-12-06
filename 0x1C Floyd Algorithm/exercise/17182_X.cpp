#include <bits/stdc++.h>

using namespace std;

const int range = 15;

int n, k, ans = 0x3f3f3f3f;
int dist[range][range];
bool vis[range];

// 시작점 * (n-1)! 경우의 수를 모두 살펴보기
// 백트래킹에서 했었던 n과 m시리즈
void traversal(int cur, int d, int depth) {
  if (depth == n - 1) {
    ans = min(ans, d);
    return;
  }
  for (int nxt = 0; nxt < n; ++nxt) {
    if (vis[nxt]) continue;
    vis[nxt] = true;
    traversal(nxt, d + dist[cur][nxt], depth + 1);
    vis[nxt] = false;
  }
}

void floyd() {
  for (int m = 0; m < n; ++m)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (i == j || m == i || m == j) continue;
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
  vis[k] = true;
  traversal(k, 0, 0);
  cout << ans;
  return 0;
}