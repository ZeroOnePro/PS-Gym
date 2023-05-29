#include <bits/stdc++.h>

using namespace std;

const int range = 1e8 + 1;

vector<int> nxts;
vector<bool> vis(range);

int bfs(int s) {
  queue<pair<int, int>> q;
  q.push({s, 0});
  vis[s] = true;
  while (!q.empty()) {
    auto [cur, dist] = q.front();
    q.pop();
    for (int nxt : nxts) {
      if (cur + nxt < 0 || cur + nxt > 1e8) continue;
      if (vis[cur + nxt]) continue;
      if (cur + nxt == 0) {
        return dist + 1;
      }
      vis[cur + nxt] = true;
      q.push({cur + nxt, dist + 1});
    }
  }
}

int solution(int storey) {
  int answer = 0;
  for (int i = 1; i <= 1e8; i *= 10) {
    nxts.push_back(i);
    nxts.push_back(-i);
  }
  answer = bfs(storey);
  return answer;
}