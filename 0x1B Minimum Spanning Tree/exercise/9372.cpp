#include <bits/stdc++.h>

using namespace std;

int tc, n, m;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
      int from, to;
      cin >> from >> to;
    }
    cout << n - 1 << '\n';
  }
  return 0;
}