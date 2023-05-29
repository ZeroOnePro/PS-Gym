#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string msg) {
  vector<int> answer;
  unordered_map<string, int> dict;
  for (int i = 1; i <= 26; ++i) {
    string s = "";
    s += 'A' + i - 1;
    dict[s] = i;
  }
  int index = 27;
  for (int i = 0; i < msg.size();) {
    int len = 2;
    while (len < msg.size() && dict.find(msg.substr(i, len)) != dict.end())
      len += 1;
    // s[i...len-1] 까지는 사전에 있음
    answer.push_back(dict[msg.substr(i, len - 1)]);
    dict[msg.substr(i, len)] = index++;
    i += len - 1;
  }
  return answer;
}