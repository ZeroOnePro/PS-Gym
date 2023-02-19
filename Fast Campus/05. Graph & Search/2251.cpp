#include <bits/stdc++.h>

typedef long long int ll;
using namespace std;

const int range = 205;

int limit[3];

struct state {
  int X[3];
  state() {}
  state(int x, int y, int z) { X[0] = x, X[1] = y, X[2] = z; }
  state(int _X[]) {
    for (int i = 0; i < 3; i++) X[i] = _X[i];
  }
  state move(int from, int to, int limit[]) {
    state res(X);
    if (X[from] + X[to] <= limit[to]) {  // 만약 from 을 전부 부을 수 있다면
      res.X[to] = res.X[from] + res.X[to];
      res.X[from] = 0;
    } else {  // from 의 일부만 옮길 수 있는 경우
      res.X[from] -= limit[to] - res.X[to];
      res.X[to] = limit[to];
    }
    return res;
  }
};

queue<state> q;
bool possible[range];
bool vis[range][range][range];

bool is_visited(state s) { return vis[s.X[0]][s.X[1]][s.X[2]]; }
void check_visit(state s) { vis[s.X[0]][s.X[1]][s.X[2]] = true; }
void bfs() {
  q.push(state(0, 0, limit[2]));
  check_visit(state(0, 0, limit[2]));
  while (!q.empty()) {
    state cur = q.front();
    q.pop();
    if (cur.X[0] == 0) possible[cur.X[2]] = true;
    for (int from = 0; from < 3; from++) {
      for (int to = 0; to < 3; to++) {
        if (from == to) continue;
        state nxt = cur.move(from, to, limit);
        if (is_visited(nxt)) continue;
        check_visit(nxt);
        q.push(nxt);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 0; i < 3; ++i) cin >> limit[i];
  bfs();
  for (int i = 0; i <= 200; i++)
    if (possible[i]) cout << i << " ";
  return 0;
}