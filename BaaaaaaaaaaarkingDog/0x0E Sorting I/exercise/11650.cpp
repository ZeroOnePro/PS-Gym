#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, int>> coord(n);
  for (auto& c : coord) cin >> c.x >> c.y;
  sort(coord.begin(), coord.end());
  for (auto c : coord) cout << c.x << ' ' << c.y << '\n';
  return 0;
}