#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> modules(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> modules[i];
  }
  sort(modules.begin(), modules.end());
  int m;
  cin >> m;
  int target;
  string ans = "";
  for (int i = 0; i < m; ++i) {
    cin >> target;
    binary_search(modules.begin(), modules.end(), target) ? ans += "yse "
                                                          : ans += "no ";
  }
  cout << ans << '\n';
  return 0;
}