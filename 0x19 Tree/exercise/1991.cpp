#include <bits/stdc++.h>

using namespace std;

int lc[27], rc[27];

void preorder_traversal(int cur, string& result) {
  result += cur + 'A' - 1;
  if (lc[cur] != 0) preorder_traversal(lc[cur], result);
  if (rc[cur] != 0) preorder_traversal(rc[cur], result);
}

void inorder_traversal(int cur, string& result) {
  if (lc[cur] != 0) inorder_traversal(lc[cur], result);
  result += cur + 'A' - 1;
  if (rc[cur] != 0) inorder_traversal(rc[cur], result);
}

void postorder_traversal(int cur, string& result) {
  if (lc[cur] != 0) postorder_traversal(lc[cur], result);
  if (rc[cur] != 0) postorder_traversal(rc[cur], result);
  result += cur + 'A' - 1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    char cur, left, right;
    cin >> cur >> left >> right;
    if (left != '.') lc[cur - 'A' + 1] = left - 'A' + 1;
    if (right != '.') rc[cur - 'A' + 1] = right - 'A' + 1;
  }
  string preorder = "", inorder = "", postorder = "";
  preorder_traversal(1, preorder);
  inorder_traversal(1, inorder);
  postorder_traversal(1, postorder);
  cout << preorder + '\n' + inorder + '\n' + postorder;
  return 0;
}