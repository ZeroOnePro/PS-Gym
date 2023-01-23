#include <bits/stdc++.h>

using namespace std;

int n, m;

int bx[4] = {1, 1, 2, 2};
int by[4] = {1, 2, 2, 1};

pair<int, int> p_walk(int n, int walk) {
  // 제일 작은 문제 크기는 2
  if (n == 2) return {bx[walk - 1], by[walk - 1]};

  // step이 어느 사분면에 있는지 판단 후 전단계 문제로 줄이기
  int pn = n >> 1;
  int pw = pn * pn;

  if (walk <= pw) {
    auto [x, y] = p_walk(pn, walk);
    return {y, x};
  } else if (walk <= 2 * pw) {
    auto [x, y] = p_walk(pn, walk - pw);
    return {x, y + pn};
  } else if (walk <= 3 * pw) {
    auto [x, y] = p_walk(pn, walk - 2 * pw);
    return {x + pn, y + pn};
  } else {
    auto [x, y] = p_walk(pn, walk - 3 * pw);
    return {n - y + 1, pn - x + 1};
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  auto [x, y] = p_walk(n, m);
  cout << x << ' ' << y << '\n';
  return 0;
}