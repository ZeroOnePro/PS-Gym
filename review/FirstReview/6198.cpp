#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  stack<int> s;
  int n, cnt = 0;
  cin >> n;
  while (n--)
  {
    int tower;
    cin >> tower;
    while (!s.empty() && s.top() <= tower)
      s.pop();
    cnt += s.size();
    s.push(tower);
  }
  cout << cnt << '\n';
  return 0;
}