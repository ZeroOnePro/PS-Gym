#include <bits/stdc++.h>

using namespace std;

// 이 문제는 오름차순이라는 문제 조건이 맞는지 아닌지를 판단하면 가능여부를 판단할 수 있지만
// 정답 출력을 보면 실제로 시뮬레이션해야한다는 것을 알 수 있다.

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, cursor = 1;
  stack<int> s;
  string answer = "";
  cin >> n;
  while (n--)
  {
    int element;
    cin >> element;
    while (cursor <= element)
    {
      s.push(cursor++);
      answer += "+\n";
    }
    if (s.top() > element)
    {
      cout << "NO\n";
      return 0;
    }
    s.pop();
    answer += "-\n";
  }
  cout << answer;
  return 0;
}