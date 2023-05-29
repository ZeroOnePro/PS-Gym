#include <iostream>
#include <vector>

using namespace std;

int station[4][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 2; ++j) {
      cin >> station[i][j];
    }
  }
  int max_num = station[0][1] - station[0][0];
  int tmp = max_num;
  for (int i = 1; i < 4; ++i) {
    tmp += station[i][1] - station[i][0];
    if (tmp > max_num)
      max_num = tmp;
  }
  cout << max_num << '\n';
  return 0;
}