#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  stack<pair<int, int>> s;
  vector<int> NGE(n);
  for (int i = 0; i < n; ++i)
  {
    int element;
    cin >> element;
    while (!s.empty() && s.top().first < element)
    {
      NGE[s.top().second] = element;
      s.pop();
    }
    s.push({element, i});
  }
  while (!s.empty())
  {
    NGE[s.top().second] = -1;
    s.pop();
  }
  for (int i = 0; i < n; ++i)
  {
    cout << NGE[i] << ' ';
  }
  return 0;
}