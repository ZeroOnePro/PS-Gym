#include <bits/stdc++.h>

using namespace std;

const int range = 55;

int n, rm, root;
vector<int> adj[range];
int leaf[range];
bool vis[range];

int dfs(int cur) {
  if (adj[cur].empty()) {
    leaf[cur] = 1;
    return leaf[cur];
  }
  for (int nxt : adj[cur]) {
    if (vis[nxt]) continue;
    vis[nxt] = true;
    leaf[cur] += dfs(nxt);
  }
  return leaf[cur];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int parent;
    cin >> parent;
    if (parent == -1) {
      root = i;
      continue;
    }
    adj[parent].push_back(i);
  }
  cin >> rm;
  // 단방향이라 굳이 실제로 간선을 지울 필요가 없을 거 같다 => 틀림
  // 삭제되는게 leaf이고 일직선 가지라면 그 부모가 leaf가 된다, 실제 배열에서
  // 삭제되어야함
  for (int i = 0; i < n; i++)
    for (auto it = adj[i].begin(); it != adj[i].end(); it++)
      if (*it == rm) {
        adj[i].erase(it);
        break;
      }
  if (root != rm) dfs(root);
  cout << leaf[root];
  return 0;
}