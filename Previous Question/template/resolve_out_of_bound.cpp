#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x, y, n, p, d;
  cout << "n x n 격자에서 (x, y)를 → ↗ ↑ ↖ ← ↙ ↓ ↘ 방향(0 ~ 7번)으로 p번 이동 "
          "시킨 좌표를 출력합니다\n";
  cout << "격자의 모든 행,열은 각각 끝과 끝이 연결되어 있습니다. 즉 격자 "
          "바깥으로 나가면 마치 지구가 둥근것처럼 반대편으로 돌아옵니다.\n";
  cout << "x, y, n, p, d를 입력해주세요 >> ";
  cin >> x >> y >> n >> p >> d;
  int nx = (x + dx[d] * p + n * p) % n;
  int ny = (y + dy[d] * p + n * p) % n;
  cout << nx << ' ' << ny;
  return 0;
}