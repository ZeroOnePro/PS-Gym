#include <bits/stdc++.h>

using namespace std;

const int range = 32'005;

int n, m;
vector<int> adj[range];
int deg[range];

void t_sort(priority_queue<int, vector<int>, greater<int>>& q) {
  while (!q.empty()) {
    int cur = q.top();
    q.pop();
    cout << cur << ' ';
    for (int nxt : adj[cur]) {
      deg[nxt] -= 1;
      if (deg[nxt] == 0) q.push(nxt);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  priority_queue<int, vector<int>, greater<int>> pq;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
    deg[to] += 1;
  }
  for (int i = 1; i <= n; ++i)
    if (deg[i] == 0) pq.push(i);
  t_sort(pq);
  return 0;
}