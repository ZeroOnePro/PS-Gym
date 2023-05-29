#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
  vector<long long> answer;
  answer.push_back(x);
  int d = x;
  while (n--) {
    answer.push_back(x += d);
  }
  answer.pop_back();
  return answer;
}