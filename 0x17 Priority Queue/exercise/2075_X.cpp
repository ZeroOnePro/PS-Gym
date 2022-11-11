#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n * n; ++i) {
    int in;
    cin >> in;
    pq.push(in);
    if (pq.size() > n) pq.pop();
  }
  cout << pq.top();
  return 0;
}