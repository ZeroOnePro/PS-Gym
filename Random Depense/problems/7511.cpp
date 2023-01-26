#include <bits/stdc++.h>

using namespace std;

const int range = 1e6 + 5;

vector<int> parent(range, -1);
vector<pair<int, int>> edge;
int t, n, k, m;

// 경로 압축 적용
int find(int x) {
  if (parent[x] < 0) return x;
  return parent[x] = find(parent[x]);
}

// union by rank 적용
void uni(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return;
  if (parent[u] == parent[v]) parent[u] -= 1;
  if (parent[u] < parent[v])
    parent[v] = u;
  else
    parent[u] = v;
  return;
}

bool is_diff_group(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return true;
  return false;
}

void input() {
  int a, b;
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    cin >> a >> b;
    edge.push_back({a, b});
  }
  cin >> m;
}

void print(int turn) {
  cout << "Scenario " << turn << ":\n";
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    cout << is_diff_group(a, b) << '\n';
  }
  cout << '\n';
}

void init() {
  fill(parent.begin(), parent.begin() + n, -1);
  edge.clear();
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    input();
    for (auto [u, v] : edge) uni(u, v);
    print(i);
    init();
  }
  return 0;
}