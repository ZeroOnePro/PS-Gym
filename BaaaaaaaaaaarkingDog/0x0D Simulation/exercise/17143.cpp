#include <bits/stdc++.h>

using namespace std;

const int range = 105;

struct shark {
  int num;  // 상어 번호
  int s;    // 속도
  int z;    // 크기
  int d;    // 방향
  int x;    // 행
  int y;    // 열
} shark[range * range];

struct human {
  int c;    // 현재 위치한 열의 번호
  int sum;  // 잡은 상어 총량
} human;

int r, c, m;
priority_queue<int> w[range]
                     [range];  // 각 격자별로 크기 순으로 상어 저장, 칸에 최대
                               // 1마리만 있을 수 있어서 굳이라는 생각이 들긴함

void input() {
  cin >> r >> c >> m;
  for (int i = 0; i < m; ++i) {
    shark[i].num = i;
    cin >> shark[i].x >> shark[i].y >> shark[i].s >> shark[i].d >> shark[i].z;
    shark[i].d -= 1;
  }
}

// 낚시
// 가장 먼저 발견되는 상어 총량에 더해주기
void fishing(int cur) {
  for (int i = 0; i < r; ++i)
    if (w[i][cur].size() > 0) {
      human.sum += w[i][cur].top();
      break;
    }
}

// i번 상어 이동
// 위치 계산 후 해당 격자 우선순위 큐에 집어넣기 => 잡아먹기 구현 위함
// d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미
// 이동 전 격자의 우선순위 큐에서 꺼내서 이동 후 격자의 우선순위 큐에 넣기
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= r || y >= c; }
void shark_move(int i) {
  // 상어의 속도만큼 이동
  for (int i = 0; i < shark[i].s; ++i) {
    int dir = shark[i].d;
    int x = shark[i].x;
    int y = shark[i].y;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    // 이동 중에 벽을 만나면 방향바꿔주고 1칸 전진
    // 반대 방향 만들어주기 상 0 <-> 하 1, 좌 3 <-> 우 2, 모듈라
    if (OOB(nx, ny)) {
    }
  }
}

// 상어끼리 잡어먹는 행위
// 격자에 여러 마리(우선순위 큐 크기 1초과일 때 제일 큰거 남기고 날리기)
// 누가 날라가는지 확인하기 위해 상어에 번호를 부여하자
void eat_each() {}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}