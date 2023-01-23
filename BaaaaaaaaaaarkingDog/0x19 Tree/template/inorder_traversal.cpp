#include <bits/stdc++.h>

using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

void inorder_traversal(int cur) {
  if (lc[cur] != 0) inorder_traversal(lc[cur]);
  cout << cur << ' ';
  if (rc[cur] != 0) inorder_traversal(rc[cur]);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  inorder_traversal(1);
  return 0;
}