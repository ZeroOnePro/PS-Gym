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
  vector<int> v(n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      ans += v[j];
    }
  }
  cout << ans << '\n';
  return 0;
}