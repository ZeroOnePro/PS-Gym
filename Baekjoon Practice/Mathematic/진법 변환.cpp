#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string str;
  double b;
  cin >> str >> b;

  double n = str.length() - 1;
  double ans = 0;
  double s = pow(b, n);

  for (char ch : str) {
    // ch * b^(str±æÀÌ-1) + ....
    if (ch >= '0' && ch <= '9') {
      ans += (ch - '0') * s;
    } else if (ch >= 'A' && ch <= 'Z') {
      ans += (ch - 55) * s;
    }
    s /= b;
  }

  cout << fixed << setprecision(0) << ans << '\n';

  return 0;
}