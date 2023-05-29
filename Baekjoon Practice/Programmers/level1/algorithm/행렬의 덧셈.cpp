#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1,
                             vector<vector<int>> arr2) {
  int row = arr1.size();
  int col = arr1[0].size();
  vector<vector<int>> answer(row, vector<int>(col, 0));
  cout << row << col << '\n';
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      answer[i][j] = arr1[i][j] + arr2[i][j];
    }
  }
  return answer;
}