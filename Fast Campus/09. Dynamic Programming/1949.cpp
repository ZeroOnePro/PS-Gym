#include <bits/stdc++.h>

using namespace std;

const int range = 1e4 + 5;
int n;
int people[range];
vector<int> adj[range];

int dp[range][2];

void dfs(int cur, int par) {
  dp[cur][1] = people[cur];
  for (int nxt : adj[cur]) {
    if (nxt == par) continue;
    dfs(nxt, cur);
    dp[cur][0] += max(dp[nxt][0], dp[nxt][1]);
    dp[cur][1] += dp[nxt][0];
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> people[i];
  for (int i = 1; i < n; ++i) {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  dfs(1, -1);
  cout << max(dp[1][0], dp[1][1]);
  return 0;
}