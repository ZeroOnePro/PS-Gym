#include <bits/stdc++.h>

using namespace std;

#define pbi pair<bool, int>

int k;
deque<int> gear[4];

// 톱니 x를 반시계 or 시계 회전
// dir 1: 시계, -1: 반시계
void rotate(int dir, int x) {
  if (dir == 1) {
    gear[x].push_front(gear[x].back());
    gear[x].pop_back();
  } else {
    gear[x].push_back(gear[x].front());
    gear[x].pop_front();
  }
}

void left_check(int x, pbi res[]) {
  int cur = x;
  for (int st = x - 1; st >= 0; --st) {
    if (gear[cur][6] != gear[st][2]) {
      res[st] = {true, -res[cur].second};
      cur = st;
    } else
      break;
  }
}

void right_check(int x, pbi res[]) {
  int cur = x;
  for (int st = x + 1; st <= 3; ++st) {
    if (gear[cur][2] != gear[st][6]) {
      res[st] = {true, -res[cur].second};
      cur = st;
    } else
      break;
  }
}

// 톱니 x가 dir로 돌았을 때 영향을 받는 톱니들 구하기
void check(int dir, int x) {
  // (회전 여부, 회전 방향)
  pbi res[4];
  res[x] = {true, dir};
  // 중간 톱니
  // 자신의 좌우로 연속적 검사
  if (x == 1 || x == 2) {
    left_check(x, res);
    right_check(x, res);
  }
  // 시작 톱니
  else if (x == 0)
    right_check(x, res);
  // 마지막 톱니
  else
    left_check(x, res);
  // 결과에 따라 회전시키기
  for (int i = 0; i < 4; ++i)
    if (res[i].first) rotate(res[i].second, i);
}

// 점수 계산
// 문제에 룰 참조
int clac_score() {
  int score = 0;
  for (int i = 0; i < 4; ++i)
    if (gear[i][0] == 1) score += (1 << i);
  return score;
}

void print_gear() {
  cout << '\n';
  for (int i = 0; i < 4; ++i) {
    for (int j : gear[i]) cout << j << ' ';
    cout << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 0; i < 4; ++i) {
    string s;
    cin >> s;
    for (char ch : s) gear[i].push_back(ch - '0');
  }
  cin >> k;
  while (k--) {
    int x, dir;
    cin >> x >> dir;
    x -= 1;
    check(dir, x);
    // print_gear();
  }
  cout << clac_score();
  return 0;
}