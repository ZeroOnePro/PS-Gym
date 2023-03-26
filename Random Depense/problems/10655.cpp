#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi2;
typedef long long ll;

vector<pi2> point;

ll clac_dist(pi2 p1, pi2 p2) {
  auto [x1, y1] = p1;
  auto [x2, y2] = p2;
  return abs(x1 - x2) + abs(y1 - y2);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  ll dist = 0, ans = LONG_MAX;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    point.push_back({x, y});
    if (i >= 1) dist += clac_dist(point[i], point[i - 1]);
  }
  for (int i = 0; i < n; ++i) {
    if (i == 0 || i == n - 1) continue;
    // i번을 건너뛴다
    ans = min(ans, dist - clac_dist(point[i], point[i - 1]) -
                       clac_dist(point[i + 1], point[i]) +
                       clac_dist(point[i + 1], point[i - 1]));
  }
  cout << ans;
  return 0;
}