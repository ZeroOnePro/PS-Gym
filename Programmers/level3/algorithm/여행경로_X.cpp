#include <bits/stdc++.h>

using namespace std;

vector<string> path;
bool is_used[10005];
bool check = false;

void dfs(string cur, int cnt, vector<vector<string>> tickets) {
  path.push_back(cur);
  if (cnt == tickets.size()) {
    check = true;
    return;
  }
  for (int i = 0; i < tickets.size(); i++) {
    if (is_used[i] || tickets[i][0] != cur) continue;
    is_used[i] = true;
    dfs(tickets[i][1], cnt + 1, tickets);
    if (!check) {
      path.pop_back();
      is_used[i] = false;
    }
  }
}

vector<string> solution(vector<vector<string>> tickets) {
  vector<string> answer;
  sort(tickets.begin(), tickets.end());
  dfs("ICN", 0, tickets);
  answer = path;
  return answer;
}