#include <iostream>

using namespace std;

int c[10];
int a[10];
// order
/*
void go(int index,int start ,int n, int m) {
        if (index == m) {
                for (int i = 0; i < m; ++i) {
                        cout << a[i] << ' ';
                }
                cout << '\n';
        }
        for (int i = start; i <= n; ++i) {
                a[index] = i;
                go(index + 1,i + 1, n,  m);
        }
}
*/
// select
void go(int index, int selected, int n, int m) {
  if (selected == m) {
    for (int i = 0; i < m; ++i) {
      cout << a[i] << ' ';
    }
    cout << '\n';
    return;
  }
  if (index > n)
    return;
  a[selected] = index;
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
  // order
  // go(0,1,n, m);
  // selected
  go(1, 0, n, m);
  return 0;
}