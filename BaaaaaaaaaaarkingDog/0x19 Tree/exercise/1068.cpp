#include <bits/stdc++.h>

using namespace std;

const int range = 55;

int n, rm, root, leaf;
int parent[range];

vector<int> adj[range];

void dfs(int cur) {
  if (root == rm) return;
  for (int nxt : adj[cur]) {
    if (parent[nxt] != -1) continue;
    if (nxt == rm) {
      if (adj[cur].size() == 2) leaf += 1;
      continue;
    }
    if (adj[nxt].size() == 1) leaf += 1;
    parent[nxt] = cur;
    dfs(nxt);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int par;
    cin >> par;
    if (par == -1) root = i;
    adj[par].push_back(i);
    adj[i].push_back(par);
  }
  cin >> rm;
  fill(parent, parent + range, -1);
  dfs(root);
  cout << leaf;
  return 0;
}