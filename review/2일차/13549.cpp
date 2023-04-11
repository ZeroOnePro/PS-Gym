#include <bits/stdc++.h>

using namespace std;

const int range = 100'001;

int n, k;
int dist[range];

bool OOB(int x) { return x < 0 || x >= range; }

void bfs_0_1(int st) {
  deque<int> dq;
  fill(dist, dist + range, -1);
  dq.push_front(st);
  dist[st] = 0;
  while (!dq.empty()) {
    int cur = dq.front();
    dq.pop_front();
    for (int nxt : {cur - 1, cur + 1, cur * 2}) {
      if (OOB(nxt) || dist[nxt] >= 0) continue;
      if (nxt == cur * 2) {
        dq.push_front(nxt);
        dist[nxt] = dist[cur];
      } else {
        dq.push_back(nxt);
        dist[nxt] = dist[cur] + 1;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  bfs_0_1(n);
  cout << dist[k];
  return 0;
}