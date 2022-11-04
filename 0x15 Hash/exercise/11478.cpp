#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  unordered_set<string> us;
  cin >> s;
  int len = s.length();
  for (int i = 1; i <= len; ++i)
    for (int j = 0; j < len; ++j) us.insert(s.substr(j, i));
  cout << us.size();
  return 0;
}