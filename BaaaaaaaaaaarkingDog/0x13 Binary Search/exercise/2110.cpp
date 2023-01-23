#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, c;
  cin >> n >> c;
  vector<int> h(n);
  for (auto& pt : h) cin >> pt;
  sort(h.begin(), h.end());
  int st = 0, en = 1e9;
  while (st < en) {
    int mid = (st + en + 1) / 2;
    int p = 0;
    int cur = 0;
    while (cur < n) {
      int lb = lower_bound(h.begin(), h.end(), h[cur] + mid) - h.begin();
      if (lb < n && h[lb] - h[cur] >= mid) p += 1;
      cur = lb;
    }
    if (p >= c - 1)
      st = mid;
    else
      en = mid - 1;
  }
  cout << st;
  return 0;
}