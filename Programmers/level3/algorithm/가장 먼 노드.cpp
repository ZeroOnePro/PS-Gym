#include <bits/stdc++.h>

using namespace std;

const int range = 2 * 1e4 + 5;

vector<int> adj[range];
int dist[range];

void bfs() {
  queue<int> q;
  fill(dist, dist + range, -1);
  q.push(1);
  dist[1] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      if (dist[nxt] >= 0) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }
}

int solution(int n, vector<vector<int>> edge) {
  int answer = 0;
  for (int i = 0; i < edge.size(); ++i) {
    int from = edge[i][0], to = edge[i][1];
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  bfs();
  sort(dist + 1, dist + n + 1);
  int mx = dist[n];
  for (int i = n; i >= 0; --i) answer += (mx == dist[i]);
  return answer;
}