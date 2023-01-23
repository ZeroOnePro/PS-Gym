#include <bits/stdc++.h>

using namespace std;

const int range = 305;
const int INF = 0x3f3f3f3f;

int n, q;
// 1차원 출발 정점 u, 2차원 도착 정점 v, 3차원 거쳐온 정점 갯수
int dist[range][range][range];

void floyd() {
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        dist[i][j][k] =
            min(dist[i][j][k - 1], dist[i][k][k - 1] + dist[k][j][k - 1]);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      int in, d;
      cin >> in;
      d = in == 0 ? INF : in;
      if (i == j) d = 0;
      // i에서 j로 가는데 중간 정점이 없기에 중간 정점 0개를 거친다
      dist[i][j][0] = d;
      dist[j][i][0] = d;
    }
  floyd();
  while (q--) {
    int c, s, e;
    cin >> c >> s >> e;
    int d = dist[s][e][c - 1];
    if (d == INF) d = -1;
    cout << d << '\n';
  }
  return 0;
}