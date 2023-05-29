#include <bits/stdc++.h>

using namespace std;

// 처음에 2차원 벡터 call by value로 해서 시간초과 났었음
// 변경하는게 아니기 때문에 call by reference로 하는게 훨 효율적, 아니면
// 전역으로 따로 선언해서 복사하던가

vector<int> cnt(2);

bool check(int x, int y, int n, vector<vector<int>>& arr) {
  for (int i = x; i < x + n; ++i)
    for (int j = y; j < y + n; ++j)
      if (arr[x][y] != arr[i][j]) return false;
  return true;
}

void divide(int x, int y, int n, vector<vector<int>>& arr) {
  // 더이상 분할할 필요 없을 때
  if (check(x, y, n, arr)) {
    cnt[arr[x][y]] += 1;
    return;
  }
  // 더이상 분할 못할 때
  if (n == 1) {
    cnt[arr[x][y]] += 1;
    return;
  }
  int nxt = n / 2;
  // 1사분면
  divide(x, y, nxt, arr);
  // 2사분면
  divide(x, y + nxt, nxt, arr);
  // 3사분면
  divide(x + nxt, y, nxt, arr);
  // 4사분면
  divide(x + nxt, y + nxt, nxt, arr);
}

vector<int> solution(vector<vector<int>> arr) {
  vector<int> answer;
  int n = arr.size();
  divide(0, 0, n, arr);
  answer = cnt;
  return answer;
}