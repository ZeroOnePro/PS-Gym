#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
  int answer = 0, tmp = 0;
  int n = (int)absolutes.size();
  for (int i = 0; i < n; ++i) {
    if (!signs[i])
      tmp = -1 * absolutes[i];
    else
      tmp = absolutes[i];
    answer += tmp;
  }
  return answer;
}