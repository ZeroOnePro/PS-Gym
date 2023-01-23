#include <bits/stdc++.h>

using namespace std;

int freq[10001];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    int in;
    cin >> in;
    mx = max(mx, in);
    freq[in] += 1;
  }
  for (int i = 1; i <= mx; ++i)
    while (freq[i]--) cout << i << '\n';

  return 0;
}