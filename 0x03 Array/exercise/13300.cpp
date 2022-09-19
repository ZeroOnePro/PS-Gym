#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<vector<int> > students(2, vector<int>(6, 0));
  int room = 0;
  while (n--) {
    int s, y;
    cin >> s >> y;
    students[s][y - 1] += 1;
  }
  for (int row = 0; row < 2; ++row) {
    for (int col = 0; col < 6; ++col) {
      if (students[row][col]) {
        room += students[row][col] / k;
        if (students[row][col] % k) room += 1;
      }
    }
  }
  cout << room << '\n';
  return 0;
}