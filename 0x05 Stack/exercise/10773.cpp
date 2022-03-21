#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  stack<int> s;
  int sum = 0;
  int k;
  cin >> k;
  while (k--)
  {
    int money;
    cin >> money;
    if (money)
    {
      s.push(money);
    }
    else
    {
      s.pop();
    }
  }
  while (!s.empty())
  {
    sum += s.top();
    s.pop();
  }
  cout << sum << '\n';
  return 0;
}