#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = 5;
  vector<int> a;
  vector<int> b(n);
  for (int i = 1; i <= n; ++i) {
    a.push_back(i);
    b[i - 1] = i;
  }
  for (int i : a) {
    cout << i << ' ';
  }
  // cout << a.size() << ' ' << b.size() << '\n';
  return 0;
}