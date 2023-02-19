#include <bits/stdc++.h>

using namespace std;

const int range = 1005;

int r, c;
vector<string> a(range), b(range);

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> r >> c;
  for (int i = 0; i < r; ++i) cin >> a[i];
  for (int i = 0; i < c; ++i) {
    string s = "";
    for (int j = 0; j < r; ++j) s += a[j][i];
    b[i] = s;
  }
  // 해시를 사용해서 중복되는게 없는지 본다
  int cur = 0, count = 0;
  while (true) {
    unordered_map<string, int> cnt;  // (문자열, 빈도수)
    bool stop = false;
    for (int i = 0; i < c; ++i) cnt[b[i].substr(cur + 1)] += 1;
    for (auto [s, freq] : cnt)
      if (freq > 1) stop = true;
    if (stop) break;
    cur += 1;
    count += 1;
  }
  cout << count;
  return 0;
}