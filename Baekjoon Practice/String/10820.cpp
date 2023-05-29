#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string str;
  while (getline(cin, str)) {
    int upper = 0;
    int lower = 0;
    int space = 0;
    int number = 0;

    for (char ch : str) {
      if (ch >= 'a' && ch <= 'z') {
        lower += 1;
      } else if (ch >= 'A' && ch <= 'Z') {
        upper += 1;
      } else if (ch >= '0' && ch <= '9') {
        number += 1;
      } else if (ch == ' ') {
        space += 1;
      }
    }
    cout << lower << ' ' << upper << ' ' << number << ' ' << space << '\n';
  }
  return 0;
}