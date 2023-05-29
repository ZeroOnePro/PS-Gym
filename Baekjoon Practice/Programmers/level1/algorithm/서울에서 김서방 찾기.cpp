#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(vector<string> seoul) {
  string answer = "";
  answer = "김서방은 ";
  int index = 0;
  for (string str : seoul) {
    if (str == "Kim") {
      break;
    }
    index += 1;
  }
  answer += to_string(index);
  answer += "에 있다";
  return answer;
}