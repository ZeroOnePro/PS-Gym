#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<bool> stu(31, false);
  int input;
  for (int i = 1; i <= 30; ++i) {
    cin >> input;
    stu[input] = true;
  }
  int num = 1;
  for_each(stu.begin() + 1, stu.end(), [&](bool i) {
    if (i != true) {
      cout << num << '\n';
      num += 1;
    } else {
      num += 1;
    }
  });
  return 0;
}