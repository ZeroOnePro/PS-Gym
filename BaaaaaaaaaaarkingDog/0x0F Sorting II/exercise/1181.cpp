#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<string> word(n);
  for (auto& w : word) cin >> w;
  sort(word.begin(), word.end(), [&word](auto a, auto b) {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
  });
  for (int i = 0; i < n; ++i) {
    if (i == 0) cout << word[i] << '\n';
    if (i > 0 && word[i] != word[i - 1]) cout << word[i] << '\n';
  }
  return 0;
}