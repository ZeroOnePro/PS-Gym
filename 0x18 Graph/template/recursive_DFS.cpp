#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10];
bool visited[10];

void dfs(int cur) {
  visited[cur] = true;
  cout << cur << ' ';
  for (auto nxt : adj[cur]) {
    if (visited[nxt]) continue;
    dfs(nxt);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int from, to;
  int n;
  cin >> n;
  while (n--) {
    cin >> from >> to;
    // 무방향 그래프를 가정
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  dfs(1);
  return 0;
}