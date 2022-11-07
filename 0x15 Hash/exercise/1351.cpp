#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, p, q;
unordered_map<ll, ll> dp;

ll create_seq(ll cur) {
  if (cur == 0) return 1;
  if (dp[cur])
    return dp[cur];
  else
    dp[cur] = create_seq(floor(cur / p)) + create_seq(floor(cur / q));
  return dp[cur];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> p >> q;
  dp[0] = 1;
  if (n != 0) create_seq(n);
  cout << dp[n];
  return 0;
}