#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> ti3;

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

string solution(int n, int k, vector<string> cmd) {
  string answer = "";
  // (원소, 이전 원소, 다음 원소)
  // 첫 행의 이전 원소(-1)와 마지막 행의 다음 원소(n)는 nullptr
  vector<ti3> table;
  stack<ti3> rm;
  for (int i = 0; i < n; ++i) table.push_back({i, i - 1, i + 1});
  int cursor = k;
  for (string op : cmd) {
    vector<string> token = parse(op, " ");
    if (token[0] == "U" || token[0] == "D") {
      int mv = stoi(token[1]);
      while (mv--) {
        auto [elem, prev, nxt] = table[cursor];
        cursor = token[0] == "U" ? prev : nxt;
      }
    } else if (token[0] == "C") {
      auto [elem, prev, nxt] = table[cursor];
      rm.push(table[cursor]);
      // 1. 첫 행이 삭제되는 경우
      if (prev == -1) {
        get<1>(table[nxt]) = -1;
        cursor = nxt;
      }
      // 2. 마지막 행이 삭제되는 경우
      else if (nxt == n) {
        get<2>(table[prev]) = n;
        cursor = prev;
      }
      // 3. 그 외
      else {
        get<2>(table[prev]) = nxt;
        get<1>(table[nxt]) = prev;
        cursor = nxt;
      }
    } else {
      auto [elem, prev, nxt] = rm.top();
      rm.pop();
      // 1. 첫 행이 복구
      if (prev == -1) get<1>(table[nxt]) = elem;
      // 2. 마지막 행이 복구
      else if (nxt == n)
        get<2>(table[prev]) = elem;
      // 3. 그 외
      else {
        get<2>(table[prev]) = elem;
        get<1>(table[nxt]) = elem;
      }
    }
  }
  unordered_map<int, bool> um;
  while (!rm.empty()) {
    um[get<0>(rm.top())] = true;
    rm.pop();
  }
  for (int i = 0; i < n; ++i) {
    if (um.find(i) != um.end())
      answer += "X";
    else
      answer += "O";
  }
  return answer;
}