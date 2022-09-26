#include <bits/stdc++.h>

using namespace std;

bool is_delimeter(char c) {
  string delimeters = "{},[] ";

  for (size_t i = 0; i < delimeters.size(); ++i)
    if (c == delimeters[i]) return true;

  return false;
}

/**
 * @brief parse string
 *
 * 시간복잡도
 * 문자열 길이 N, 구분자 길이 M이라 할 때 O(NM)
 *
 * @return vector<string>
 */
vector<string> parse(string s) {
  vector<string> tokens;
  string token = "";
  for (char ch : s) {
    if (is_delimeter(ch)) {
      if (token != "") tokens.push_back(token);
      token = "";
      continue;
    }
    token += ch;
  }
  return tokens;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string in = "{[12,2,3], [4,5,6], [7,8,9]}";
  vector<string> tokens = parse(in);
  for (auto token : tokens) cout << token << ' ';
  return 0;
}