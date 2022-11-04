#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k, l;
  cin >> k >> l;
  unordered_map<string, int> m;
  for (int i = 0; i < l; ++i) {
    string num;
    cin >> num;
    m[num] = i;
  }
  vector<pair<string, int>> s(m.begin(), m.end());
  sort(s.begin(), s.end(),
       [&s](auto a, auto b) { return a.second < b.second; });
  for (int i = 0; i < min(k, (int)s.size()); ++i) cout << s[i].first << '\n';
  return 0;
}