#include <bits/stdc++.h>

using namespace std;

long long reverse_number(long long n) {
  queue<int> q;
  int digit = -1;
  long long reversed = 0;
  while (n != 0) {
    int d = n % 10;
    q.push(d);
    n /= 10;
    digit += 1;
  }
  while (!q.empty()) {
    long long mul = 1;
    for (int i = 0; i < digit; ++i) mul *= 10;
    digit -= 1;
    reversed += q.front() * mul;
    q.pop();
  }
  return reversed;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> v(n);
  for (auto& e : v) cin >> e;
  for (auto& e : v) e = reverse_number(e);
  sort(v.begin(), v.end());
  for (auto e : v) cout << e << '\n';
  return 0;
}