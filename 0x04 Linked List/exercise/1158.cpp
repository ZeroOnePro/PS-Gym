#include <bits/stdc++.h>

using namespace std;

list<int>::iterator ForCircularIterator(list<int> &l, list<int>::iterator &iter)
{
  return std::next(iter) == l.end() ? l.begin() : std::next(iter);
}

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
  for (auto cursor = find(seq.begin(), seq.end(), k);;)
  {
    if (*cursor != -1)
    {
      jose.push_back(*cursor);
      *cursor = -1;
      seqLen += 1;
      if (seqLen == n)
        break;
      for (int i = 0; i < k;)
      {
        cursor = ForCircularIterator(seq, cursor);
        if (*cursor != -1)
          i++;
      }
    }
  }
  cout << '<';
  for (auto it = jose.begin(); it != jose.end(); it++)
  {
    cout << *it;
    if (it != jose.end() - 1)
      cout << ", ";
  }
  cout << '>';
  return 0;
}