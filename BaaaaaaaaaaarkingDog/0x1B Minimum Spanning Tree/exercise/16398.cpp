#include <bits/stdc++.h>

using namespace std;

const int range = 1'005;

typedef long long ll;

int n;
// (비용, 출발, 도착)
vector<tuple<int, int, int>> edge;
vector<int> p(range, -1);

int find(int x) {
  if (p[x] < 0)
    return x;
  else
    return p[x] = find(p[x]);
}

// union-find 짜기
// - disjoint set -1로 초기화
// - find는 경로 압축 적용하기
// - union은 union by rank적용하기
// - 높이가 낮은게 높은쪽으로 편입된다
// - rank를 음수로 관리하는다는 것을 명심하기
bool is_diff_group(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return false;
  // rank 같을 때, u로 합치고 rank 갱신, 아래에서 v부모를 u로 지정해줄 것임
  if (p[u] == p[v]) p[u] -= 1;
  // v가 더 rank 작을 때
  if (p[u] < p[v]) p[v] = u;
  // u가 더 rank 작을 때
  else
    p[u] = v;
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      int c;
      cin >> c;
      if (i != j) edge.push_back({c, i, j});
    }
  sort(edge.begin(), edge.end());
  // to do
  // kruscal 짜기
  // - 과정 생각해보자
  // - 간선 n-1개 될 때까지 제일 작은 간선 고른다
  // - 골른 간선의 출발, 도착 정점이 같은 그룹 내에 있는지 살펴보고 같은
  // - 그룹이라면 컷 다른 그룹이라면 간선에 추가 최소 비용에 가중치 누적
  ll mst_edge = 0, min_cost = 0;
  for (auto [cost, st, en] : edge) {
    if (!is_diff_group(st, en)) continue;
    min_cost += cost;
    mst_edge += 1;
    if (mst_edge == n - 1) break;
  }
  cout << min_cost;
  return 0;
}