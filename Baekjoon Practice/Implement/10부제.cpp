#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int day;
  vector<int> car_num(5, 0);
  cin >> day;
  for (int i = 0; i < 5; ++i) {
    cin >> car_num[i];
  }
  int cnt = 0;
  for (int c : car_num) {
    c == day ? cnt += 1 : cnt = cnt;
  }
  cout << cnt << '\n';
  return 0;
}