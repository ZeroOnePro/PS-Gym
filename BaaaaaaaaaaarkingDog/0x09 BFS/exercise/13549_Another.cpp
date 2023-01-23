#include <bits/stdc++.h>

using namespace std;

// 일반적인 BFS 탐색과 동일하지만,
// 가중치가 0인 정점이 존재하기 때문에 실제로 더 많은 노드를 거쳐가더라도(건너
// 뛴 횟수) 가중치가 더 낮은 경우를 고려해야합니다 그렇기 때문에 결과 값이 방문
// 횟수의 최소가 아닌 가중치의 최소인 경우를 찾아야하고 따라서 가중치가 낮은
// 경로부터 탐색해야합니다.

// 다만 2배의 위치로 N의 제한을 넘어 이동했을 때 최적해를 가질 수 있다는 점을
// 유의하여 이동할 수 있는 노드는 넉넉히 20만 개 이상으로 설정해야 한다.
#define MX 200000

int n, k;
int dist[MX + 2];

void zero_one_bfs(deque<int>& dq) {
  while (!dq.empty()) {
    int cur = dq.front();
    dq.pop_front();
    if (2 * cur < MX && dist[2 * cur] == -1) {
      dist[2 * cur] = dist[cur];
      dq.push_front(2 * cur);
    }
    for (int nxt : {cur - 1, cur + 1}) {
      if (nxt < 0 or nxt >= MX or dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      dq.push_back(nxt);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  fill(dist, dist + MX, -1);
  deque<int> dq;
  dq.push_back(n);
  dist[n] = 0;
  zero_one_bfs(dq);
  cout << dist[k];
  return 0;
}