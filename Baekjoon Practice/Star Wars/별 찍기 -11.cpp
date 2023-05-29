#include <iostream>
using namespace std;

char p[3072][6144];
void starfractal(int n, int x, int y);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  // 배열 초기화 *좌표공간만들기*
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * n; j++) // 높이
    {
      if (j == 2 * n - 1)
        p[i][j] = NULL;
      else
        p[i][j] = ' ';
    }
  }

  starfractal(n, n - 1, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * n - 1; j++) {
      cout << p[i][j];
    }
    cout << '\n';
  }
  return 0;
}

void starfractal(int n, int x, int y) {
  if (n == 3) {
    p[y][x] = '*';         // 기준점
    p[y + 1][x - 1] = '*'; // 한줄 내려와 좌로 한칸 (x-1)
    p[y + 1][x + 1] = '*'; // 한줄 내려와 우로 한칸 (x+1)
    p[y + 2][x - 2] = '*'; //  두줄 내려와 좌로 두칸
    p[y + 2][x - 1] = '*'; // 두줄 내려와 좌로 한칸
    p[y + 2][x] = '*';     // 두줄 내려와 그대로
    p[y + 2][x + 1] = '*'; // 두줄 내려와 우로 한칸
    p[y + 2][x + 2] = '*'; // 두줄 내려와 우로 두칸
    return; // 반복구조라 재귀로 구현하는데 더이상 자기자신 호출하지말라고
  }
  starfractal(n / 2, x, y);
  starfractal(n / 2, x - (n / 2), y + (n / 2));
  starfractal(n / 2, x + (n / 2), y + (n / 2));
}