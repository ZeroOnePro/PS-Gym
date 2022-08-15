#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  stack<char> s;
  cin >> str;
  // 올바르지 않은 거에 대한 말이 없는거 보니 올바른 것만 주어지는 듯?
  int bar = 0;
  int index = 0;
  for (char ch : str)
  {
    if (ch == '(')
      s.push(ch);
    else if (ch == ')')
    {
      s.pop();
      if (str[index - 1] == '(') // 인접 쌍 처리 = 레이저, 잘리는 라인 왼쪽 갯수만 센다
        bar += s.size();
      else // 인접 하지 않은 막대기들 빠질 때 잔여 갯수, 레이저 라인 기준으로 왼쪽 것들은 레이저에서 이미 카운트했기 때문에 1개만 더해주면 됨(제일 오른쪽 것)
        bar += 1;
    }
    index += 1;
  }
  cout << bar << '\n';
  return 0;
}