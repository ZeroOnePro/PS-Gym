#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= 2 * n - 1; ++i)
  {
    if (n >= i)
    {
      for (int j = 1; j <= i; ++j)
      {
        cout << '*';
      }
    }
    else
    {
      for (int j = 2 * n - 1; j >= i; --j)
      {
        cout << '*';
      }
    }
    for (int k = 2 * abs(n - i); k > 0; --k)
    {
      cout << ' ';
    }
    if (n >= i)
    {
      for (int j = 1; j <= i; ++j)
      {
        cout << '*';
      }
    }
    else
    {
      for (int j = 2 * n - 1; j >= i; --j)
      {
        cout << '*';
      }
    }
    cout << '\n';
  }
  return 0;
}