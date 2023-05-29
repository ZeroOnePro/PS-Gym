#include <bits/stdc++.h>

using namespace std;

int solution(string t, string p) {
  int answer = 0;
  // p의 길이 최대 18이라 int 초과될 수 있음
  for (int i = 0; i <= t.length() - p.length(); ++i)
    if (stoll(p) >= stoll(t.substr(i, p.length()))) answer += 1;
  return answer;
}