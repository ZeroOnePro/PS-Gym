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

// union by rank 적용
bool is_diff_group(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return false;
  // parent[u] == parent[v]의 의미는
  // u와 v가 각각 disjoint set의 루트라는 의미이다
  // parent[u]의 부모가 있었다면 find(u) = find(v) = parent[parent[u]]를
  // 반환했을 것이기 때문(v도 마찬가지) union(u, v)를 하게되면, u를 루트로 하고
  // u, v, u의 자식들, v의 자식들이 u의 자식이 됨(경로압축 때문)
  // 만들어진 트리는 rank가 2가되고, u에 저장된 rank를 1 감소시켜야함(rank가
  // 음수로 담긴다)
  if (parent[u] == parent[v]) parent[u] -= 1;
  // rank는 음수
  // 높이가 더 높을 수록 값이 작다
  // 항상 높이가 더 낮은 트리를 높이가 높은 트리 밑에 넣는다
  // 높이가 더 높은 쪽을 루트로 삼는다
  // v의 rank가 더 클 경우(높이가 작은 경우) u의 집합으로 합친다
  // v가 u 밑으로 들어간다
  // 각 disjoint set의 루트만 높이가 담기고 자식들에는 부모의 번호가 담긴다
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