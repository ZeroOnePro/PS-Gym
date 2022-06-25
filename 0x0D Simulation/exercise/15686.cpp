#include <bits/stdc++.h>

using namespace std;

enum entity { HOME = 1, CHICKEN = 2 };

int n, m;
int city[52][52];
vector<pair<int, int>> homes;
vector<pair<int, int>> chickens;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> city[i][j];
      if (city[i][j] == HOME) homes.push_back({i, j});
      if (city[i][j] == CHICKEN) chickens.push_back({i, j});
    }
  }
  vector<int> cs(chickens.size(), 1);
  fill(cs.begin(), cs.begin() + chickens.size() - m, 0);
  int min_dist = INT_MAX;
  do {
    int tmp = 0;
    for (auto home : homes) {
      int dist = INT_MAX;
      for (int i = 0; i < chickens.size(); ++i) {
        if (cs[i] == 0) continue;
        int cx, cy, hx, hy;
        tie(cx, cy) = chickens[i];
        tie(hx, hy) = home;
        dist = min(dist, abs(cx - hx) + abs(cy - hy));
      }
      tmp += dist;
    }
    min_dist = min(min_dist, tmp);
  } while (next_permutation(cs.begin(), cs.end()));
  cout << min_dist;
  return 0;
}