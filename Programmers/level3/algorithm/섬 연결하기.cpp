#include <bits/stdc++.h>

using namespace std;

// mst 만들기
// kruscal or prim

const int range = 105;

vector<int> parent(range, -1);
tuple<int, int, int> edges[range];

// 경로 압축 적용
int find(int x) {
  if (parent[x] < 0) return x;
  return parent[x] = find(parent[x]);
}

// union by rank 적용
bool is_diff_group(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return false;
  if (parent[u] == parent[v]) parent[u] -= 1;
  if (parent[u] < parent[v])
    parent[v] = u;
  else
    parent[u] = v;
  return true;
}

int kruscal(int n, int edge) {
  int mst_edge = 0, min_cost = 0;
  for (int i = 0; i < edge; ++i) {
    int u, v, cost;
    tie(cost, u, v) = edges[i];
    if (!is_diff_group(u, v)) continue;
    min_cost += cost;
    mst_edge += 1;
    if (mst_edge == n - 1) break;
  }
  return min_cost;
}

int solution(int n, vector<vector<int>> costs) {
  int answer = 0;
  int e = costs.size();
  for (int i = 0; i < e; ++i) {
    int u = costs[i][0], v = costs[i][1], cost = costs[i][2];
    edges[i] = {cost, u, v};
  }
  sort(edges, edges + e);
  answer = kruscal(n, e);
  return answer;
}