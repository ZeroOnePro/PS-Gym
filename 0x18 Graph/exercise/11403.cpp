#include <bits/stdc++.h>

using namespace std;

int n;
const int range = 105;

vector<int> adj[range];
int res[range][range];
bool vis[range];

void dfs(int st, int cur) {
  for (int nxt : adj[cur]) {
    res[st][nxt] = 1;
    if (vis[nxt]) continue;
    vis[nxt] = true;
    dfs(st, nxt);
  }
}

void print() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << res[i][j] << ' ';
    cout << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      int in;
      cin >> in;
      if (in) adj[i].push_back(j);
    }
  for (int i = 0; i < n; ++i) {
    fill(vis, vis + range, false);
    vis[i] = true;
    dfs(i, i);
  }
  print();
  return 0;
}