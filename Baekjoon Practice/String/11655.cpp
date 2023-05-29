#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string str;
  string ans;
  getline(cin, str);
  for (char ch : str) {
    if (ch >= 'a' && ch <= 'z') {
      if (ch + 13 > 'z') {
        ans += (ch + 13) - 'z' + 'a' - 1;
      } else {
        ans += (ch + 13);
      }
    } else if (ch >= 'A' && ch <= 'Z') {
      if (ch + 13 > 'Z') {
        ans += (ch + 13) - 'Z' + 'A' - 1;
      } else {
        ans += (ch + 13);
      }
    } else {
      ans += ch;
    }
  }
  cout << ans << '\n';
  return 0;
}