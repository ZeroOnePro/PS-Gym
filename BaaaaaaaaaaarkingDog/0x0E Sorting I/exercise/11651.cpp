#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, int>> coord(n);
  for (auto& c : coord) cin >> c.y >> c.x;
  sort(coord.begin(), coord.end());
  for (auto c : coord) cout << c.y << ' ' << c.x << '\n';
  return 0;
}