#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
ll mx;
vector<ll> bud;

bool possible(int x) {
  if (x > mx) return false;
  ll sum = 0;
  for (auto b : bud) sum += (b <= x ? b : x);
  return sum <= m;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  bud.resize(n);
  for (auto& pt : bud) cin >> pt;
  cin >> m;
  int st = 0, en = 1e9 + 5;
  sort(bud.begin(), bud.end());
  mx = bud[n - 1];
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