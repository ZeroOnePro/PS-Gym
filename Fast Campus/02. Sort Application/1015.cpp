#include <bits/stdc++.h>

using namespace std;

#define pi2 pair<int, int>

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pi2> a(n), b(n);
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    int elem;
    cin >> elem;
    b[i] = a[i] = {elem, i};
  }
  sort(b.begin(), b.end());
  for (int i = 0; i < n; ++i) p[b[i].second] = i;
  for (int i : p) cout << i << ' ';
  return 0;
}