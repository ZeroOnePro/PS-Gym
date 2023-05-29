#include <bits/stdc++.h>

using namespace std;

// 인접행렬해야 삭제가 쉽다
// 그래프 탐색 vs 유니온 파인드
// 트리의 특성을 이용하면 완전탐색을 사용하지 않고 O(N)으로 끝낼 수 있고, 모든
// 노드의 자식의 개수를 구하는 것이 힌트

const int range = 105;

int adj[range][range];
int vis[range];

int bfs(int st, int n) {
  int cnt = 1;
  queue<int> q;
  q.push(st);
  vis[st] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 1; i <= n; ++i) {
      if (adj[cur][i] == 0 || cur == i || vis[i]) continue;
      q.push(i);
      vis[i] = true;
      cnt += 1;
    }
  }
  return cnt;
}

int solution(int n, vector<vector<int>> wires) {
  int answer = INT_MAX;
  for (int rm = 0; rm < n - 1; ++rm) {
    vector<int> cnt;

    for (int i = 0; i < n - 1; ++i) {
      // 여기서 그래프 만들 때 edge 두 개 빼기
      if (rm == i) continue;
      int from = wires[i][0], to = wires[i][1];
      adj[from][to] = adj[to][from] = 1;
    }

    for (int i = 1; i <= n; ++i)
      if (!vis[i]) cnt.push_back(bfs(i, n));

    // 탐색 끝내고 차이 세기
    // 트리라 엣지 하나 제거되면 연결 요소 두 개로 분할됨
    answer = min(answer, abs(cnt[0] - cnt[1]));

    fill(vis, vis + range, false);
    for (int i = 1; i <= n; ++i) fill(adj[i], adj[i] + range, 0);
  }
  return answer;
}