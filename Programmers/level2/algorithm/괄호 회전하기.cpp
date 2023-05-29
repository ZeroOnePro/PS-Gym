#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void rotate(vector<string>& rotated, string s) {
  int len = s.length();
  for (int i = 0; i < len; i++) {
    string first = s.substr(0, 1);
    string sub = s.substr(1, len - 1);
    s = sub + first;
    rotated.push_back(s);
  }
}

int solution(string s) {
  int answer = 0;
  stack<char> st;
  vector<string> rotated;
  rotate(rotated, s);
  for (string str : rotated) {
    bool is_correct = true;
    for (char ch : str) {
      if (ch == '[' || ch == '(' || ch == '{') {
        st.push(ch);
      } else if (ch == ']') {
        if (st.top() == '[') {
          st.pop();
        } else {
          is_correct = false;
          break;
        }
      } else if (ch == ')') {
        if (st.top() == '(') {
          st.pop();
        } else {
          is_correct = false;
          break;
        }
      } else {
        if (st.top() == '{') {
          st.pop();
        } else {
          is_correct = false;
          break;
        }
      }
    }
    if (st.empty() && is_correct) answer += 1;
  }
  return answer;
}