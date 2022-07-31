#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<int> s;
  int cur = 1;
  string ans;
  while (n--) {
    int elem;
    cin >> elem;
    while (cur <= elem) {
      s.push(cur++);
      ans += "+\n";
    }
    if (s.top() != elem) {
      cout << "NO\n";
      return 0;
    }
    s.pop();
    ans += "-\n";
  }
  cout << ans;
  return 0;
}