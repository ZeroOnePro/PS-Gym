#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  vector<int> divs;
  cin >> n;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      divs.push_back(i);
      if (i * i != n) divs.push_back(n / i);
    }
  }
  for (int div : divs) {
    cout << div << ' ';
  }
  return 0;
}