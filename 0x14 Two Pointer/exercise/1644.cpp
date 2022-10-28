#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> prime;
vector<bool> state;

void create_prime() {
  state.resize(n + 1, true);
  for (int i = 2; i * i <= n; ++i) {
    if (!state[i]) continue;
    for (int j = i * i; j <= n; j += i) state[j] = false;
  }
  for (int i = 2; i <= n; ++i)
    if (state[i]) prime.push_back(i);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  create_prime();
  int en = 0, sum = 0, ans = 0, len = prime.size();
  for (int st = 0; st < len; ++st) {
    while (en < len && sum + prime[en] <= n) {
      sum += prime[en];
      en += 1;
    }
    if (sum == n) ans += 1;
    sum -= prime[st];
  }
  cout << ans;
  return 0;
}