#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int k;
    ll c, ans = 0;
    cin >> k;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    while (k--) {
      cin >> c;
      pq.push(c);
    }
    while (pq.size() > 1) {
      ll concat = 0;
      int iter = 2;
      while (iter--) {
        concat += pq.top();
        pq.pop();
      }
      ans += concat;
      pq.push(concat);
    }
    cout << ans << '\n';
  }
  return 0;
}