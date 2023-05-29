#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> order) {
  int answer = 0, cur = 1;
  stack<int> s;
  for (int i = 0; i < order.size(); ++i) {
    while (cur <= order[i]) s.push(cur++);
    if (s.top() > order[i]) break;
    answer += 1;
    s.pop();
  }
  return answer;
}
