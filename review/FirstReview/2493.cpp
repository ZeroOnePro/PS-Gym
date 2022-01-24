#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  stack<pair<int, int>> s;
  s.push({1e7, 0});
  for (int i = 1; i <= n; ++i)
  {
    int tower;
    cin >> tower;
    while (!s.empty() && s.top().first < tower)
      s.pop();
    cout << s.top().second << ' ';
    s.push({tower, i});
  }

  return 0;
}

/* 반례 */

/*

n이 6일 때,,,

4 9 6 3 7 8
0 0 2 3 2 2

4 9 6 3 7 8
0 0 2 3 2 2

4 9 7 3 6 8
0 0 2 3 3 2

9 7 4 3 6 8
0 1 2 3 2 1

7 4 9 3 6 8
0 1 0 3 3 3

9 4 6 3 7 8
0 1 1 3 1 1

5 4 6 9 8 7
0 1 0 0 4 5

*/

// 부분 타워 구간을 고려하지 않은 풀이
// stack<int> answer;
// while (!s.empty())
// {
//   int current = s.top();
//   int cnt = 0;
//   while (!s.empty() && s.top() <= current)
//   {
//     cnt += 1;
//     s.pop();
//   }
//   while (cnt--)
//   {
//     answer.push(s.size());
//   }
// }
// while (!answer.empty())
// {
//   cout << answer.top() << ' ';
//   answer.pop();
// }