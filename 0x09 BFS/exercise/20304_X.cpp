#include <bits/stdc++.h>

using namespace std;

const int range = (int)1e6;

int n, m;
int dist[range + 5];

void print_binary(int n) {
  string bis;
  while (n != 0) {
    int r = n % 2;
    bis += to_string(r);
    n /= 2;
  }
  reverse(bis.begin(), bis.end());
  int len = bis.length();
  for (int i = 0; i < 32 - len; ++i) {
    bis.insert(0, 1, '0');
  }
  cout << bis << '\n';
}

int flip(int n, int i) {
  int nxt = 0;
  // i번째 비트가 1일 경우, 0으로 바꿔줌
  if (n & (1 << i)) nxt = n & ~(1 << i);
  // i번째 비트가 0일 경우, 1로 바꿔줌
  else
    nxt = n | (1 << i);
  return nxt;
}

void bfs(queue<int>& q) {
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    // 2^20이 최대인 백만보다 큼
    for (int i = 0; i < 20; ++i) {
      int nxt = flip(cur, i);
      if (nxt > range) continue;
      if (dist[nxt] >= 0) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<int> q;
  cin >> n >> m;
  fill(dist, dist + range + 5, -1);
  for (int i = 0; i < m; ++i) {
    int p;
    cin >> p;
    dist[p] = 0;
    q.push(p);
  }
  bfs(q);
  int ans = 0;
  for (int i = 0; i <= n; ++i) ans = max(ans, dist[i]);
  cout << ans << '\n';
  return 0;
}