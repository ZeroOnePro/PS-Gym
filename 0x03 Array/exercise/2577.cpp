#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b, c;
  vector<int> feq(10);
  cin >> a >> b >> c;
  int multi = a * b * c;
  while (multi > 0)
  {
    feq[multi % 10] += 1;
    multi /= 10;
  }
  for (int cnt : feq)
    cout << cnt << '\n';
  return 0;
}