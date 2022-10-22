#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<int> cookie;

bool possible(int len) {
  int cnt = 0;
  for (int i : cookie) cnt += i / len;
  return cnt >= m;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> m >> n;
  for (int i = 0; i < n; ++i) {
    int len;
    cin >> len;
    cookie.push_back(len);
  }
  int st = 0, en = 1e9 + 1;
  while (st < en) {
    int mid = (st + en + 1) / 2;
    if (possible(mid))
      st = mid;
    else
      en = mid - 1;
  }
  cout << st;
  return 0;
}