#include <bits/stdc++.h>

using namespace std;

// 상우하좌
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = 4;
  int x = 0, y = 0, d = 0;
  int nx = (x + dx[d] + n) % n;
  int ny = (y + dy[d] + n) % n;
  cout << nx << ' ' << ny << '\n';
  return 0;
}