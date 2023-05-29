#include <algorithm>
#include <iostream>
using namespace std;
int num[10];
int a[10];
bool check[10000];

void go(int index, int n, int m) {
  if (index == m) {
    for (int i = 0; i < m; ++i) {
      cout << a[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (check[num[i]])
      continue;
    a[index] = num[i];
    check[num[i]] = true;
    go(index + 1, n, m);
    check[num[i]] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> num[i];
  }
  sort(num, num + n);
  go(0, n, m);
  return 0;
}