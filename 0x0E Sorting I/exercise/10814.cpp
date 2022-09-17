#include <bits/stdc++.h>

using namespace std;

#define age first
#define name second

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, string>> user(n);
  for (int i = 0; i < n; ++i) cin >> user[i].age >> user[i].name;
  stable_sort(user.begin(), user.end(),
              [&user](auto a, auto b) { return a.age < b.age; });
  for (auto u : user) cout << u.age << ' ' << u.name << '\n';
  return 0;
}