#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

const int n_range = 55;
const int m_range = 15;

enum { HOME = 1, CHIC = 2 };

int n, m, mn = INT_MAX;

int origin[n_range][n_range];
bool is_used[m_range];
int seq[m_range];
vector<pii> h;
vector<pii> c;

// 도시의 치킨 거리 계산하기
// O(2NM)
int clac_dist() {
  int local_dist = 0;
  for (auto [hx, hy] : h) {
    int local_mn = INT_MAX;
    for (int i = 0; i < m; ++i) {
      auto [cx, cy] = c[seq[i]];
      local_mn = min(local_mn, abs(cx - hx) + abs(cy - hy));
    }
    local_dist += local_mn;
  }
  return local_dist;
}

// m개의 치킨집 조합을 뽑는다
// 13C6
void all_case(int cur, int prev) {
  if (cur == m) {
    // 여기서 뽑힌 치킨집들과 집들 사이에 치킨거리 합 구하기
    // for (int i = 0; i < m; ++i) cout << seq[i] << ' ';
    // cout << '\n';
    mn = min(mn, clac_dist());
    return;
  }
  for (int i = 0; i < c.size(); ++i) {
    if (is_used[i]) continue;
    is_used[i] = true;
    seq[cur] = i;
    if (seq[cur] > prev) all_case(cur + 1, seq[cur]);
    is_used[i] = false;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> origin[i][j];
      if (origin[i][j] == HOME)
        h.push_back({i, j});
      else if (origin[i][j] == CHIC)
        c.push_back({i, j});
    }
  all_case(0, -1);
  cout << mn;
  return 0;
}