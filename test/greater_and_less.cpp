#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // a > b면 true
  cout << greater<int>().operator()(3, 2) << '\n';

  // a < b면 true
  cout << less<int>().operator()(2, 3) << '\n';
  return 0;
}