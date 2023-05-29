#include <bits/stdc++.h>

using namespace std;

// substring 써서 같은지 비교하자

// 문자열을 같은 크기로 자르는 기능
// 각 chunk들이 같은지 확인하는 기능

int solution(string s) {
  int answer = s.length();
  string ans = "";
  for (int chunk = 1; chunk <= s.length() / 2; ++chunk) {
    int cnt = 1;
    string pattern = s.substr(0, chunk);
    int i = chunk;
    for (; i <= s.length(); i += chunk) {
      string tmp = s.substr(i, chunk);
      if (pattern == tmp)
        cnt += 1;
      else {
        ans += cnt <= 1 ? pattern : to_string(cnt) + pattern;
        pattern = tmp;
        cnt = 1;
      }
    }
    if (s.length() % chunk != 0) {
      int offset = (s.length() / chunk) * chunk;
      ans += s.substr(offset, s.length() - offset);
    }
    if (answer > ans.length()) answer = ans.length();
    ans = "";
  }
  return answer;
}