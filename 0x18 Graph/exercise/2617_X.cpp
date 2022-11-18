#include <bits/stdc++.h>

using namespace std;

const int range = 100;

int v, e;

vector<int> h2l[range], l2h[range];
bool vis[range];

bool bfs(int st, vector<int> (&adj)[]) {
  int cnt = 0;
  fill(vis + 1, vis + v + 1, false);
  queue<int> q;
  q.push(st);
  vis[st] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      if (vis[nxt]) continue;
      q.push(nxt);
      vis[nxt] = true;
      cnt += 1;
    }
  }
  return cnt >= (v + 1) / 2;
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int cnt = 0;
  cin >> v >> e;
  for (int i = 0; i < e; ++i) {
    int heavy, ligth;
    cin >> heavy >> ligth;
    h2l[heavy].push_back(ligth);  // 무 -> 가
    l2h[ligth].push_back(heavy);  // 가 -> 무
  }
  for (int i = 1; i <= v; ++i)
    if (bfs(i, h2l) || bfs(i, l2h)) cnt += 1;
  cout << cnt;
  return 0;
}