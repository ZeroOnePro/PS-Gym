#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
  int answer = n;
  answer -= lost.size();
  sort(lost.begin(), lost.end());
  sort(reserve.begin(), reserve.end());
  for (int i = 0; i < lost.size(); i++) {
    for (int j = 0; j < reserve.size(); j++) {
      if (lost[i] == reserve[j]) {
        lost[i] = -1;
        reserve[j] = -1;
        answer += 1;
      }
    }
  }
  for (int i = 0; i < lost.size(); i++) {
    for (int j = 0; j < reserve.size(); j++) {
      if (lost[i] == reserve[j] - 1 || lost[i] == reserve[j] + 1) {
        answer++;
        reserve[j] = -1;
        break;
      }
    }
  }
  return answer;
}