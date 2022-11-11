#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = 5;
  vector<int> a(n);
  int b[n];
  priority_queue<int> pq;
  for (int i = 1; i <= n; ++i) pq.push(i);
  cout << sizeof(a) << ' ' << sizeof(b) << ' ' << sizeof(pq) << '\n';
  return 0;
}