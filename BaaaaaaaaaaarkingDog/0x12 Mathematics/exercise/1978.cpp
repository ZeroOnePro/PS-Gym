#include <bits/stdc++.h>

using namespace std;

bool check_prime(int n) {
  if (n == 1) return false;
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) return false;
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int cnt = 0, tmp;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    cnt += (check_prime(tmp) == true);
  }
  cout << cnt;
  return 0;
}