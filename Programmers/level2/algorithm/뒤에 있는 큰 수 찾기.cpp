#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) {
  vector<int> answer(numbers.size());
  stack<pair<int, int>> s;
  for (int i = 0; i < numbers.size(); ++i) {
    while (!s.empty() && s.top().first < numbers[i]) {
      answer[s.top().second] = numbers[i];
      s.pop();
    }
    s.push({numbers[i], i});
  }
  while (!s.empty()) {
    answer[s.top().second] = -1;
    s.pop();
  }
  return answer;
}