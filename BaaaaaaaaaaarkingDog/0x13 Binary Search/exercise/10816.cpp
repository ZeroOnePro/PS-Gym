#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> card(20000002, 0);
  int n, m;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int elem;
    cin >> elem;
    card[10000000 + elem]++;
  }
  cin >> m;
  while (m--) {
    int elem;
    cin >> elem;
    cout << card[10000000 + elem] << ' ';
  }
  return 0;
}