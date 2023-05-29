#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<string, int> transBinary(string bits) {
  string removed = "", convert = "";
  int cnt = 0;

  for (char b : bits) {
    if (b == '0') {
      cnt += 1;
      continue;
    }
    removed += b;
  }

  int len = removed.length();

  while (len != 0) {
    convert += to_string(len % 2);
    len /= 2;
  }

  reverse(convert.begin(), convert.end());

  return {convert, cnt};
}

vector<int> solution(string s) {
  vector<int> answer;
  string trans = s;
  int transCount = 0, removedZeros = 0;
  while (trans != "1") {
    transCount += 1;
    removedZeros += transBinary(trans).second;
    trans = transBinary(trans).first;
  }
  answer.push_back(transCount);
  answer.push_back(removedZeros);
  return answer;
}