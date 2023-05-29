#include <algorithm>
#include <iostream>
using namespace std;
int num[10];
int a[10];

void go(int index, int selected, int n, int m) {
  if (selected == m) {
    for (int i = 0; i < m; ++i) {
      cout << a[i] << ' ';
    }
    cout << '\n';
    return;
  }
  if (index >= n)
    return;
  a[selected] = num[index];
  go(index + 1, selected + 1, n, m);
  a[selected] = 0;
  go(index + 1, selected, n, m);
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
  go(0, 0, n, m);
  return 0;
}