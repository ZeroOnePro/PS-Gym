#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<string> words(n);
  for (auto& w : words) cin >> w;
  sort(words.begin(), words.end(), [&words](auto a, auto b) {
    if (a.length() == b.length()) {
      int sum[2] = {0, 0};
      int len = a.length();
      for (int i = 0; i < len; ++i) {
        if (isdigit(a[i])) sum[0] += (a[i] - '0');
        if (isdigit(b[i])) sum[1] += (b[i] - '0');
      }
      if (sum[0] != sum[1]) return sum[0] < sum[1];
      return a < b;
    }
    return a.length() < b.length();
  });
  for (string word : words) cout << word << '\n';
  return 0;
}