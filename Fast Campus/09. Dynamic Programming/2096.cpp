#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  int mx[3] = {0, 0, 0};
  int mn[3] = {0, 0, 0};
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    if (i == 0) {
      mn[0] = mx[0] = a;
      mn[1] = mx[1] = b;
      mn[2] = mx[2] = c;
    } else {
      int pre_mx[3] = {mx[0], mx[1], mx[2]};
      int pre_mn[3] = {mn[0], mn[1], mn[2]};
      mx[0] = max(pre_mx[0], pre_mx[1]) + a;
      mx[1] = max({pre_mx[0], pre_mx[1], pre_mx[2]}) + b;
      mx[2] = max(pre_mx[1], pre_mx[2]) + c;
      mn[0] = min(pre_mn[0], pre_mn[1]) + a;
      mn[1] = min({pre_mn[0], pre_mn[1], pre_mn[2]}) + b;
      mn[2] = min(pre_mn[1], pre_mn[2]) + c;
    }
  }
  cout << max({mx[0], mx[1], mx[2]}) << ' ' << min({mn[0], mn[1], mn[2]});
  return 0;
}