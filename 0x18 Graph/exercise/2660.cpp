#include <bits/stdc++.h>

using namespace std;

const int range = 55;

int n;
int score[range];
int dist[range];
vector<int> adj[range];

void bfs(int st) {
  queue<int> q;
  fill(dist, dist + range, -1);
  q.push(st);
  dist[st] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      if (dist[nxt] >= 0) continue;
      dist[nxt] = dist[cur] + 1;
      score[st] = max(score[st], dist[nxt]);
      q.push(nxt);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  while (true) {
    int from, to;
    cin >> from >> to;
    if (from == -1 && to == -1) break;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  for (int i = 1; i <= n; ++i) bfs(i);
  int mn = *min_element(score + 1, score + 1 + n);
  vector<int> candidates;
  for (int i = 1; i <= n; ++i)
    if (mn == score[i]) candidates.push_back(i);
  cout << mn << ' ' << candidates.size() << '\n';
  for (int c : candidates) cout << c << ' ';
  return 0;
}