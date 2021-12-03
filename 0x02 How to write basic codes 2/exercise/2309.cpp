#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> midgets(9);
  vector<int> checked = {0, 0, 0, 0, 0, 0, 0, 1, 1};
  for (int i = 0; i < 9; ++i)
    cin >> midgets[i];
  int sum = 0;
  // 9개 중 7개를 뽑는 순열
  do
  {
    sum = 0;
    for (int i = 0; i < 9; ++i)
    {
      if (!checked[i])
      {
        sum += midgets[i];
      }
    }
    if (sum == 100)
      break;
  } while (next_permutation(checked.begin(), checked.end()));

  for (int i = 0; i < 9; ++i)
  {
    if (checked[i])
      midgets[i] = 0;
  }

  sort(midgets.begin(), midgets.end());

  for (int i = 2; i < (int)midgets.size(); ++i)
  {
    cout << midgets[i] << '\n';
  }

  return 0;
}