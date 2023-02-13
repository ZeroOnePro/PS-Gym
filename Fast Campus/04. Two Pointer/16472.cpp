#include <bits/stdc++.h>

using namespace std;

int n, ans, kind;
string s;
vector<int> cnt(26);

void add(char ch) {
  cnt[ch - 'a'] += 1;
  // 새로 추가된 수면 1일 것이다
  if (cnt[ch - 'a'] == 1) kind += 1;
}

void erase(char ch) {
  cnt[ch - 'a'] -= 1;
  if (cnt[ch - 'a'] == 0) kind -= 1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> s;
  int len = s.length();
  for (int l = 0, r = 0; r < len; ++r) {
    add(s[r]);
    while (true) {
      if (kind <= n) break;
      erase(s[l]);
      l++;
    }
    ans = max(ans, r - l + 1);
  }
  cout << ans;
  return 0;
}