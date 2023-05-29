#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string str;
  cin >> str;
  int length = 0;
  for (char ch : str) {
    length += 1;
  }
  cout << length << '\n';
  return 0;
}