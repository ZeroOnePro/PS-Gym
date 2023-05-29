#include <algorithm>
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
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  // 수열 전체에 대해 m으로 나눴을 때 나머지가 모두 같다면,
  // v[i] - v[i-1] = m * (몫[i] - 몫[i-1])이 성립해야한다.
  // 임의의 m에 대해서
  // v[i] - v[i-1] / (몫[i] - 몫[i-1]) = m이 성립하려면
  // (몫[i] - 몫[i-1]) * m == m의 배수
  // (몫[i] - 몫[i - 1]) 이것의 최대값을 찾아 => 최대공약수
  // 이 값의 약수를 모두 구해주면 된다.
  sort(v.begin(), v.end());

  ll g = v[1] - v[0];
  for (int i = 2; i < n; ++i) {
    g = GCD(g, v[i] - v[i - 1]);
  }
  vector<ll> ans;
  // g = i * g/i 이므로 i와 g/i는 g의 약수
  for (int i = 2; i * i <= g; ++i) {
    if (g % i == 0) {
      ans.push_back(i);
      ans.push_back(g / i);
    }
  }
  ans.push_back(g);
  sort(ans.begin(), ans.end());
  // 중복 제거 STL
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  for (ll i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
  return 0;
}