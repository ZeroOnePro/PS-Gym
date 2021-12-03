#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  while (n--)
  {
    string input;
    cin >> input;
    list<char> password;
    list<char>::iterator cursor = password.begin();
    for (char ch : input)
    {
      if (ch == '<')
      {
        if (cursor != password.begin())
          cursor--;
      }
      else if (ch == '>')
      {
        if (cursor != password.end())
          cursor++;
      }
      else if (ch == '-')
      {
        if (cursor != password.begin())
        {
          cursor--;
          cursor = password.erase(cursor);
        }
      }
      else
      {
        password.insert(cursor, ch);
      }
    }
    for (auto ch : password)
    {
      cout << ch;
    }
    cout << '\n';
  }
  return 0;
}