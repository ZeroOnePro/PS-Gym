#include <iostream>
#include <vector>

using namespace std;

int arithmeticOperation(int x, int y, char op)
{
  int result = 0;
  switch (op)
  {
  case '+':
    result = x + y;
    break;
  case '-':
    result = x - y;
    break;
  case '*':
    result = x * y;
    break;
  case '/':
    result = x / y;
    break;
  case '%':
    result = x % y;
    break;
  default:
    break;
  }
  return result;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b;
  cin >> a >> b;
  vector<char> ops = {'+', '-', '*', '/', '%'};
  for (char op : ops)
  {
    cout << arithmeticOperation(a, b, op) << '\n';
  }
  return 0;
}