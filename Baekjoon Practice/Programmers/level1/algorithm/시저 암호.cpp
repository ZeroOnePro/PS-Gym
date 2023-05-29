#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {
  string answer = "";
  for (char ch : s) {
    if (ch == ' ')
      answer += ' ';
    else {
      if (ch >= 'a' && ch <= 'z') {
        if (ch + n <= 'z') {
          answer += char(ch + n);
        } else {
          int offset = ch + n - 'z' - 1;
          answer += char(offset + 'a');
        }
      } else {
        if (ch + n <= 'Z') {
          answer += char(ch + n);
        } else {
          int offset = ch + n - 'Z' - 1;
          answer += char(offset + 'A');
        }
      }
    }
  }
  return answer;
}