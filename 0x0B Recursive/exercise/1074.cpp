#include <bits/stdc++.h>

using namespace std;

// 재귀 구현 순서
// 1. 함수 정의 => 인자랑 기능
// 2. base condition 설정
// 3. 재귀 식 수립 => 규칙 찾기
int z_traversal(int r, int c, int n) {
  if (n == 0) return 0;
  int half = 1 << (n - 1);
  int width = half * half;
  // 1, 2, 3, 4는 4등분 후의 사각형 중 방문 순서를 나타냄
  // 2, 3, 4의 경우, 1의 계산 값으로 방문 순서를 알 수 있음
  // 따라서 2, 3, 4의 경우 1을 이용해야하기 때문에 각 좌표에서 1로 좌표를 각
  // 재귀호출의 r과 c의 값이 된다.
  if (r < half && c < half) return z_traversal(r, c, n - 1);  // 1
  if (r < half && c >= half)
    return width + z_traversal(r, c - half, n - 1);  // 2
  if (r >= half && c < half)
    return 2 * width + z_traversal(r - half, c, n - 1);       // 3
  return 3 * width + z_traversal(r - half, c - half, n - 1);  // 4
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, r, c;
  cin >> n >> r >> c;
  cout << z_traversal(r, c, n);
  return 0;
}