#include <bits/stdc++.h>

using namespace std;

const int range = 1'005;

int n, m;

vector<tuple<int, int, int>> edge;
vector<int> p(range, -1);

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

int kruscal() {
  int min_cost = 0, mst_edge = 0;
  for (auto [cost, from, to] : edge) {
    if (!is_diff_group(from, to)) continue;
    min_cost += cost;
    mst_edge += 1;
    // 0번 입구 포함
    if (mst_edge == n) break;
  }
  return min_cost * min_cost;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int min_cost, max_cost;
  cin >> n >> m;
  for (int i = 0; i <= m; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    edge.push_back({1 - cost, from, to});
  }
  sort(edge.begin(), edge.end());
  min_cost = kruscal();
  p = vector<int>(range, -1);
  sort(edge.begin(), edge.end(), greater<tuple<int, int, int>>());
  max_cost = kruscal();
  cout << max_cost - min_cost;
  return 0;
}