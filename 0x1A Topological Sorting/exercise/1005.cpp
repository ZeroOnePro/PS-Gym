#include <bits/stdc++.h>

using namespace std;

const int range = 1'005;

int n, m, w, tc;
vector<int> adj[range];
int deg[range];
int cost[range];
int dp[range];

void init() {
  for (int i = 1; i <= n; ++i) {
    adj[i].clear();
    deg[i] = cost[i] = dp[i] = 0;
  }
}

void t_sort(queue<int>& q) {
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      deg[nxt] -= 1;
      dp[nxt] = max(dp[cur] + cost[nxt], dp[nxt]);
      if (deg[nxt] == 0) q.push(nxt);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> tc;
  while (tc--) {
    queue<int> q;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> cost[i];
    for (int i = 0; i < m; ++i) {
      int from, to;
      cin >> from >> to;
      adj[from].push_back(to);
      deg[to] += 1;
    }
    cin >> w;
    for (int i = 1; i <= n; ++i)
      if (deg[i] == 0) {
        q.push(i);
        dp[i] = cost[i];
      }
    t_sort(q);
    cout << dp[w] << '\n';
    init();
  }
  return 0;
}