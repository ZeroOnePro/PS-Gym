#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int goodWord = 0;
  // top과 다르면 pop x
  // top과 같으면 없애버리자
  int tc;
  cin >> tc;
  while (tc--)
  {
    string word;
    cin >> word;
    stack<char> s;
    for (char ch : word)
    {
      if (s.empty())
        s.push(ch);
      else
      {
        if (s.top() == ch)
          s.pop();
        else
          s.push(ch);
      }
    }
    if (s.empty())
      goodWord += 1;
  }
  cout << goodWord << '\n';
  return 0;
}