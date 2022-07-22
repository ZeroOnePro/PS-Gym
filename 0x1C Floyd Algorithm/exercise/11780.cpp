#include <bits/stdc++.h>

using namespace std;

int v, e;
const int INF = 0x3f3f3f3f;
vector<vector<int>> dist(105, vector<int>(105, INF));
vector<vector<int>> nxt(105, vector<int>(105, 0));

void trace_path(int s, int t) {
  vector<int> path = {s};
  int cur = nxt[s][t];
  while (cur != t) {
    path.push_back(cur);
    cur = nxt[cur][t];
  }
  path.push_back(t);
  cout << (int)path.size() << ' ';
  for (int vertex : path) cout << vertex << ' ';
  cout << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> v >> e;
  while (e--) {
    int a, b, cost;
    cin >> a >> b >> cost;

    // 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
    if (dist[a][b] > cost) {
      dist[a][b] = cost;
      nxt[a][b] = b;
    }
  }

  // for (int i = 1; i <= v; ++i) dist[i][i] = 0;

  for (int k = 1; k <= v; ++k) {
    for (int i = 1; i <= v; ++i) {
      for (int j = 1; j <= v; ++j) {
        if (i == j or k == i or k == j) continue;
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  }

  for (int i = 1; i <= v; ++i) {
    for (int j = 1; j <= v; ++j) {
      cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' ';
    }
    cout << '\n';
  }

  for (int i = 1; i <= v; ++i) {
    for (int j = 1; j <= v; ++j) {
      if (dist[i][j] == INF)
        cout << "0\n";
      else
        trace_path(i, j);
    }
  }
  return 0;
}