#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
  int answer = 0;
  if (s[0] == '-') {
    answer = atoi(s.substr(1).c_str());
    int tmp = 2 * answer;
    answer -= tmp;
  } else {
    answer = atoi(s.c_str());
  }
  return answer;
}