#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
  long long answer = 0;
  priority_queue<int> pq;
  for (int w : works) pq.push(w);
  for (int i = 0; i < n; ++i) {
    int w = pq.top();
    pq.pop();
    if (w - 1 > 0)
      pq.push(w - 1);
    else
      pq.push(0);
  }
  while (!pq.empty()) {
    answer += pq.top() * pq.top();
    pq.pop();
  }
  return answer;
}