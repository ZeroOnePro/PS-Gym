#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc = 3;
  while (tc--)
  {
    string game;
    getline(cin, game);
    int frontCnt = 0;
    for (char ch : game)
    {
      if (ch != '0')
        continue;
      else
        frontCnt += 1;
    }
    switch (frontCnt)
    {
    case 0:
      cout << 'E' << '\n';
      break;
    case 1:
      cout << 'A' << '\n';
      break;
    case 2:
      cout << 'B' << '\n';
      break;
    case 3:
      cout << 'C' << '\n';
      break;
    case 4:
      cout << 'D' << '\n';
      break;
    default:
      break;
    }
  }
  return 0;
}