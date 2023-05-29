#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool compare(string a, string b) { return a < b; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string str;
  cin >> str;

  string substr[1005];

  int length = str.length();

  for (int i = 0; i <= length; ++i) {
    substr[i] = str.substr(i, length);
  }

  sort(substr, substr + length, compare);

  for (int i = 0; i <= length; ++i) {
    cout << substr[i] << '\n';
  }

  return 0;
}