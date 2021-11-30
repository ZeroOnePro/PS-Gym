#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> originCounts(26, 0);
  vector<int> shuffledCounts(26, 0);
  while (n--)
  {
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
    string isPossibleCase = "Possible";
    for (int i = 0; i < 26; ++i)
    {
      if (originCounts[i] != shuffledCounts[i])
      {
        isPossibleCase = "Impossible";
      }
    }
    cout << isPossibleCase << '\n';
    fill(originCounts.begin(), originCounts.end(), 0);
    fill(shuffledCounts.begin(), shuffledCounts.end(), 0);
  }
  return 0;
}