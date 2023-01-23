#include <bits/stdc++.h>

using namespace std;

vector<int> adj[8];
int indegree[8];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = 7;
  vector<pair<char, char>> edges;
  edges.push_back({'A', 'B'});
  edges.push_back({'C', 'B'});
  edges.push_back({'C', 'D'});
  edges.push_back({'D', 'B'});
  edges.push_back({'D', 'E'});
  edges.push_back({'E', 'F'});
  edges.push_back({'G', 'E'});
  for (int i = 1; i <= n; ++i) {
    adj[edges[i - 1].first - 'A' + 1].push_back(edges[i - 1].second - 'A' + 1);
    indegree[edges[i - 1].second - 'A' + 1] += 1;
  }
  queue<int> q;
  string result = "";
  for (int i = 1; i <= n; ++i) {
    if (indegree[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    result += cur + 'A' - 1;
    for (auto nxt : adj[cur]) {
      indegree[nxt] -= 1;
      if (indegree[nxt] == 0) q.push(nxt);
    }
  }
  cout << result;
  return 0;
}