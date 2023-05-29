#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int solution(string s) {
  fastio;

  int answer = -1;

  stack<char> st;

  for (char ch : s) {
    if (st.empty())
      st.push(ch);
    else {
      if (st.top() == ch)
        st.pop();
      else
        st.push(ch);
    }
  }

  if (!st.empty())
    answer = 0;
  else
    answer = 1;

  return answer;
}