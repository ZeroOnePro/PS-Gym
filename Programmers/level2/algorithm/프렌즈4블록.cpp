#include <bits/stdc++.h>

using namespace std;

const int range = 35;

string b[range];

bool rm[range][range];

int dx[] = {0, 0, 1, 1};
int dy[] = {0, 1, 0, 1};

int check(int m, int n) {
  int rm_block = 0;
  for (int i = 0; i <= m - 2; ++i)
    for (int j = 0; j <= n - 2; ++j) {
      char block = b[i][j];
      if (block == ' ') continue;
      int cnt = 0;
      for (int dir = 1; dir < 4; ++dir)
        if (block == b[i + dx[dir]][j + dy[dir]]) cnt += 1;
      if (cnt == 3)
        for (int dir = 0; dir < 4; ++dir)
          if (!rm[i + dx[dir]][j + dy[dir]]) {
            rm[i + dx[dir]][j + dy[dir]] = true;
            rm_block += 1;
          }
    }
  return rm_block;
}

void down(int m, int n) {
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      if (rm[i][j]) b[i][j] = ' ';
  for (int j = 0; j < n; ++j)
    for (int i = m - 1; i >= 0; --i)
      if (b[i][j] == ' ')
        for (int k = i - 1; k >= 0; --k)
          if (b[k][j] != ' ') {
            swap(b[i][j], b[k][j]);
            break;
          }
}

void print(int m, int n) {
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) cout << b[i][j] << ' ';
    cout << '\n';
  }
}

int solution(int m, int n, vector<string> board) {
  int answer = 0;
  for (int i = 0; i < m; ++i) b[i] = board[i];
  while (true) {
    int rm_block = check(m, n);
    if (rm_block == 0) break;
    down(m, n);
    for (int i = 0; i < m; ++i) fill(rm[i], rm[i] + n, false);
    answer += rm_block;
  }
  return answer;
}