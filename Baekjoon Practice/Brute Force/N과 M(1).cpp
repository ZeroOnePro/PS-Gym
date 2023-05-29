#include <iostream>

using namespace std;

int c[10];
int a[10];

void go(int index, int n, int m) {
  if (index == m) {
    for (int i = 0; i < m; ++i) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
  for (int i = 1; i <= n; ++i) {
    if (c[i])
      continue;
    c[i] = 1;
    a[index] = i;
    go(index + 1, n, m);
    c[i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  go(0, n, m);
  return 0;
}