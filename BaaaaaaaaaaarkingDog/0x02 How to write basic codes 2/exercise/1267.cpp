#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  vector<int> calls;
  cin >> n;
  while (n--) {
    int call;
    cin >> call;
    calls.push_back(call);
  }
  int y = 0, m = 0;
  for (int call : calls) {
    y += ((call / 30) + 1) * 10;
    m += ((call / 60) + 1) * 15;
  }
  if (y > m)
    cout << 'M' << ' ' << m << '\n';
  else if (y < m)
    cout << 'Y' << ' ' << y << '\n';
  else
    cout << 'Y' << ' ' << 'M' << ' ' << y << '\n';
  return 0;
}