#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int time = 0;
  int input;
  for (int i = 0; i < 4; ++i) {
    cin >> input;
    time += input;
  }
  int minute = time / 60;
  int second = time - minute * 60;
  cout << minute << '\n' << second << '\n';
  return 0;
}