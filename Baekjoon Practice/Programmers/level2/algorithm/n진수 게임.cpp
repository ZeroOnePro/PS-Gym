#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string make_b_base(int number, int b) {
  string result = "";
  if (number == 0) return "0";
  stack<string> s;
  while (number != 0) {
    int r = number % b;
    string digit = "";
    r >= 10 ? digit = (char)('A' + (r - 10)) : digit = to_string(r);
    s.push(digit);
    number /= b;
  }
  while (!s.empty()) {
    result += s.top();
    s.pop();
  }
  return result;
}

string solution(int n, int t, int m, int p) {
  string answer = "";
  string tmp = "";
  for (int i = 0; tmp.size() < m * t; ++i) {
    tmp += make_b_base(i, n);
  }
  answer = tmp[p - 1];
  for (int i = m; answer.size() != t; i += m) {
    answer += tmp[p - 1 + i];
  }
  return answer;
}