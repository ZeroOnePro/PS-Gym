#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  list<int> seq;
  vector<int> jose;
  for (int i = 1; i <= n; ++i)
    seq.push_back(i);
  int seqLen = 0;
  for (auto cursor = find(seq.begin(), seq.end(), k); seqLen != n;)
  {
    if (*cursor != -1)
    {
      jose.push_back(*cursor);
      int term = 0;
      cout << *seq.end() << '\n';
      *cursor = -1;
      while (1)
      {
        cursor++;
        if (*cursor != -1)
        {
          term += 1;
          if (term == k)
            break;
        }
        if (cursor == seq.end())
        {
          cursor = seq.begin();
        }
      }
      seqLen += 1;
    }
  }
  for (auto i : jose)
  {
    cout << i << ' ';
  }
  return 0;
}