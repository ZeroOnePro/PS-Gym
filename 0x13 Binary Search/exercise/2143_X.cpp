#include <bits/stdc++.h>

using namespace std;

void sub_sum(vector<int>& v, vector<int>& res) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    int sum = v[i];
    res.push_back(sum);
    for (int j = i + 1; j < len; ++j) {
      sum += v[j];
      res.push_back(sum);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, n, m;
  cin >> t >> n;
  vector<int> a(n);
  for (auto& pt : a) cin >> pt;
  cin >> m;
  vector<int> b(m);
  for (auto& pt : b) cin >> pt;
  vector<int> a_sum, b_sum;
  sub_sum(a, a_sum);
  sub_sum(b, b_sum);
  sort(b_sum.begin(), b_sum.end());
  long long ans = 0;
  for (int sub : a_sum) {
    int target = t - sub;
    ans += upper_bound(b_sum.begin(), b_sum.end(), target) -
           lower_bound(b_sum.begin(), b_sum.end(), target);
  }
  cout << ans;
  return 0;
}