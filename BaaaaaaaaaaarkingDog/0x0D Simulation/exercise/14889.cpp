#include <bits/stdc++.h>

using namespace std;

const int range = 25;

int n, mn = INT_MAX;
int team[range];
int s[range][range];

int clac_team_ablity(vector<int> v) {
  int sum = 0, sz = n / 2;
  for (int i = 0; i < sz - 1; ++i)
    for (int j = i + 1; j < sz; ++j) {
      int p1 = v[i], p2 = v[j];
      sum += s[p1][p2] + s[p2][p1];
    }
  return sum;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> s[i][j];
  fill(team + n / 2, team + n, 1);
  do {
    vector<int> start_team, link_team;
    for (int i = 0; i < n; ++i) {
      if (team[i] == 0)
        start_team.push_back(i);
      else
        link_team.push_back(i);
    }
    int s_sum = clac_team_ablity(start_team);
    int l_sum = clac_team_ablity(link_team);
    mn = min(mn, abs(s_sum - l_sum));
  } while (next_permutation(team, team + n));
  cout << mn;
  return 0;
}