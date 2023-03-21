#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  long long tot = 0;
  stack<int> s;
  cin >> n;
  while (n--) {
    int t;
    cin >> t;
    while (!s.empty() && s.top() <= t) s.pop();
    tot += s.size();
    s.push(t);
  }
  cout << tot;
  return 0;
}