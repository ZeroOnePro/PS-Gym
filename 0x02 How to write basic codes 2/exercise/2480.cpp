#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> dies(7);
  // 같은 거 3개라길래 3의 배수구나 싶었는데 예외가 있었어 글고 같은 거 2개 일때부터 안 통함
  // 뻔한 빈도수배열로 하자
  for (int i = 0; i < 3; ++i)
  {
    int input;
    cin >> input;
    dies[input] += 1;
  }
  int rule = 1;
  int die = 0;
  for (int i = 1; i < 7; ++i)
  {
    if (!dies[i])
      continue;
    if (dies[i] > 1)
    {
      rule = dies[i];
      die = i;
      break;
    }
    else
    {
      rule = 1;
      if (die < i)
        die = i;
    }
  }

  switch (rule)
  {
  case 1:
    cout << die * 1e2 << '\n';
    break;
  case 2:
    cout << 1e3 + die * 1e2 << '\n';
    break;
  case 3:
    cout << 1e4 + die * 1e3 << '\n';
    break;
  default:
    break;
  }

  return 0;
}