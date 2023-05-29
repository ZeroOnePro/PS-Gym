#include <bits/stdc++.h>

using namespace std;

// 이거보다 제일 많이 나오는 원소가 제일 처음 배치되고, 그다음 많이나오는게 그
// 다음 배치 이런식으로 해서 한 풀이있는데 지리는듯

vector<int> solution(string s) {
  vector<int> answer;
  vector<string> v;
  vector<int> tups[505];
  int st = 0, mx = -1;
  for (int i = 1; i < s.length() - 1; ++i) {
    if (s[i] == '{') st = i + 1;
    if (s[i] == '}') v.push_back(s.substr(st, i - st));
  }
  for (auto tup : v) {
    int num;
    vector<int> tmp;
    string token;
    stringstream stream(tup);
    while (getline(stream, token, ',')) tmp.push_back(stoi(token));
    tups[tmp.size()] = tmp;
    mx = max(mx, (int)tmp.size());
  }
  for (int i = 1; i <= mx; ++i) {
    for (int i : tups[i]) {
      if (find(answer.begin(), answer.end(), i) != answer.end()) continue;
      answer.push_back(i);
    }
  }
  return answer;
}