#include <bits/stdc++.h>

using namespace std;

// 그리디

string solution(string number, int k) {
  string answer = "";
  stack<int> s;
  for (char ch : number) {
    while (k > 0 && !s.empty() && s.top() < ch - '0') {
      s.pop();
      k -= 1;
    }
    if (s.size() < number.size() - k) s.push(ch - '0');
  }
  while (!s.empty()) {
    answer = to_string(s.top()) + answer;
    s.pop();
  }
  return answer;
}