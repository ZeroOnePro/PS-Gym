#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a, b;
  set<int> diff;
  for (int i = 0; i < n; ++i) {
    int in;
    cin >> in;
    a.push_back(in);
  }
  for (int i = 0; i < m; ++i) {
    int in;
    cin >> in;
    b.push_back(in);
  }
  sort(b.begin(), b.end());
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (binary_search(b.begin(), b.end(), a[i])) {
      cnt += 1;
      continue;
    }
    diff.insert(a[i]);
  }
  if (cnt == n)
    cout << 0;
  else {
    cout << n - cnt << '\n';
    for (int i : diff) cout << i << ' ';
  }
  return 0;
}