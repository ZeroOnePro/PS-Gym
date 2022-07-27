#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> a = {1, 2, 3, 4, 5};
  vector<int> b;
  // deep copy
  b = a;
  b[3] = 6;
  cout << a[3] << ' ' << b[3] << '\n';

  int c[5] = {1, 2, 3, 4, 5};
  int* d;

  d = c;

  d[3] = 6;
  cout << c[3] << ' ' << d[3] << '\n';

  return 0;
}