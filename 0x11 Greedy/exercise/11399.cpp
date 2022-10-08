#include <bits/stdc++.h>

using namespace std;

vector<int> t;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, sum = 0, ans = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int in;
    cin >> in;
    t.push_back(in);
  }
  sort(t.begin(), t.end());
  for (int i : t) {
    sum = i + sum;
    ans += sum;
  }
  cout << ans;
  return 0;
}