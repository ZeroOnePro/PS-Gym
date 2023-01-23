#include <bits/stdc++.h>

using namespace std;

int abs(int x) { return x < 0 ? -x : x; }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, mn = 1e9 * 2 + 5;
  cin >> n;
  vector<int> sol(n);
  for (auto& s : sol) cin >> s;
  for (int i = 0; i < n; ++i) {
    int idx = lower_bound(sol.begin(), sol.end(), -sol[i]) - sol.begin();
    /**
     * 최소는 idx - 1, idx, idx + 1 중 하나
     */
    for (int nxt : {idx - 1, idx, idx + 1})
      if (nxt >= 0 && nxt < n && nxt != i && abs(sol[i] + sol[nxt]) < abs(mn))
        mn = sol[i] + sol[nxt];
  }
  cout << mn;
  return 0;
}