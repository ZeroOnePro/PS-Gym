#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  // 공백 줄어들었다가 다시 늘어나니 절댓값으로 ㄱ?
  for (int i = 1; i <= 2 * n - 1; ++i)
  {
    for (int j = abs(n - i); j > 0; --j)
      cout << ' ';
    if (n >= i)
    {
      for (int k = 1; k <= 2 * i - 1; ++k)
      {
        cout << '*';
      }
    }
    else
    {
      for (int k = 2 * n - 1; k >= 2 * (i - n) + 1; --k)
      {
        cout << '*';
      }
    }
    cout << '\n';
  }
  return 0;
}