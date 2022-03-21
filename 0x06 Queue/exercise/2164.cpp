#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<int> cards;
  int n;
  cin >> n;
  // 수학적 해답이 있을거 같은 느낌이 드는데?
  for (int i = 1; i <= n; ++i)
    cards.push(i);

  while (cards.size() > 1)
  {
    cards.pop();
    int top = cards.front();
    cards.push(top);
    cards.pop();
  }
  cout << cards.front() << '\n';
  return 0;
}