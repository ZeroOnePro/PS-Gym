#include <bits/stdc++.h>

using namespace std;

vector<string> parse(string origin, string delimiter) {
  vector<string> token;
  size_t pos = 0;
  while ((pos = origin.find(delimiter)) != string::npos) {
    token.push_back(origin.substr(0, pos));
    origin.erase(0, pos + delimiter.length());
  }
  token.push_back(origin);
  return token;
}

vector<int> solution(vector<string> operations) {
  vector<int> answer;
  set<int> s;

  for (string op : operations) {
    vector<string> v = parse(op, " ");
    string command = v[0];
    int x = stoi(v[1]);
    if (command == "I")
      s.insert(x);
    else {
      if (s.empty()) continue;
      if (x == 1)
        s.erase(prev(s.end()));
      else
        s.erase(s.begin());
    }
  }
  if (s.empty())
    answer = {0, 0};
  else
    answer = {*s.rbegin(), *s.begin()};
  return answer;
}