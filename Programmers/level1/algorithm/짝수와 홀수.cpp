#include <string>
#include <vector>

using namespace std;

string solution(int num) {
  string answer = "";
  num % 2 == 0 ? answer = "Even" : answer = "Odd";
  return answer;
}
