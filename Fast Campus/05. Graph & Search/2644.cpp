#include <bits/stdc++.h>

using namespace std;

vector<int> adj[101];
int check[101];

void dfs(int start, int m) {
  check[start] = m;
  m += 1;
  for (int i = 0; i < (int)adj[start].size(); ++i) {
    int next = adj[start][i];
    if (!check[next]) {
      dfs(next, m);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, start, end, m;
  cin >> n >> start >> end >> m;
  for (int i = 0; i < m; ++i) {
    int parent, child;
    cin >> parent >> child;
    adj[parent].push_back(child);
    adj[child].push_back(parent);
  }
  dfs(start, 1);
  // check배열에서 자기자신과의 촌수를 1로 시작했다(체크를 해야되기 때문에
  // 따라서 -1해야함)
  cout << check[end] - 1 << '\n';
  return 0;
}