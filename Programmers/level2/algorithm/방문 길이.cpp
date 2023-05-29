#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi2;

bool vis[4][15]
        [15];  // 1차원은 방향(어디로 들어왔는지), 2, 3차원은 각각 x, y 좌표
unordered_map<char, tuple<int, int, int, int>> delta;  // 방향 정보
int cnt;  // 처음 걸어본 길의 수

bool OOB(int x, int y) { return x < 0 || y < 0 || x > 10 || y > 10; }

void game(string dirs) {
  int x = 5, y = 5;
  for (char dir : dirs) {
    auto [dx, dy, d, rd] = delta[dir];
    int nx = x + dx;
    int ny = y + dy;
    if (OOB(nx, ny)) continue;
    if (!vis[rd][nx][ny]) {
      cnt += 1;
      vis[rd][nx][ny] = true;
      vis[d][x][y] = true;
    }
    x = nx;
    y = ny;
  }
}

int solution(string dirs) {
  int answer = 0;
  delta['U'] = {-1, 0, 0, 1};
  delta['D'] = {1, 0, 1, 0};
  delta['L'] = {0, -1, 2, 3};
  delta['R'] = {0, 1, 3, 2};
  game(dirs);
  answer = cnt;
  return answer;
}