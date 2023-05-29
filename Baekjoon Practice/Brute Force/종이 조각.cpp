#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n, m;
  cin >> n >> m;
  vector<vector<int>> paper(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%1d", &paper[i][j]);
    }
  }

  // 해당 칸이 가로조각에 포함 상태 0, 해당 칸이 칸이 세로조각에 포함 1
  int ans = -1;
  for (int s = 0; s < (1 << m * n); ++s) {
    int sum = 0;
    // 가로종이조각에 칸에 포함
    for (int i = 0; i < n; ++i) {
      int cur = 0;
      for (int j = 0; j < m; ++j) {
        int k = i * m + j;
        if ((s & (1 << k)) == 0) {
          // k는 (i,j) 칸의 번호 row by row로 칸에 번호 매겼을 때
          cur = cur * 10 + paper[i][j];
          // 칸이 포함될때는 숫자를 생성
        } else {
          // 포함 안되면 그 조각은 끝난것이므로 총합에 더함
          sum += cur;
          cur = 0;
        }
      }
      // 한개의 행을 다하고 결과를 총합에 더함
      sum += cur;
    }
    // 세로종이조각에 칸에 포함
    for (int j = 0; j < m; ++j) {
      int cur = 0;
      for (int i = 0; i < n; ++i) {
        int k = i * m + j;
        if ((s & (1 << k)) != 0) {
          cur = cur * 10 + paper[i][j];
        } else {
          sum += cur;
          cur = 0;
        }
      }
      // 한개의 열을 다하고 결과를 총합에 더함
      sum += cur;
    }
    ans = max(sum, ans);
  }
  cout << ans << '\n';
  return 0;
}