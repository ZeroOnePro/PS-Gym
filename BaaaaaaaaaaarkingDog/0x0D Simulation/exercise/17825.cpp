#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi2;

// 칸에 있는 말도 저장할 필요 있음
struct point {
  int score;
  int color;        // 0은 빨강, 1은 파랑
  int id;           // 칸 번호
  vector<pi2> nxt;  // (다음 칸 id, 화살표 색)
};

struct player {
  int id;     // 플레이어 번호
  int p_id;   // 현재 위치한 칸의 위치
  int score;  // 누적 점수
};

vector<int> dice(10);
vector<point> board(33);
vector<player> play(10);
int mx = -1;

void print_board() {
  for (auto [score, color, id, nxt] : board) {
    cout << id << ' ' << score << ": ";
    for (auto [id, color] : nxt) cout << "(" << id << ", " << color << "), ";
    cout << '\n';
  }
}

void input() {
  for (auto& pt : dice) cin >> pt;
}

void init() {
  for (int i = 0; i < 4; ++i) play[i] = {i, 0, 0};
}

void create_game() {
  board[0] = {0, 0, 0, {{1, 0}}};  // 시작점
  for (int id = 1; id <= 20; ++id) {
    int color = id % 5 == 0 && id != 20 ? 1 : 0;
    int nxt = id != 20 ? id + 1 : 32;
    board[id] = {id * 2, color, id, {{nxt, 0}}};
  }
  // 10에서 파란화살표로 분기
  for (int id = 21; id <= 23; ++id) {
    int nxt = id != 23 ? id + 1 : 29;  // 19의 nxt 25(id = 29)로 변경해야함
    board[id] = {13 + 3 * (id - 21), 0, id, {{nxt, 0}}};
  }
  // 20에서 파란화살표로 분기
  for (int id = 24; id <= 25; ++id) {
    int nxt = id == 24 ? id + 1 : 29;  // 24의 nxt 25(id = 29)로 변경해야함
    board[id] = {22 + 2 * (id - 24), 0, id, {{nxt, 0}}};
  }
  // 30에서 파란화살표로 분기
  for (int id = 26; id <= 28; ++id) {
    int nxt = id != 28 ? id + 1 : 29;  // 26의 nxt 25(id = 29)로 변경해야함
    board[id] = {28 - (id - 26), 0, id, {{nxt, 0}}};
  }
  // 25에서 40으로 가는 맵의 중앙
  for (int id = 29; id <= 31; ++id) {
    int nxt = id != 31 ? id + 1 : 20;  // 35의 nxt 40(id=20)으로 변경해야함
    board[id] = {25 + 5 * (id - 29), 0, id, {{nxt, 0}}};
  }
  board[32] = {0, 0, 32, {}};  // 도착점
  // 파란 화살표 추가
  // 10(id=5) -> 13(id=21)
  board[5].nxt.push_back({21, 1});
  // 20(id=10) -> 22(id=24)
  board[10].nxt.push_back({24, 1});
  // 30(id=15) -> 28(id=25)
  board[15].nxt.push_back({26, 1});

  // 플레이어 생성
  init();
}

bool move(int d, int p) {
  // p번 플레이어가 d만큼 이동한다
  int cur = play[p].p_id;
  if (cur == 32) return true;
  // 빨간 칸에서 시작하는지 파란 칸에서 시작하는지 구분할 필요 있음
  // 빨간 칸에서 시작
  if (board[cur].color == 0) {
    for (int i = 0; i < d; ++i)
      for (auto [id, color] : board[cur].nxt)
        if (color == 0) cur = id;
  }
  // 파란 칸에서 시작
  else {
    for (auto [id, color] : board[cur].nxt)
      if (color == 1) cur = id;
    // 파란 화살표 타고 이동한 후는 빨간 화살표로 이동과 같음
    for (int i = 1; i < d; ++i)
      for (auto [id, color] : board[cur].nxt)
        if (color == 0) cur = id;
  }
  // 만약 이동한 칸에 다른 말이 있으면 갱신 하지 말기
  for (int i = 0; i < 4; ++i) {
    if (i == p) continue;
    if (play[i].p_id == cur && cur != 32) return false;
  }
  play[p].p_id = cur;
  play[p].score += board[cur].score;
  return true;
}

// 4^10 가지의 중복 순열
int seq[15];
void all_case(int cur) {
  if (cur == 10) {
    bool res = true;
    for (int i = 0; i < 10; ++i) res &= move(dice[i], seq[i]);
    // 점수 계산 후 갱신
    if (res) {
      int sum = 0;
      for (int i = 0; i < 4; ++i) sum += play[i].score;
      mx = max(mx, sum);
    }
    init();
    return;
  }
  for (int i = 0; i < 4; ++i) {
    seq[cur] = i;
    all_case(cur + 1);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  create_game();
  all_case(0);
  cout << mx;
  return 0;
}