#include <bits/stdc++.h>

using namespace std;

// 구현해야할 부분
/*
  1. 방향 경우의 수 만들기
  2. 사각지대 개수 세기
*/

#define EMPTY 0
#define WALL 6
#define MARK 7

int n, m;
int office[10][10];
int copied_office[10][10];  // 각 경우의 수 살펴본 후 마킹 지우는 작업 없애기
                            // 위해 복사본을 사용

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 최대 8개이므로 10개 전까지는 안전 아니면 사이즈줘서 선언해주기
vector<pair<int, int>> cctv;

bool OOB(int x, int y) { return x < 0 or x >= n or y < 0 or y >= m; }

// 방향에 따라 마킹해주기
void mark_blind(int x, int y, int dir) {
  dir %= 4;
  while (true) {
    x += dx[dir];
    y += dy[dir];
    if (OOB(x, y) or copied_office[x][y] == WALL) return;
    if (copied_office[x][y] != EMPTY) continue;
    copied_office[x][y] = MARK;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  int blind = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> office[i][j];
      if (office[i][j] != EMPTY && office[i][j] != WALL) cctv.push_back({i, j});
      if (office[i][j] == EMPTY) blind++;
    }
  }
  int cctvs = (int)cctv.size();
  for (int i = 0; i < (1 << (2 * cctvs)); ++i) {
    copy(*office, *office + 100, *copied_office);
    int cs = i;
    for (int j = 0; j < cctvs; ++j) {
      int dir = cs % 4;
      cs /= 4;
      int x, y;
      tie(x, y) = cctv[j];
      switch (office[x][y]) {
        case 1:
          mark_blind(x, y, dir);
          break;
        case 2:
          mark_blind(x, y, dir);
          mark_blind(x, y, dir + 2);
          break;
        case 3:
          mark_blind(x, y, dir);
          mark_blind(x, y, dir + 1);
          break;
        case 4:
          for (int k = 0; k < 3; ++k) mark_blind(x, y, dir + k);
          break;
        case 5:
          for (int k = 0; k < 4; ++k) mark_blind(x, y, dir + k);
          break;
        default:
          break;
      }
    }
    int cnt = 0;
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        // if문 안쓰고 개수세기, true, false가 각각 1과 0이므로
        cnt += (copied_office[r][c] == EMPTY);
      }
    }
    blind = min(blind, cnt);
  }
  cout << blind;
  return 0;
}