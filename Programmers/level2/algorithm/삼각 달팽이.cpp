#include <bits/stdc++.h>

using namespace std;

int mx[1005];
int tri[1005][1005];

vector<int> solution(int n) {
  vector<int> answer;
  mx[1] = 1;
  for (int i = 2; i <= n; ++i) mx[i] = mx[i - 1] + i;
  int x = -1, y = 0, cnt = 1;
  int side = n;
  while (cnt <= mx[n]) {
    for (int i = 0; i < side; ++i) tri[++x][y] = cnt++;
    for (int i = 0; i < side - 1; ++i) tri[x][++y] = cnt++;
    for (int i = 0; i < side - 2; ++i) tri[--x][--y] = cnt++;
    side -= 3;
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= i; ++j) answer.push_back(tri[i][j]);
  return answer;
}