#include <bits/stdc++.h>

using namespace std;

int isEmpty(queue<int> &Q)
{
  if (Q.empty())
  {
    return -1;
  }
  return 0;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  queue<int> q;
  while (n--)
  {
    string command;
    cin >> command;
    if (command == "push")
    {
      int element;
      cin >> element;
      q.push(element);
      continue;
    }
    else if (command == "front")
    {
      int result = isEmpty(q) == -1 ? -1 : q.front();
      cout << result;
    }
    else if (command == "back")
    {
      int result = isEmpty(q) == -1 ? -1 : q.back();
      cout << result;
    }
    else if (command == "size")
    {
      cout << q.size();
    }
    else if (command == "empty")
    {
      int result = isEmpty(q) == -1; // 자동형 변환인가
      cout << result;
    }
    else
    {
      int result = isEmpty(q) == -1 ? -1 : q.front();
      if (!q.empty())
      {
        q.pop();
      }
      cout << result;
    }
    cout << '\n';
  }
  return 0;
}