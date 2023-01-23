#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, d, k, c;
  cin >> n >> d >> k >> c;
  vector<int> sushi(n);
  vector<int> is_used(d + 1);
  for (auto& pt : sushi) cin >> pt;
  for (int i = 0; i < k; ++i) sushi.push_back(sushi[i]);
  int en = 0, mx = 0, uniq = 0;
  for (int st = 0; st < n; ++st) {
    while (en < n + k - 1 && en - st < k) {
      if (is_used[sushi[en]] == 0) uniq += 1;
      is_used[sushi[en]] += 1;
      en += 1;
    }
    if (is_used[c] == 0) uniq += 1;
    mx = max(uniq, mx);
    if (is_used[c] == 0) uniq -= 1;
    is_used[sushi[st]] -= 1;
    if (is_used[sushi[st]] == 0) uniq -= 1;
  }
  cout << mx;
  return 0;
}