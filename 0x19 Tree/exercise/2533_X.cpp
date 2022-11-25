#include <bits/stdc++.h>

using namespace std;

const int range = 1'000'005;

enum State { normal, early };

int n;
vector<int> adj[range];
int dp[range][2];

int dfs(int cur, int prev, int state) {
  if (dp[cur][state] != -1) return dp[cur][state];
  // cur이 normal라면, 인접들은 반드시 early여야한다
  if (state == normal) {
    dp[cur][state] = normal;
    for (int nxt : adj[cur]) {
      if (nxt == prev) continue;
      dp[cur][state] += dfs(nxt, cur, early);
    }
  }
  // cur이 early라면, 인접들은 early이던 아니던 상관 없다
  // 다만 최소를 찾아야하니까 두 경우를 비교해줘야한다
  else {
    dp[cur][state] = early;
    for (int nxt : adj[cur]) {
      if (nxt == prev) continue;
      dp[cur][state] += min(dfs(nxt, cur, early), dfs(nxt, cur, normal));
    }
  }
  return dp[cur][state];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  for (int i = 1; i <= n; ++i) fill(dp[i], dp[i] + 2, -1);
  cout << min(dfs(1, -1, 1), dfs(1, -1, 0));
  return 0;
}