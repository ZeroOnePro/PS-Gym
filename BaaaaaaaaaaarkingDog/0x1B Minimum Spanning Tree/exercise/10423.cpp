#include <bits/stdc++.h>

using namespace std;

const int range = 1'005;

int n, m, k;
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

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  // 관념 노드번호는 0
  // 어차피 이거보다 작은 가중치는 없어서 무조건 뽑힌다
  // 굳이 관념노드랑 발전소랑 그룹지을 필요 x
  for (int i = 0; i < k; ++i) {
    int pn;
    cin >> pn;
    edge.push_back({0, 0, pn});
  }
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edge.push_back({w, u, v});
  }
  sort(edge.begin(), edge.end());
  int mst_edge = 0, min_cost = 0;
  for (auto [cost, u, v] : edge) {
    if (!is_diff_group(u, v)) continue;
    min_cost += cost;
    mst_edge += 1;
    if (mst_edge == n - 1 + k) break;
  }
  cout << min_cost;
  return 0;
}