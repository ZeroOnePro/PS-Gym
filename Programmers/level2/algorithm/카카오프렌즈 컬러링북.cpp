#include <stdio.h>

#include <iostream>
#include <vector>
using namespace std;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int area;
bool visited[100][100];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

void bfs(int start_num, int x, int y, int size_x, int size_y,
         vector<vector<int>> picture) {
  int next_x, next_y;

  visited[x][y] = true;
  area++;

  for (int i = 0; i < 4; i++) {
    next_x = x + dx[i];
    next_y = y + dy[i];
    if (next_x < 0 || next_x > size_x - 1 || next_y < 0 ||
        next_y > size_y - 1) {
      continue;
    } else if (!visited[next_x][next_y] &&
               picture[next_x][next_y] == start_num) {
      bfs(start_num, next_x, next_y, size_x, size_y, picture);
    }
  }
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
  int max = 0;
  int number_of_area = 0;
  int max_size_of_one_area = 0;
  int zone = 0;
  vector<int> answer(2);
  answer[0] = number_of_area;
  answer[1] = max_size_of_one_area;

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      visited[i][j] = false;
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j] && picture[i][j] != 0) {
        area = 0;
        bfs(picture[i][j], i, j, m, n, picture);

        if (max < area) max = area;
        zone++;
      }
    }
  }
  answer[0] = zone;
  answer[1] = max;

  return answer;
}