#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, ans = 1;
    string cloth, type;
    unordered_map<string, int> mm;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> cloth >> type;
      mm[type] += 1;
    }
    for (auto m : mm) ans *= m.second + 1;
    cout << ans - 1 << '\n';
  }
  return 0;
}