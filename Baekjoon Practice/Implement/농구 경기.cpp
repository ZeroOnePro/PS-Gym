#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  string input;
  vector<char> first_name(26, 0);
  for (int i = 0; i < n; ++i) {
    cin >> input;
    first_name[input[0] - 'a'] += 1;
  }
  string ans = "";
  for (int i = 0; i < 26; ++i) {
    if (first_name[i] >= 5) {
      ans += i + 'a';
    }
  }
  ans == "" ? cout << "PREDAJA\n" : cout << ans << '\n';
  return 0;
}