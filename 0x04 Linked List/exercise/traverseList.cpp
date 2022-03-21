#include <bits/stdc++.h>

using namespace std;

list<int>::iterator circularNext(list<int> &lis, list<int>::iterator &iter)
{
  return std::next(iter) == lis.end() ? lis.begin() : std::next(iter);
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  list<int> seq;
  for (int i = 1; i <= 6; ++i)
    seq.push_back(i);

  int size = 0;

  for (auto it = seq.begin();; it = circularNext(seq, it))
  {
    size += 1;
    if (size > 12)
      break;
    cout << *it << ' ';
  }
  return 0;
}