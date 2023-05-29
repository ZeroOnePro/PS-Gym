#include <bits/stdc++.h>

using namespace std;

const int range = 205;

vector<int> adj[range];
bool vis[range];

void bfs(int st) {
  queue<int> q;
  q.push(st);
  vis[st] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      if (vis[nxt]) continue;
      vis[nxt] = true;
      q.push(nxt);
    }
  }
}

int solution(int n, vector<vector<int>> computers) {
  int answer = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (computers[i][j] == 1) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      bfs(i);
      answer += 1;
    }
  }
  return answer;
}