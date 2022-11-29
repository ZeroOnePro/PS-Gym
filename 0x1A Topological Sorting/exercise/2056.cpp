#include <bits/stdc++.h>

using namespace std;

const int range = 10'005;

int n, done;
int workload[range];
int deg[range];
int dp[range];
vector<int> adj[range];

void t_sort(int st) {
  queue<int> q;
  q.push(st);
  dp[st] = workload[st];
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      deg[nxt] -= 1;
      dp[nxt] = max(workload[nxt] + dp[cur], dp[nxt]);
      if (deg[nxt] == 0) q.push(nxt);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int post, wn;
    cin >> workload[i] >> post;
    for (int j = 0; j < post; ++j) {
      cin >> wn;
      adj[wn].push_back(i);
      deg[i] += 1;
    }
  }
  for (int i = 1; i <= n; ++i)
    if (deg[i] == 0 && dp[i] == 0) t_sort(i);
  // for (int i = 1; i <= n; ++i) cout << dp[i] << ' ';
  cout << *max_element(dp + 1, dp + n + 1);
  return 0;
}