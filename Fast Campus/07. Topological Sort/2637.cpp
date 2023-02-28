#include <bits/stdc++.h>

using namespace std;

const int range = 105;

int n, m;

// dp[i][j] = j 부품을 만드는데 필요한 i 부품의 수
vector<int> basic;
int dp[range][range];
vector<int> adj[range];
int deg[range];

void t_sort(queue<int>& q) {
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      deg[nxt] -= 1;
      for (int b : basic)
        if (dp[b][cur] != 0)
          if (cur != b) dp[b][nxt] += dp[b][cur] * dp[cur][nxt];
      if (deg[nxt] == 0) q.push(nxt);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<int> q;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int com, need, cnt;
    cin >> com >> need >> cnt;
    adj[need].push_back(com);
    deg[com] += 1;
    dp[need][com] = cnt;
  }
  for (int i = 1; i <= n; ++i)
    if (deg[i] == 0) {
      dp[i][i] = 1;
      basic.push_back(i);
      q.push(i);
    }
  sort(basic.begin(), basic.end());
  t_sort(q);
  for (int b : basic) cout << b << ' ' << dp[b][n] << '\n';
  return 0;
}