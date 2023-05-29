#include <iostream>

using namespace std;

char p[6562][6562];
void Star(int n, int x, int y);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == n)
        p[i][j] = '\0';
      else
        p[i][j] = ' ';
    }
  }

  Star(n, (n - 1) / 2, (n - 1) / 2);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << p[i][j];
    }
    cout << '\n';
  }

  return 0;
}

void Star(int n, int x, int y) {
  if (n == 3) {
    p[y - 1][x - 1] = '*';
    p[y - 1][x] = '*';
    p[y - 1][x + 1] = '*';
    p[y][x - 1] = '*';
    p[y][x + 1] = '*';
    p[y + 1][x - 1] = '*';
    p[y + 1][x] = '*';
    p[y + 1][x + 1] = '*';
    return;
  }

  Star(n / 3, x - (n / 3), y - (n / 3)); // 1
  Star(n / 3, x, y - (n / 3));
  Star(n / 3, x + (n / 3), y - (n / 3));
  Star(n / 3, x - (n / 3), y); // 4
  Star(n / 3, x + (n / 3), y);
  Star(n / 3, x - (n / 3), y + (n / 3)); // 7
  Star(n / 3, x, y + (n / 3));
  Star(n / 3, x + (n / 3), y + (n / 3));
}