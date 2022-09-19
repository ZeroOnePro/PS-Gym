#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, c;
  cin >> n >> c;
  // (빈도, 숫자)
  vector<pair<int, int>> msg;
  for (int i = 0; i < n; ++i) {
    int in;
    cin >> in;
    bool is_exist = false;
    for (auto& m : msg) {
      if (m.second == in) {
        m.first += 1;
        is_exist = true;
      }
    }
    if (!is_exist) msg.push_back({1, in});
  }
  stable_sort(msg.begin(), msg.end(),
              [](auto a, auto b) { return a.first > b.first; });
  for (auto m : msg)
    while (m.first--) cout << m.second << ' ';
  return 0;
}