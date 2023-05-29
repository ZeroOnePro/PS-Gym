#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
  vector<int> answer;
  int i = 0;
  int j = 0;
  while (j < arr.size()) {
    if (arr[i] != arr[j]) {
      answer.push_back(arr[i]);
      i = j;
    } else {
      j++;
    }
  }
  answer.push_back(arr[i]);

  return answer;
}