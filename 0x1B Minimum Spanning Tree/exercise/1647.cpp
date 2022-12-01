#include <bits/stdc++.h>

using namespace std;

const int range = 100'005;

int n, m;
vector<tuple<int, int, int>> edge;
vector<int> p(range, -1);

int find(int x) {
  if (p[x] < 0)
    return x;
  else
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
  for (int i = 0; i < m; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    edge.push_back({cost, from, to});
  }
  sort(edge.begin(), edge.end());
  int mst_edge = 0, min_cost = 0;
  for (auto [cost, from, to] : edge) {
    if (!is_diff_group(from, to)) continue;
    mst_edge += 1;
    min_cost += cost;
    if (mst_edge == n - 2) break;
  }
  cout << min_cost;
  return 0;
}