#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s, e, q;
  cin >> s >> e >> q;
  unordered_map<string, pair<bool, bool>> log;
  while (!cin.eof()) {
    string time, id;
    cin >> time >> id;
    if ("00:00" <= time && s >= time)
      log[id].first = true;
    else if (e <= time && q >= time)
      log[id].second = true;
  }
  int ans = 0;
  for (auto [id, record] : log)
    if (record.first && record.second) ans += 1;
  cout << ans;
  return 0;
}