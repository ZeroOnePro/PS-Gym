#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string in;
  cin >> in;
  vector<string> suffix;
  int len = in.length();
  for (int i = 0; i < len; ++i) suffix.push_back(in.substr(i, len));
  sort(suffix.begin(), suffix.end());
  for (auto s : suffix) cout << s << '\n';
  return 0;
}