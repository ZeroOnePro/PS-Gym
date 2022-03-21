#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  stack<int> s;
  int n;
  cin >> n;
  vector<int> received(n + 1);
  vector<bool> checked(n + 1);
  int index = n;
  for (int i = 0; i < n; ++i)
  {
    int height;
    cin >> height;
    s.push(height);
  }
  int current = s.top();
  s.pop();
  while (!s.empty())
  {
    // 신호 받을 수 있음
    if (s.top() >= current)
    {
      received[index] = index - 1;
      checked[index] = 1;
    }
    else
    {
      received[index] = current;
    }
    for (int i = index + 1; i <= n; ++i)
    {
      if (checked[i] == 0)
      {
        cout << i << ' ' << received[i] << ' ' << s.top() << '\n';
        if (received[i] <= s.top())
        {
          received[i] = index - 1;
        }
      }
    }
    // cout << received[index] << ' ' << checked[index] << ' ' << index << '\n';
    index -= 1;
    current = s.top();
    s.pop();
  }
  for (int i = 1; i <= n; ++i)
  {
    if (!checked[i])
    {
      cout << '0';
    }
    else
    {
      cout << received[i];
    }
    cout << ' ';
  }
  return 0;
}