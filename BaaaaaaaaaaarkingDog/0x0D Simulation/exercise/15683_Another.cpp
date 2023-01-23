#include <bits/stdc++.h>

using namespace std;

const int range = 10;

int n, m, k;

enum { EMPTY = 0, WALL = 6, MARK = 10 };

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int office[range][range];    // 입력 받는 사무실 상태
int m_office[range][range];  // 마킹 하는 사무실 상태
int seq[range];              // 방향 조합
vector<pair<int, int>> st;   // cctv 시작 위치
int blind;  // cctv가 없는 경우도 있다, 그래서 이 경우도 고려해주기 위해
            // 사각지대의 개수를 센다

// 맵을 벗어났는지 검사
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }

// 마킹
// 벽 통과 못함
// 빈 칸 통과 가능
// cctv는 서로를 통과 할 수 있음
void mark(int x, int y, int dir) {
  dir %= 4;
  while (true) {
    x += dx[dir];
    y += dy[dir];
    if (OOB(x, y) || m_office[x][y] == WALL) return;
    if (m_office[x][y] != EMPTY) continue;
    m_office[x][y] = MARK;
  }
}

// 마킹 후 사각지대의 개수 검사
// 이전 케이스보다 사각지대가 줄어들면 갱신
void check() {
  copy(*office, *office + 100, *m_office);
  for (int i = 0; i < k; ++i) {
    auto [x, y] = st[i];
    int dir = seq[i];
    switch (office[x][y]) {
      // 1번 cctv
      case 1:
        mark(x, y, dir);
        break;
      // 2번 cctv
      case 2:
        mark(x, y, dir);
        mark(x, y, dir + 2);
        break;
      // 3번 cctv
      case 3:
        mark(x, y, dir);
        mark(x, y, dir + 1);
        break;
        // 4번 cctv
      case 4:
        mark(x, y, dir);
        mark(x, y, dir + 1);
        mark(x, y, dir + 2);
        break;
      // 5번 cctv
      case 5:
        mark(x, y, dir);
        mark(x, y, dir + 1);
        mark(x, y, dir + 2);
        mark(x, y, dir + 3);
        break;
      default:
        break;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cnt += (m_office[i][j] == EMPTY);
  blind = min(blind, cnt);
}

// 방향 경우의 수 조합 백트래킹으로 생성
void case_all(int cur) {
  if (cur == k) {
    // 여기서 만들어진 방향에 따라 각 CCTV에 대해 마킹해주면 됨
    check();
    return;
  }
  for (int i = 0; i <= 4; ++i) {
    seq[cur] = i;
    case_all(cur + 1);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> office[i][j];
      if (office[i][j] == EMPTY) blind += 1;
      if (office[i][j] != EMPTY && office[i][j] != WALL) {
        st.push_back({i, j});
        k += 1;
      }
    }
  case_all(0);
  cout << blind;
  return 0;
}