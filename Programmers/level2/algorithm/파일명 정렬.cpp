#include <bits/stdc++.h>

using namespace std;

vector<string> parse(string str) {
  transform(str.begin(), str.end(), str.begin(), ::tolower);
  vector<string> tokens;
  bool is_first = true;
  int st, en;
  // 문자열을 세 부분으로 나누기
  // head: 처음 숫자 등장 이전 / number: 숫자 등장 이후 숫자 이외 문자 나올
  // 때까지 / tail: 이후 나머지
  for (int i = 0; i < str.length(); i++)
    if (isdigit(str[i]) && is_first) {
      st = i;
      is_first = false;
      int j = i;
      while (isdigit(str[j])) j++;
      en = j;
      break;
    }
  tokens.push_back(str.substr(0, st));
  tokens.push_back(str.substr(st, en - st));
  tokens.push_back(str.substr(en));
  return tokens;
}

vector<string> solution(vector<string> files) {
  vector<string> answer;
  stable_sort(files.begin(), files.end(), [](string a, string b) {
    vector<string> a_tokens = parse(a);
    vector<string> b_tokens = parse(b);
    if (a_tokens[0] == b_tokens[0]) {
      if (stoi(a_tokens[1]) == stoi(b_tokens[1])) return false;
      return stoi(a_tokens[1]) < stoi(b_tokens[1]);
    }
    return a_tokens[0] < b_tokens[0];
  });
  answer = files;
  return answer;
}