#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  priority_queue<int> pq;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int in;
    cin >> in;
    if (in == 0) {
      if (pq.empty())
        cout << 0 << '\n';
      else {
        cout << pq.top() << '\n';
        pq.pop();
      }
    } else
      pq.push(in);
  }
  return 0;
}