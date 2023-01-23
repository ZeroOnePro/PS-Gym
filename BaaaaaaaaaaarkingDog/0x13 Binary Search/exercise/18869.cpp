#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
int planet[102][10'002];

void transform(int* a) {
  vector<int> tmp(a, a + n);
  sort(tmp.begin(), tmp.end());
  for (int i = 0; i < n; ++i)
    a[i] = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> m >> n;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j) cin >> planet[i][j];
  for (int i = 0; i < m; ++i) transform(planet[i]);
  for (int i = 0; i < m - 1; ++i)
    for (int j = i + 1; j < m; ++j) {
      bool eql = true;
      for (int k = 0; k < n; ++k)
        if (planet[i][k] != planet[j][k]) eql = false;
      if (eql) cnt += 1;
    }
  cout << cnt;
  return 0;
}