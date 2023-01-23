#include <bits/stdc++.h>

using namespace std;

const int range = 1e4 + 5;

int n, col, root;
int lc[range];
int rc[range];
pair<int, int> d2w[range];

void inorder(int cur, int depth) {
  if (lc[cur] != -1) inorder(lc[cur], depth + 1);
  // 레벨에 왼쪽 자식이나 오른쪽 자식이 처음 나타나거나
  // 새로운 최소 열 번호나 최대 열 번호가 나타나면 갱신
  col += 1;
  auto &[ln, rn] = d2w[depth];
  if (ln == 0 || col < ln) ln = col;
  if (rn == 0 || rn < col) rn = col;
  if (rc[cur] != -1) inorder(rc[cur], depth + 1);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  vector<bool> is_root(n + 1, true);
  for (int i = 0; i < n; ++i) {
    int p, l, r;
    cin >> p >> l >> r;
    lc[p] = l;
    rc[p] = r;
    if (l != -1) is_root[l] = false;
    if (r != -1) is_root[r] = false;
  }
  for (int i = 1; i <= n; ++i)
    if (is_root[i]) root = i;
  inorder(root, 1);
  int mx_width = 0, depth = 1;
  for (int d = 1; d <= n; ++d) {
    auto [ln, rn] = d2w[d];
    if (ln + rn == 0) break;
    int width = rn - ln + 1;
    if (width > mx_width) {
      mx_width = width;
      depth = d;
    }
  }
  cout << depth << ' ' << mx_width;
  return 0;
}