#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, cur = 1;
  stack<int> s;
  string ans = "";
  cin >> n;
  while (n--) {
    int e;
    cin >> e;
    while (cur <= e) {
      s.push(cur++);
      ans += "+\n";
    }
    if (s.top() > e) {
      cout << "NO\n";
      return 0;
    }
    ans += "-\n";
    s.pop();
  }
  cout << ans;
  return 0;
}