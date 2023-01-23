#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pi2 pair<int, int>

inline bool leq(vector<pi2>& v, int i) { return v[i - 1].x == v[i].x; }
inline bool req(vector<pi2>& v, int i) { return v[i + 1].x == v[i].x; }
inline int diff(vector<pi2>& v, int i, char dir) {
  if (dir == 'l') return v[i].y - v[i - 1].y;
  return v[i + 1].y - v[i].y;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pi2> point(n);
  for (int i = 0; i < n; ++i) {
    int loc, color;
    cin >> loc >> color;
    point[i] = {color, loc};
  }
  sort(point.begin(), point.end());
  int len_sum = 0;
  for (int i = 0; i < n; ++i) {
    // 같은 색이면, 화살표가 생긴다
    if (i == 0 || req(point, i) && !leq(point, i))
      len_sum += diff(point, i, 'r');
    else if (i == n - 1 || leq(point, i) && !req(point, i))
      len_sum += diff(point, i, 'l');
    else if (leq(point, i) && req(point, i))
      len_sum += min(diff(point, i, 'l'), diff(point, i, 'r'));
  }
  cout << len_sum;
  return 0;
}