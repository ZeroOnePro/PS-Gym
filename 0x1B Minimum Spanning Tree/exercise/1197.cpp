#include <bits/stdc++.h>

using namespace std;

vector<int> parent(10005, -1);
int vertex, edge;
tuple<int, int, int> edges[100005];

// 경로 압축 적용
int find(int x) {
  if (parent[x] < 0) return x;
  return parent[x] = find(parent[x]);
}

// union by lank 적용
bool is_diff_group(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return false;
  // parent[u]가 어떤 disjoint set(집합을 트리로 구현했을 때)의 루트라는 의미
  // parent[u]의 부모가 있었다면 find(u) = find(v) = parent[parent[u]] 를
  // 반환했을 것이기 때문 parent[i]에는 i가 루트일 경우 (-1) * i의 rank가
  // 담기는데, union(u, v)를 하게되면, parent[u] 를 루트로 하고 u, v, u의
  // 자식들, v의 자식들이 parent[u]의 자식이 됨(경로압축 때문), 결과적으로
  // 만들어진 트리는 lank가 2가되고, parent[u]는 lank가 - 1 되야함
  if (parent[u] == parent[v]) parent[u] -= 1;
  if (parent[u] < parent[v])
    parent[v] = u;
  else
    parent[u] = v;
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> vertex >> edge;

  for (int i = 0; i < edge; ++i) {
    int u, v, cost;
    cin >> u >> v >> cost;
    edges[i] = {cost, u, v};
  }

  sort(edges, edges + edge);

  int mst_edge = 0, min_cost = 0;

  for (int i = 0; i < edge; ++i) {
    int u, v, cost;
    tie(cost, u, v) = edges[i];
    if (!is_diff_group(u, v)) continue;
    min_cost += cost;
    mst_edge += 1;
    if (mst_edge == vertex - 1) break;
  }

  cout << min_cost;
  return 0;
}