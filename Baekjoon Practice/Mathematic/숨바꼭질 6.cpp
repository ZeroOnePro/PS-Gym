#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll GCD(ll a, ll b) {
  while (b != 0) {
    ll r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  ll s;
  cin >> n >> s;
  vector<ll> v(n + 1);
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    ll diff = abs(a - s);
    v[i] = diff;
  }
  ll d = GCD(v[0], v[1]);
  for (int i = 2; i < n; ++i) {
    d = GCD(d, v[i]);
  }
  cout << d << '\n';
  return 0;
}