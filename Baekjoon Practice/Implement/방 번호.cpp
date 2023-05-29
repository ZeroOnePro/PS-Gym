#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string room_num;
  cin >> room_num;
  vector<int> numbers(10, 0);
  for (char ch : room_num) {
    if (ch - '0' == 6 || ch - '0' == 9) {
      if (numbers[6] <= numbers[9])
        numbers[6] += 1;
      else
        numbers[9] += 1;
    } else {
      numbers[ch - '0'] += 1;
    }
  }
  int ans = *max_element(numbers.begin(), numbers.end());
  cout << ans << '\n';
  return 0;
}