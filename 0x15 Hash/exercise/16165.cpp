#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  unordered_map<string, vector<string>> t2n;
  unordered_map<string, string> n2t;
  while (n--) {
    string team, name;
    int member;
    cin >> team >> member;
    for (int i = 0; i < member; ++i) {
      cin >> name;
      t2n[team].push_back(name);
      n2t[name] = team;
    }
    sort(t2n[team].begin(), t2n[team].end());
  }
  while (m--) {
    string query;
    int quiz;
    cin >> query >> quiz;
    switch (quiz) {
      case 0:
        for (auto name : t2n[query]) cout << name << '\n';
        break;
      case 1:
        cout << n2t[query] << '\n';
        break;
    }
  }
  return 0;
}