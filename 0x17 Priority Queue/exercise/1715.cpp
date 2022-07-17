#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, card;
  priority_queue<int, vector<int>, greater<int>> pq;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> card;
    pq.push(card);
  }
  int ans = 0;
  while (pq.size() > 1) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    ans += a + b;
    pq.push(a + b);
  }
  cout << ans << '\n';
  return 0;
}