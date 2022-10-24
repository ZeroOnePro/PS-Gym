#include <bits/stdc++.h>

using namespace std;

int abs(int x) {
  x = x < 0 ? x * -1 : x;
  return x;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  vector<int> sol;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int in;
    cin >> in;
    sol.push_back(in);
  }
  int ans1 = 1e9 + 5;
  int ans2 = ans1;
  for (int i = 0; i < n; i++) {
    int idx = lower_bound(sol.begin(), sol.end(), -sol[i]) - sol.begin();
    int mn = ans1 + ans2;
    if (idx + 1 < n && i != idx + 1 && abs(sol[i] + sol[idx + 1]) < abs(mn)) {
      ans1 = sol[i];
      ans2 = sol[idx + 1];
    }
    if (idx < n && i != idx && abs(sol[i] + sol[idx]) < abs(mn)) {
      ans1 = sol[i];
      ans2 = sol[idx];
    }
    if (idx != 0 && i != idx - 1 && abs(sol[i] + sol[idx - 1]) < abs(mn)) {
      ans1 = sol[i];
      ans2 = sol[idx - 1];
    }
  }
  if (ans1 > ans2) swap(ans1, ans2);
  cout << ans1 << ' ' << ans2;
  return 0;
}