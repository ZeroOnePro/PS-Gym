#include <bits/stdc++.h>

using namespace std;

const int range = 105;

int n, cnt;
// 커브의 자취
bool trace[range][range];

// 커브 그리기
// 0세대부터 시작해서 g세대까지 그려주기
void draw_curve(int x, int y, int d, int g) {
  int nx, ny;
  vector<int> dir;
  int dx[] = {0, -1, 0, 1};
  int dy[] = {1, 0, -1, 0};
  dir.push_back(d);
  for (int i = 0; i < g; ++i) {
    for (int j = dir.size() - 1; j >= 0; --j) dir.push_back((dir[j] + 1) % 4);
  }
  trace[x][y] = true;
  for (int d : dir) {
    nx = x + dx[d];
    ny = y + dy[d];
    trace[nx][ny] = true;
    x = nx;
    y = ny;
  }
}

// 정사각형 세기
// 정사각형 모양의 인접 네칸이 모두 true인지 체크
void count_square() {
  int dx[] = {0, 1, 0, 1};
  int dy[] = {0, 0, 1, 1};
  for (int i = 0; i < range - 1; ++i)
    for (int j = 0; j < range - 1; ++j) {
      bool is_square = true;
      for (int dir = 0; dir < 4; ++dir)
        is_square &= trace[i + dx[dir]][j + dy[dir]];
      if (is_square) cnt += 1;
    }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y, d, g;
    // y와 x 거꾸로 받기, 원래 쓰던대로 쓰기위함
    cin >> y >> x >> d >> g;
    draw_curve(x, y, d, g);
  }
  count_square();
  cout << cnt;
  return 0;
}

/**
 * 틀린 이유
 * 2세대와 3세대에서 방향이 바뀌는 패턴이 달랐다
 * 2세대에선 <-이 ^로 바뀌는데 3세대에선 v로 바뀌기 때문에 끝점을 기준으로 90도
 * 대칭이동하는 수학공식이 필요한 줄 알았음.. 좀 더 고민해보다가 규칙을 못찾고
 * 결국에는 정답을 참고했음
 * 이전 세대를 구성하는 방향(dir)의 역순으로 (dir+ 1) % 4이 다음 세대를 구성하는
 * 방향이 되는 규칙이 있었음
 *
 */