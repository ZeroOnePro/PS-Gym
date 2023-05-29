#include <iostream>

using namespace std;
int board[500][500];

int block[19][3][2] = {
    {{0, 1}, {0, 2}, {0, 3}},   {{1, 0}, {2, 0}, {3, 0}},
    {{1, 0}, {1, 1}, {1, 2}},   {{0, 1}, {1, 0}, {2, 0}},
    {{0, 1}, {0, 2}, {1, 2}},   {{1, 0}, {2, 0}, {2, -1}},
    {{0, 1}, {0, 2}, {-1, 2}},  {{1, 0}, {2, 0}, {2, 1}},
    {{0, 1}, {0, 2}, {1, 0}},   {{0, 1}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 0}, {1, 1}},   {{0, 1}, {-1, 1}, {-1, 2}},
    {{1, 0}, {1, 1}, {2, 1}},   {{0, 1}, {1, 1}, {1, 2}},
    {{1, 0}, {1, -1}, {2, -1}}, {{0, 1}, {0, 2}, {-1, 1}},
    {{0, 1}, {0, 2}, {1, 1}},   {{1, 0}, {2, 0}, {1, 1}},
    {{1, 0}, {2, 0}, {1, -1}},
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> board[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < 19; ++k) {
        int sum = board[i][j];
        for (int l = 0; l < 3; ++l) {
          int x = i + block[k][l][0];
          int y = j + block[k][l][1];
          if (0 <= x && x < n && 0 <= y && y < m) {
            sum += board[x][y];
          } else {
            break;
          }
        }
        if (ans < sum) {
          ans = sum;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}