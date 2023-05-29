#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
  string answer = "";
  int cnt = phone_number.size();
  for (char ch : phone_number) {
    cnt > 4 ? answer += "*" : answer += ch;
    cnt -= 1;
  }
  return answer;
}