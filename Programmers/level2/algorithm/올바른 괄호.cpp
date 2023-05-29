#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

bool solution(string s) {
  fastio;

  bool answer = true;

  stack<char> st;

  for (char ch : s) {
    if (ch == '(')
      st.push(ch);
    else {
      if (st.empty() || st.top() != '(') answer = false;
      st.pop();
    }
  }

  if (!st.empty()) answer = false;

  return answer;
}