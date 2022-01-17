#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  stack<char> s;
  cin >> str;
  int index = 0, sum = 0, multiplier = 1;
  bool isCorrect = true;
  for (char ch : str)
  {
    if (ch == '(' || ch == '[')
    {
      multiplier *= (ch == '(' ? 2 : 3);
      s.push(ch);
    }
    else if (ch == ')' || ch == ']')
    {
      if (s.empty() || (ch == ']' && s.top() != '[') || (ch == ')' && s.top() != '('))
      {
        isCorrect = false;
        break;
      }
      else
      {
        if (str.at(index - 1) == '[' || str.at(index - 1) == '(')
          sum += multiplier;
        multiplier /= (ch == ')' ? 2 : 3);
        s.pop();
      }
    }
    index += 1;
  }
  if (!s.empty())
    isCorrect = false;
  cout << (isCorrect ? sum : 0) << '\n';
  return 0;
}