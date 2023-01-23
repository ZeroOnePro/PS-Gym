#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

const int range = 100'005;
const int ds = 3;

int n;
// 1차원 x, 2차원 y, 3차원 z
vector<pair<int, int>> planet[ds];
vector<tuple<int, int, int>> edge;
vector<int> p(range, -1);

int find(int cur) {
  if (p[cur] < 0) return cur;
  return p[cur] = find(p[cur]);
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
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < ds; ++j) {
      int point;
      cin >> point;
      planet[j].push_back({point, i});
    }
  for (int i = 0; i < ds; ++i) sort(planet[i].begin(), planet[i].end());
  for (int i = 1; i < n; ++i)
    for (int j = 0; j < ds; ++j) {
      edge.push_back({planet[j][i].x - planet[j][i - 1].x, planet[j][i - 1].y,
                      planet[j][i].y});
    }
  sort(edge.begin(), edge.end());
  int min_cost = 0, mst_edge = 0;
  for (auto [cost, u, v] : edge) {
    if (!is_diff_group(u, v)) continue;
    mst_edge += 1;
    min_cost += cost;
    if (mst_edge == n - 1) break;
  }
  cout << min_cost;
  return 0;
}