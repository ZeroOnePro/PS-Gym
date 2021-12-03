#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n;
  vector<int> seq(1e6 + 1);
  vector<int> freq(1e6 + 1);
  for (int i = 0; i < n; ++i)
  {
    cin >> seq[i];
    freq[seq[i]] += 1;
  }
  cin >> x;
  int cnt = 0;
  for (int elem : seq)
  {
    if (!elem)
      continue;
    if (x > elem && freq[x - elem])
      cnt += 1;
  }
  cout << cnt / 2 << '\n';
  return 0;
}