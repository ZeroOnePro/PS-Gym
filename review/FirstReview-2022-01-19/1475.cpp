#include <bits/stdc++.h>

using namespace std;

void adjust(int &a, int &b)
{
  int diff = (int)abs(a - b) / 2;
  if (a > b)
  {
    a -= diff;
    b += diff;
  }
  else
  {
    a += diff;
    b -= diff;
  }
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> digits(10, 0);
  string roomNumber;
  cin >> roomNumber;
  for (char ch : roomNumber)
    digits[ch - '0'] += 1;
  adjust(digits[6], digits[9]);
  cout << *max_element(digits.begin(), digits.end()) << '\n';
  return 0;
}