#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = 7;
  int sum = 0, minimum = 100;
  while (n--)
  {
    int input;
    cin >> input;
    if (input & 1)
    {
      if (minimum > input)
        minimum = input;
      sum += input;
    }
  }
  if (!sum)
    cout << -1 << '\n';
  else
    cout << sum << '\n'
         << minimum << '\n';
  return 0;
}