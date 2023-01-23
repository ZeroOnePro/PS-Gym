#include <bits/stdc++.h>

using namespace std;

const int range = 105;
const int INF = 0x3f3f3f3f;

int n, m, r, t;

int item[range];
int dist[range][range];

void floyd() {
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (i == j || k == i || k == j) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> r;
  for (int i = 0; i < n; ++i) cin >> item[i];
  for (int i = 0; i < n; ++i) fill(dist[i], dist[i] + n, INF);
  for (int i = 0; i < r; ++i) {
    int a, b, l;
    cin >> a >> b >> l;
    a--;
    b--;
    dist[a][b] = l;
    dist[b][a] = l;
  }
  floyd();
  int mx_item = 0;
  for (int i = 0; i < n; ++i) {
    int cnt = item[i];
    for (int j = 0; j < n; ++j) {
      if (dist[i][j] <= m) cnt += item[j];
    }
    mx_item = max(mx_item, cnt);
  }
  cout << mx_item;
  return 0;
}