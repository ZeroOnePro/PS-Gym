#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> originCounts(26, 0);
  vector<int> shuffledCounts(26, 0);
  string origin, shuffled;
  cin >> origin >> shuffled;
  for (int i = 0; i < (int)origin.size(); ++i)
  {
    originCounts[origin[i] - 'a'] += 1;
  }
  for (int i = 0; i < (int)shuffled.size(); ++i)
  {
    shuffledCounts[shuffled[i] - 'a'] += 1;
  }
  int cnt = 0;
  for (int i = 0; i < 26; ++i)
  {
    if (originCounts[i] != shuffledCounts[i])
    {
      if (originCounts[i] != 0 && shuffledCounts[i] != 0)
      {
        if (originCounts[i] > shuffledCounts[i])
          cnt += originCounts[i] - shuffledCounts[i];
        else
          cnt += shuffledCounts[i] - originCounts[i];
      }
      else
      {
        cnt += originCounts[i];
        cnt += shuffledCounts[i];
      }
    }
  }
  cout << cnt << '\n';
  return 0;
}