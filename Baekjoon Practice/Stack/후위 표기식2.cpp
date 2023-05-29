#include <iomanip>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;

  string postfix;
  cin >> postfix;

  stack<double> s;
  vector<int> operand(26);
  for (int i = 0; i < n; ++i) {
    cin >> operand[i];
  }

  for (char ch : postfix) {

    if (ch >= 'A' && ch <= 'Z') {
      // ¾ËÆÄºª¿¡ ¼ýÀÚ ´ëÀÀ½ÃÅ°´Â ÀÎµ¦½Ì
      s.push((double)operand[ch - 'A']);
    } else {
      double op2 = s.top();
      s.pop();
      double op1 = s.top();
      s.pop();

      if (ch == '*') {
        s.push(op1 * op2);
      } else if (ch == '/') {
        s.push(op1 / op2);
      } else if (ch == '+') {
        s.push(op1 + op2);
      } else if (ch == '-') {
        s.push(op1 - op2);
      }
    }
  }

  cout << fixed << setprecision(2) << s.top() << '\n';

  return 0;
}