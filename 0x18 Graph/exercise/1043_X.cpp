#include <bits/stdc++.h>

using namespace std;

const int range = 55;

int n, m, t;
int cnt;
bool truth[range];
vector<int> pt[range];
vector<int> adj[range];

void bfs() {
  queue<int> q;
  for (int i = 1; i <= n; ++i)
    if (truth[i]) q.push(i);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      if (truth[nxt]) continue;
      truth[nxt] = true;
      q.push(nxt);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> t;
  cnt = m;
  for (int i = 0; i < t; ++i) {
    int in;
    cin >> in;
    truth[in] = true;
  }
  for (int i = 0; i < m; ++i) {
    int p;
    cin >> p;
    for (int j = 0; j < p; ++j) {
      int pn;
      cin >> pn;
      pt[i].push_back(pn);
      if (j >= 1) {
        adj[pt[i][j - 1]].push_back(pt[i][j]);
        adj[pt[i][j]].push_back(pt[i][j - 1]);
      }
    }
  }
  bfs();
  for (int i = 0; i < m; ++i)
    for (int p : pt[i])
      if (truth[p]) {
        cnt -= 1;
        break;
      }
  cout << cnt;
  return 0;
}