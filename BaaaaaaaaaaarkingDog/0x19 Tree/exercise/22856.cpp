#include <bits/stdc++.h>

using namespace std;

const int range = 1e5 + 5;

int n, mov, ans;

int lc[range];
int rc[range];

// mov는 중의 순위의 마지막 방문지점에 도달하고나서 루트까지 되돌아오므로
// 마지막 정점에서 루트까지 올라오는 거리까지 더해지게되어 이를 빼줘야한다
void inorder_traversal(int cur) {
  if (lc[cur] > 0) {
    mov += 1;  // 진입
    inorder_traversal(lc[cur]);
    mov += 1;  // 되돌아 나올 때
  }
  ans = mov;
  if (rc[cur] > 0) {
    mov += 1;  // 진입
    inorder_traversal(rc[cur]);
    mov += 1;  // 되돌아 나올 때
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int p, l, r;
    cin >> p >> l >> r;
    lc[p] = l;
    rc[p] = r;
  }
  inorder_traversal(1);
  cout << ans;
  return 0;
}