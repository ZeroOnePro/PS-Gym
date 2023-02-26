#include <bits/stdc++.h>

using namespace std;

int n, k, cnt;

// 컨베이어 벨트의 각 칸
typedef struct b {
  int rn;  // 벨트 위의 로봇 번호, 없으면 -1로 정의
  int d;   // 내구도
} b;

deque<b> belt;
vector<int> robot;  // 벨트 위에서 로봇의 위치 나타낸다, 벨트 위에서 내려진
                    // 로봇은 -1로 표기

// 벨트 위에(0번에) 로봇 놓기
void in_robot() {
  auto [rn, d] = belt[0];
  if (d == 0) return;
  belt[0] = {cnt, d};
  robot[cnt] = 0;
  cnt += 1;
}

void out_robot() {
  auto [rn, d] = belt[n - 1];
  // n-1번 칸에 로봇이 있음
  if (rn != -1) {
    belt[n - 1].rn = -1;
    robot[rn] = -1;
  }
}

// 로봇 이동
void move_robot() {
  for (int i = 0; i < robot.size(); ++i) {
    if (belt[robot[i] + 1].rn != -1 && belt[robot[i] + 1].d >= 1 &&
        robot[i] != -1) {
      robot[i] += 1;
      belt[robot[i]].d -= 1;
      belt[robot[i]].rn = i;
    }
  }
}

// 벨트 회전
void rotate() {
  belt.push_front(belt.back());
  belt.pop_back();
}

// 내구도 검사
// 내구도 0인 칸이 k개 이상인지
bool check() {
  int cnt = 0;
  for (auto [rn, d] : belt) cnt += (d == 0);
  return cnt < k;
}

void simulation() {
  int step = 1;
  while (check()) {
    rotate();
    out_robot();
    move_robot();
    out_robot();
    in_robot();
    step += 1;
  }
  cout << step;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 0; i < 2 * n; ++i) {
    int d;
    cin >> d;
    belt.push_back({-1, d});
  }
  simulation();
  return 0;
}