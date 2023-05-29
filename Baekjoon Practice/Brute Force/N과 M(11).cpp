#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int num[10];
int a[10];

vector<vector<int>> d;

void go(int index, int n, int m) {
  if (index == m) {
    vector<int> tmp;
    for (int i = 0; i < m; ++i) {
      tmp.push_back(num[a[i]]);
    }
    d.push_back(tmp);
    return;
  }
  for (int i = 0; i < n; ++i) {
    a[index] = i;
    go(index + 1, n, m);
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
  sort(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());
  for (auto &v : d) {
    for (int i = 0; i < m; ++i) {
      cout << v[i];
      if (i != m - 1) {
        cout << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}