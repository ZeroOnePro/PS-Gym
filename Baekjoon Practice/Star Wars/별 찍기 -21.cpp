#include <iostream>

using namespace std;

char star[2][105];

int main() {
  int n;
  cin >> n;
  int toggle_row = 0;
  for (int i = 0; i < n; ++i) {
    star[toggle_row][i] = '*';
    star[1 - toggle_row][i] = ' ';
    toggle_row = 1 - toggle_row;
  }
  int loop = n;
  while (loop--) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << star[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}