#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1,
                             vector<vector<int>> arr2) {
  int numOfRow = arr1.size();
  int numOfCol = arr2[0].size();
  int numOfCur = arr1[0].size();
  vector<vector<int>> answer(numOfRow, vector<int>(numOfCol, 0));
  int subSum = 0;
  for (int row = 0; row < numOfRow; ++row) {
    for (int col = 0; col < numOfCol; ++col) {
      for (int cur = 0; cur < numOfCur; ++cur) {
        subSum += arr1[row][cur] * arr2[cur][col];
      }
      answer[row][col] = subSum;
      subSum = 0;
    }
  }
  return answer;
}