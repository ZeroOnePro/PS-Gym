#include <iostream>
#include <string>
using namespace std;

bool solution(string s) {
  bool answer = true;
  int cnt1 = 0;
  int cnt2 = 0;
  for (int i = 0; i < s.size(); i++) {
    s[i] = tolower(s[i]);
    if (s[i] == 'p') {
      cnt1 += 1;
    }
    if (s[i] == 'y') {
      cnt2 += 1;
    }
  }
  cnt1 == cnt2 ? answer : answer = false;
  return answer;
}