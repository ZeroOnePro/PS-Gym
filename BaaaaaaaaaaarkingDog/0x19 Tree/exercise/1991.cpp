#include <bits/stdc++.h>

using namespace std;

int lc[27], rc[27];

void traversal(int cur, string order, string& result) {
  if (order == "pre") result += cur + 'A' - 1;
  if (lc[cur] != 0) traversal(lc[cur], order, result);
  if (order == "in") result += cur + 'A' - 1;
  if (rc[cur] != 0) traversal(rc[cur], order, result);
  if (order == "post") result += cur + 'A' - 1;
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
  traversal(1, "pre", preorder);
  traversal(1, "in", inorder);
  traversal(1, "post", postorder);
  cout << preorder + '\n' + inorder + '\n' + postorder;
  return 0;
}