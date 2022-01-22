#include <bits/stdc++.h>

using namespace std;

// 이 문제는 오름차순이라는 문제 조건이 맞는지 아닌지를 판단하면 가능여부를 판단할 수 있지만 이 문제의 출력형식에 주의해야한다.
// 정답 출력을 보면 실제로 시뮬레이션해야한다는 것을 알 수 있다.
// 시뮬레이션 중 중간 과정이 어디까지 진행됐는지 확인하는 cursor변수를 둔다.
// 입력되는 수열은 pop되는 순서이므로 이를 그대로 모방한다.
// 입력 값보다 수열의 top이 크면, 입력 값이 오름차순으로 들어오지 않음을 의미한다.(즉, 스택에 내림차순으로 쌓였다.)
// 이런 경우는 불가능한 케이스이다.

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