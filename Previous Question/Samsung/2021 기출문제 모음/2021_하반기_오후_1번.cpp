#include <bits/stdc++.h>

using namespace std;

#define EGG 0
#define MOVING 1
#define DEAD 2

int m, t;

struct packman {
  int x;
  int y;
} packman;

typedef struct monster {
  int d;
  int x;
  int y;
  int age;
} monster;

// 알 상태, 이동 중 상태, 죽은 상태의 몬스터를 각각 관리
vector<monster> egg, live, dead;

int d[4][4];  // 격자에서 죽은 몬스터 수 저장
int l[4][4];  // 격자에서 살아있는 몬스터 수 저장

//  순서대로 ↑, ↖, ←, ↙, ↓, ↘, →, ↗ 를 의미합니다.
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
// 팩맨 이동 우선순위 상좌하우
int ddx[] = {-1, 0, 1, 0};
int ddy[] = {0, -1, 0, 1};

bool OOB(int x, int y) { return x < 0 || x >= 4 || y < 0 || y >= 4; }

/*
==입력==
첫 줄에는 몬스터의 마리 수 m과 진행되는 턴의 수 t이 주어집니다. 두번째 줄에는
팩맨의 격자에서의 초기 위치 r, c가 주어집니다. r은 격자의 몇번째 행인지, c는
격자의 몇번째 열인지를 나타냅니다. 그 다음 줄부터 m개의 줄에는 몬스터의 위치 r,
c와 방향 정보 d가 주어집니다. r과 c는 각각 격자의 몇번째 행인지, c는 격자의
몇번째 열인지를 의미하고, 방향 d는 1부터 순서대로 ↑, ↖, ←, ↙, ↓, ↘, →, ↗ 를
의미합니다.

1 ≤ m ≤ 10
1 ≤ t ≤ 25
몬스터의 초기 위치와 팩맨의 초기 위치는 같을 수도 있습니다.
턴이 진행되는 동안 살아있는 몬스터의 수가 100만개가 넘는 입력은 주어지지
않는다고 가정해도 좋습니다.
*/
void input() {
  cin >> m >> t;
  cin >> packman.x >> packman.y;
  packman.x -= 1;
  packman.y -= 1;
  for (int i = 0; i < m; ++i) {
    int x, y, d;
    cin >> x >> y >> d;
    x -= 1;
    y -= 1;
    d -= 1;
    live.push_back({d, x, y, 3});
    l[x][y] += 1;
  }
}

/*
1. 몬스터 복제 시도
몬스터는 현재의 위치에서 자신과 같은 방향을 가진 몬스터를 복제하려 합니다. 이때
복제된 몬스터는 아직은 부화되지 않은 상태로 움직이지 못합니다. 그림에서 알의
형태를 띄고 있는 복제된 몬스터는 현재 시점을 기준으로 각 몬스터와 동일한 방향을
지니게 되며, 이후 이 알이 부화할 시 해당 방향을 지닌 채로 깨어나게 됩니다.
*/
void replicate_monster() {
  vector<monster> tmp;
  for (int i = 0; i < live.size(); ++i)
    egg.push_back({live[i].d, live[i].x, live[i].y, live[i].age});
}

/*
2. 몬스터 이동
몬스터는 현재 자신이 가진 방향대로 한 칸 이동합니다. 이때 움직이려는 칸에 몬스터
시체가 있거나, 팩맨이 있는 경우거나 격자를 벗어나는 방향일 경우에는 반시계
방향으로 45도를 회전한 뒤 해당 방향으로 갈 수 있는지 판단합니다. 만약 갈 수
없다면, 가능할 때까지 반시계 방향으로 45도씩 회전하며 해당 방향으로 갈 수
있는지를 확인합니다. 만약 8 방향을 다 돌았는데도 불구하고, 모두 움직일 수
없었다면 해당 몬스터는 움직이지 않습니다.
*/
void move_monster() {
  for (int i = 0; i < live.size(); ++i) {
    for (int j = 0; j < 8; ++j) {
      int nx = live[i].x + dx[(live[i].d + j) % 8];
      int ny = live[i].y + dy[(live[i].d + j) % 8];
      if (OOB(nx, ny) || packman.x == nx && packman.y == ny || d[nx][ny] != 0)
        continue;
      l[live[i].x][live[i].y] -= 1;
      l[nx][ny] += 1;
      live[i].x = nx;
      live[i].y = ny;
      live[i].d = live[i].d + j % 8;
      break;
    }
  }
}

/*
3. 팩맨 이동
팩맨의 이동은 총 3칸을 이동하게 되는데, 각 이동마다 상하좌우의 선택지를 가지게
됩니다. 총 4가지의 방향을 3칸 이동하기 때문에 총 64개의 이동 방법이 존재하는데,
이 중 몬스터를 가장 많이 먹을 수 있는 방향으로 움직이게 됩니다. 만약 가장 많이
먹을 수 있는 방향이 여러개라면 상-좌-하-우(0, 1, 2, 3)의 우선순위를 가지며
우선순위가 높은 순서대로 배열하면 "상상상 - 상상좌 - 상상하 - 상상우 - 상좌상 -
상좌좌 - 상좌하
- ..."과 같이 나타낼 수 있습니다. 이동하는 과정에 격자 바깥을 나가는 경우는
고려하지 않습니다. 예시의 경우에서는 상우우, 우상우, 우우상으로 이동하면 총
2마리의 몬스터를 먹을 수 있기 때문에 이중 우선순위가 제일 높은 상우우 방향으로
움직입니다. 이때 이동할 때 이동하는 칸에 있는 몬스터는 모두 먹어치운 뒤, 그
자리에 몬스터의 시체를 남깁니다. 이때 팩맨은 알은 먹지 않으며, 움직이기 전에
함께 있었던 몬스터도 먹지 않습니다. 즉, 이동하는 과정에 있는 몬스터만 먹습니다.
*/
vector<vector<int>> all_route;
int seq[4];
int num = 0;
void all_case(int cur) {
  if (cur == 3) {
    vector<int> tmp;
    for (int i = 0; i < 3; ++i) tmp.push_back(seq[i]);
    all_route.push_back(tmp);
    return;
  }
  for (int i = 0; i < 4; ++i) {
    seq[cur] = i;
    all_case(cur + 1);
  }
}

void move_packman() {
  // 여기서 몬스터 몇마리 먹을 수 있는지 계산
  int mx = -1, x = -1, y = -1, index = 0;
  for (int i = 0; i < 64; ++i) {
    int sum = 0, nx = packman.x, ny = packman.y;
    int cnt[4][4];
    for (int j = 0; j < 4; ++j) fill(cnt[j], cnt[j] + 4, 0);
    cnt[nx][ny] = l[nx][ny];
    for (int dir = 0; dir < 3; ++dir) {
      nx += ddx[all_route[i][dir]];
      ny += ddy[all_route[i][dir]];
      if (OOB(nx, ny)) {
        sum = 0;
        break;
      }
      if (cnt[nx][ny] == 0) {
        sum += l[nx][ny];
        cnt[nx][ny] = l[nx][ny];
      }
    }
    if (mx < sum) {
      x = nx;
      y = ny;
      mx = sum;
      index = i;
    }
  }

  if (mx == 0) {
    packman.x = x;
    packman.y = y;
    return;
  }

  int nx = packman.x;
  int ny = packman.y;
  // 해당하는 좌표에 해당하는 애들을 제외한 애들은 담은 새로운 배열로 교체
  set<pair<int, int>> route;
  vector<monster> tmp;
  for (int i = 0; i < 3; ++i) {
    nx += ddx[all_route[index][i]];
    ny += ddy[all_route[index][i]];
    route.insert({nx, ny});
    d[nx][ny] += l[nx][ny];
    l[nx][ny] = 0;
  }
  for (auto it = live.begin(); it != live.end(); it++) {
    if (route.find({it->x, it->y}) != route.end())
      dead.push_back({it->d, it->x, it->y, it->age});
    else
      tmp.push_back(*it);
  }
  live = tmp;
  packman.x = x;
  packman.y = y;
}

/*
4. 몬스터 시체 소멸
몬스터의 시체는 총 2턴동안만 유지됩니다. 즉, 시체가 생기고 나면 시체가 소멸되기
까지는 총 두 턴을 필요로 합니다. 현재 예시에는 소멸되는 몬스터가 존재하지
않습니다.
*/
void clean_monster_body() {
  vector<monster> tmp;
  for (auto it = dead.begin(); it != dead.end(); it++) {
    it->age -= 1;
    if (it->age == 0)
      d[it->x][it->y] -= 1;
    else
      tmp.push_back(*it);
  }
  dead = tmp;
}

/*
5. 몬스터 복제 완성
아까 알 형태였던 몬스터가 부화합니다. 처음 복제가 된 몬스터의 방향을 지닌 채로
깨어나게 됩니다.
*/
void hatch_monster() {
  for (int i = 0; i < egg.size(); ++i) {
    live.push_back({egg[i].d, egg[i].x, egg[i].y, egg[i].age});
    l[egg[i].x][egg[i].y] += 1;
  }
  egg.clear();
}

/**
 * 디버깅용 프린트
 */
void print(int turn) {
  cout << "\n===라운드 " << turn << "===\n\n";
  cout << "팩맨 위치: ";
  cout << packman.x << ' ' << packman.y << "\n\n";
  cout << "살아있는 몬스터\n";
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) cout << l[i][j] << ' ';
    cout << '\n';
  }
  cout << '\n';
  cout << "죽은 몬스터\n";
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) cout << d[i][j] << ' ';
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  input();
  all_case(0);
  for (int turn = 1; turn <= t; ++turn) {
    replicate_monster();
    move_monster();
    move_packman();
    clean_monster_body();
    hatch_monster();
  }
  cout << live.size() << '\n';
  return 0;
}