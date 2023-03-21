#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<int, int> pi2;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  stack<pi2> s;
  vector<int> nge(n);
  for (int i = 0; i < n; ++i) {
    int e;
    cin >> e;
    while (!s.empty() && s.top().x < e) {
      nge[s.top().y] = e;
      s.pop();
    }
    s.push({e, i});
  }
  while (!s.empty()) {
    nge[s.top().y] = -1;
    s.pop();
  }
  for (auto e : nge) cout << e << ' ';
  return 0;
}