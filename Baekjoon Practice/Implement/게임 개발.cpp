#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, direction;
// 북, 서, 남, 동 방향 정의
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

// 왼쪽으로 회전
void turn_left() { direction = (direction + 1) % 4; }

int main(void) {
  cin >> n >> m;
  cin >> x >> y >> direction;
  vector<vector<int>> game_map(n, vector<int>(m, 0));
  game_map[x][y] = 1; // 현재 좌표 방문 처리
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> game_map[i][j];
    }
  }
  // 시뮬레이션 시작
  int cnt = 1;
  int turn_time = 0;
  int trapped = 0;
  while (true) {
    turn_left();
    int nx = x + dx[direction];
    int ny = y + dy[direction];
    // 이동
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) { // 이동시 맵 벗어남
      trapped += 1;
      if (trapped == 4)
        break;
      continue;
    } else {
      if (game_map[nx][ny] == 0) {
        game_map[nx][ny] = 1;
        x = nx;
        y = ny;
        cnt += 1;
        turn_time = 0;
        continue;
      }
      // 회전한 이후 정면에 가보지 않은 칸이 없거나 바다인 경우
      else
        turn_time += 1;
      // 네 방향 모두 갈 수 없는 경우
      if (turn_time == 4) {
        nx = x - dx[direction];
        ny = y - dy[direction];
        // 뒤로 갈 수 있다면 이동하기
        if (game_map[nx][ny] == 0) {
          x = nx;
          y = ny;
        }
        // 뒤가 바다로 막혀있는 경우
        else
          break;
        turn_time = 0;
      }
    }
  }

  cout << cnt << '\n';
}