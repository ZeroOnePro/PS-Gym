#include <bits/stdc++.h>

using namespace std;

const int range = 1'005;

int n, m;
vector<pair<int, int>> coord(range);
vector<tuple<double, int, int>> edge;
vector<int> p(range, -1);

double p2p(int u, int v) {
  auto [x1, y1] = coord[u];
  auto [x2, y2] = coord[v];
  double dx = x1 - x2;
  double dy = y1 - y2;
  return sqrt(dx * dx + dy * dy);
}

int find(int x) {
  if (p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return false;
  if (p[u] == p[v]) p[u] -= 1;
  if (p[u] < p[v])
    p[v] = u;
  else
    p[u] = v;
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    coord[i] = {x, y};
  }
  for (int i = 0; i < m; ++i) {
    int st, en;
    cin >> st >> en;
    is_diff_group(st, en);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      edge.push_back({p2p(i, j), i, j});
    }
  }
  sort(edge.begin(), edge.end());
  // 이미 연결된 간선 제외시키기(n-1-m개의 간선 만들기)
  double min_cost = 0;
  int mst_edge = 0;
  for (auto [cost, u, v] : edge) {
    if (!is_diff_group(u, v)) continue;
    min_cost += cost;
    mst_edge += 1;
    if (mst_edge == n - 1 - m) break;
  }
  cout.precision(2);
  cout << fixed << min_cost;
  return 0;
}