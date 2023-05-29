#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(vector<int> numbers) {
  string answer = "";
  // 최고자리를 비교한다.
  // 같다면 뒷자리를 비교한다.
  // 30과 3이런 경우는 자릿수가 적은것이 우선이다.
  vector<string> snumbers;
  bool flag = false;
  int s = numbers.size();
  int cnt = 0;
  for (int i : numbers) {
    if (i == 0) {
      cnt += 1;
    }
    snumbers.push_back(to_string(i));
  }
  if (cnt == s) return "0";
  sort(snumbers.begin(), snumbers.end(), [&](string a, string b) {
    return a + b > b + a;  // 기본은 사전순 정렬
  });
  for (string s : snumbers) {
    answer += s;
  }
  return answer;
}