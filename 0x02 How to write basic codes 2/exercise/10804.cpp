#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> cards(20);
  for (int i = 1; i <= 20; ++i)
    cards[i - 1] = i;
  for (int i = 0; i < 10; ++i)
  {
    int start, end;
    cin >> start >> end;
    // reverse(i,j) => i ~ j-1까지 뒤집기에 포함
    reverse(cards.begin() + (start - 1), cards.begin() + end);
  }
  for (int i : cards)
    cout << i << ' ';
  return 0;
}