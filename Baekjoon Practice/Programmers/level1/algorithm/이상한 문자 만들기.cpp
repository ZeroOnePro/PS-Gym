#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";
  int index = 0;
  for (char ch : s) {
    if (ch == ' ') {
      answer += ' ';
      index = 0;
    } else {
      if (index % 2 == 0) {
        answer += toupper(ch);
      } else {
        answer += tolower(ch);
      }
      index += 1;
    }
  }
  return answer;
}