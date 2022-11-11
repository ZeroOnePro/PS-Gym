#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  priority_queue<int> pq;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int in;
    cin >> in;
    pq.push(in);
    queue<int> q;
    int mid = pq.size() / 2;
    while (mid--) {
      q.push(pq.top());
      pq.pop();
    }
    cout << pq.top() << '\n';
    while (!q.empty()) {
      pq.push(q.front());
      q.pop();
    }
  }
  return 0;
}