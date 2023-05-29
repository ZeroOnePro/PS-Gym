#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string input;
  string ans = "";
  cin >> input;
  for (char ch : input) {
    isupper(ch) ? ans += ch : ans = ans;
  }
  cout << ans << '\n';
  return 0;
}