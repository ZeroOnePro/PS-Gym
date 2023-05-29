#include <bits/stdc++.h>

using namespace std;

const int range = 100;

int n;
int elem = 1;
int snail[range][range];
vector<pair<int, int>> spiral_points;

void search_snail() {
  int x = n / 2, y = n / 2;

  snail[x][y] = elem++;

  // 좌 하 우 상
  int dx[] = {0, 1, 0, -1};
  int dy[] = {-1, 0, 1, 0};

  int dir = 0, move = 1;

  while (x || y) {
    // move만큼 이동
    for (int i = 0; i < move; i++) {
      x += dx[dir];
      y += dy[dir];
      snail[x][y] = elem++;
      spiral_points.push_back(make_pair(x, y));
      if (x == 0 && y == 0) break;
    }

    dir = (dir + 1) % 4;
    // 왼쪽이나 오른쪽으로 방향을 틀 경우 이동 횟수 증가
    if (dir == 0 || dir == 2) move += 1;
  }
}

void print() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << setw(2) << snail[i][j] << ' ';
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // n은 무조건 홀수
  cin >> n;
  search_snail();
  print();
  return 0;
}