#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> a(n), b(n), c(n), d(n), sum_ab, sum_cd;
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i] >> d[i];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      sum_ab.push_back(a[i] + b[j]);
      sum_cd.push_back(c[i] + d[j]);
    }
  ll ans = 0;
  sort(sum_ab.begin(), sum_ab.end());
  sort(sum_cd.begin(), sum_cd.end());
  for (int i = 0; i < n * n; ++i) {
    int ub =
        upper_bound(sum_ab.begin(), sum_ab.end(), -sum_cd[i]) - sum_ab.begin();
    int lb =
        lower_bound(sum_ab.begin(), sum_ab.end(), -sum_cd[i]) - sum_ab.begin();
    ans += ub - lb;
  }
  cout << ans;
  return 0;
}