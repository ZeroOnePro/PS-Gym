#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  long long answer = 0;
  stack<pair<int, int>> s;
  cin >> n;
  while (n--)
  {
    int height, cnt = 1;
    cin >> height;
    while (!s.empty() && s.top().first <= height)
    {
      if (s.top().first == height)
        cnt += s.top().second;
      answer += s.top().second;
      s.pop();
    }
    if (!s.empty() && s.top().first > height)
      answer++;
    s.push({height, cnt});
  }
  cout << answer << '\n';
  return 0;
}